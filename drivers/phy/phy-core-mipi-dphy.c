/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2013 NVIDIA Corporation
 * Copyright (C) 2018 Cadence Design Systems Inc.
 */

#include <common.h>
#include <div64.h>

#include <generic-phy.h>
#include <phy-mipi-dphy.h>
#include <linux/errno.h>
#include <mipi_dsi.h>
#include <linux/compat.h>

#define PSEC_PER_SEC	1000000000000LL

unsigned long long phy_mipi_dphy_get_hs_clk(unsigned long pixel_clock,
	unsigned int bpp, unsigned int lanes, unsigned long dsi_mode_flags,
	unsigned int min_hs_clock_multiple, unsigned int mipi_dsi_multiple)
{
	unsigned long long hs_clk_rate = pixel_clock;

	debug("%s: pixel_clock=%ld, bpp=%d, lanes=%d, dsi_mode_flags=0x%lx,"
		"min_hs_clock_multiple=%d, mipi_dsi_multiple=%d\n", __func__,
		pixel_clock, bpp, lanes, dsi_mode_flags,
		min_hs_clock_multiple, mipi_dsi_multiple);
	if (dsi_mode_flags & MIPI_DSI_MODE_VIDEO_MBC) {
		unsigned n = (bpp + (lanes * 8) - 1) / (lanes * 8);

		hs_clk_rate *= n * 8;
	} else {
		hs_clk_rate *= bpp;
		do_div(hs_clk_rate, lanes);
	}
	if (min_hs_clock_multiple) {
		unsigned long long bit_clkm = pixel_clock;

		bit_clkm *= min_hs_clock_multiple;
		if (hs_clk_rate < bit_clkm)
			hs_clk_rate = bit_clkm;
	}
	if (mipi_dsi_multiple) {
		hs_clk_rate += mipi_dsi_multiple - 1;
		do_div(hs_clk_rate, mipi_dsi_multiple);

		hs_clk_rate *= mipi_dsi_multiple;
	}
	return hs_clk_rate;
}

/*
 * Minimum D-PHY timings based on MIPI D-PHY specification. Derived
 * from the valid ranges specified in Section 6.9, Table 14, Page 41
 * of the D-PHY specification (v2.1).
 */
int phy_mipi_dphy_get_default_config(unsigned long pixel_clock,
				     unsigned int bpp,
				     unsigned int lanes,
				     struct phy_configure_opts_mipi_dphy *cfg,
				     unsigned long dsi_mode_flags,
				     unsigned int min_hs_clock_multiple,
				     unsigned int mipi_dsi_multiple)
{
	unsigned long long hs_clk_rate;
	unsigned long long ui;

	if (!cfg)
		return -EINVAL;

	hs_clk_rate = phy_mipi_dphy_get_hs_clk(pixel_clock, bpp, lanes,
			dsi_mode_flags, min_hs_clock_multiple, mipi_dsi_multiple);

	ui = ALIGN(PSEC_PER_SEC, hs_clk_rate);
	do_div(ui, hs_clk_rate);

	cfg->clk_miss = 0;
	cfg->clk_post = 60000 + 52 * ui;
	cfg->clk_pre = 8;
	cfg->clk_prepare = 38000;
	cfg->clk_settle = 95000;
	cfg->clk_term_en = 0;
	cfg->clk_trail = 60000;
	cfg->clk_zero = 262000;
	cfg->d_term_en = 0;
	cfg->eot = 0;
	cfg->hs_exit = 100000;
	cfg->hs_prepare = 40000 + 4 * ui;
	cfg->hs_zero = 105000 + 6 * ui;
	cfg->hs_settle = 85000 + 6 * ui;
	cfg->hs_skip = 40000;

	/*
	 * The MIPI D-PHY specification (Section 6.9, v1.2, Table 14, Page 40)
	 * contains this formula as:
	 *
	 *     T_HS-TRAIL = max(n * 8 * ui, 60 + n * 4 * ui)
	 *
	 * where n = 1 for forward-direction HS mode and n = 4 for reverse-
	 * direction HS mode. There's only one setting and this function does
	 * not parameterize on anything other that ui, so this code will
	 * assumes that reverse-direction HS mode is supported and uses n = 4.
	 */
	cfg->hs_trail = max(4 * 8 * ui, 60000 + 4 * 4 * ui);

	cfg->init = 100;
	cfg->lpx = 60000;
	cfg->ta_get = 5 * cfg->lpx;
	cfg->ta_go = 4 * cfg->lpx;
	cfg->ta_sure = 2 * cfg->lpx;
	cfg->wakeup = 1000;

	cfg->hs_clk_rate = hs_clk_rate;
	cfg->lanes = lanes;

	return 0;
}

/*
 * Validate D-PHY configuration according to MIPI D-PHY specification
 * (v1.2, Section Section 6.9 "Global Operation Timing Parameters").
 */
int phy_mipi_dphy_config_validate(struct phy_configure_opts_mipi_dphy *cfg)
{
	unsigned long long ui;

	if (!cfg)
		return -EINVAL;

	ui = ALIGN(PSEC_PER_SEC, cfg->hs_clk_rate);
	do_div(ui, cfg->hs_clk_rate);

	if (cfg->clk_miss > 60000)
		return -EINVAL;

	if (cfg->clk_post < (60000 + 52 * ui))
		return -EINVAL;

	if (cfg->clk_pre < 8)
		return -EINVAL;

	if (cfg->clk_prepare < 38000 || cfg->clk_prepare > 95000)
		return -EINVAL;

	if (cfg->clk_settle < 95000 || cfg->clk_settle > 300000)
		return -EINVAL;

	if (cfg->clk_term_en > 38000)
		return -EINVAL;

	if (cfg->clk_trail < 60000)
		return -EINVAL;

	if ((cfg->clk_prepare + cfg->clk_zero) < 300000)
		return -EINVAL;

	if (cfg->d_term_en > (35000 + 4 * ui))
		return -EINVAL;

	if (cfg->eot > (105000 + 12 * ui))
		return -EINVAL;

	if (cfg->hs_exit < 100000)
		return -EINVAL;

	if (cfg->hs_prepare < (40000 + 4 * ui) ||
	    cfg->hs_prepare > (85000 + 6 * ui))
		return -EINVAL;

	if ((cfg->hs_prepare + cfg->hs_zero) < (145000 + 10 * ui))
		return -EINVAL;

	if ((cfg->hs_settle < (85000 + 6 * ui)) ||
	    (cfg->hs_settle > (145000 + 10 * ui)))
		return -EINVAL;

	if (cfg->hs_skip < 40000 || cfg->hs_skip > (55000 + 4 * ui))
		return -EINVAL;

	if (cfg->hs_trail < max(8 * ui, 60000 + 4 * ui))
		return -EINVAL;

	if (cfg->init < 100)
		return -EINVAL;

	if (cfg->lpx < 50000)
		return -EINVAL;

	if (cfg->ta_get != (5 * cfg->lpx))
		return -EINVAL;

	if (cfg->ta_go != (4 * cfg->lpx))
		return -EINVAL;

	if (cfg->ta_sure < cfg->lpx || cfg->ta_sure > (2 * cfg->lpx))
		return -EINVAL;

	if (cfg->wakeup < 1000)
		return -EINVAL;

	return 0;
}
