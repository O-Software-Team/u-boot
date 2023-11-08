// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright 2019 NXP
 * Peng Fan <peng.fan@nxp.com>
 */

#include <common.h>
#include <clk.h>
#include <clk-uclass.h>
#include <dm.h>
#include <log.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <dt-bindings/clock/imx8mn-clock.h>

#include "clk.h"

static u32 share_count_disp;

static const char *pll_ref_sels[] = { "clock-osc-24m", "dummy", "dummy", "dummy", };
static const char * const video_pll1_bypass_sels[] = {"video_pll1", "video_pll1_ref_sel", };
static const char *dram_pll_bypass_sels[] = {"dram_pll", "dram_pll_ref_sel", };
static const char *arm_pll_bypass_sels[] = {"arm_pll", "arm_pll_ref_sel", };
static const char *sys_pll1_bypass_sels[] = {"sys_pll1", "sys_pll1_ref_sel", };
static const char *sys_pll2_bypass_sels[] = {"sys_pll2", "sys_pll2_ref_sel", };
static const char *sys_pll3_bypass_sels[] = {"sys_pll3", "sys_pll3_ref_sel", };

static const char *imx8mn_a53_sels[] = {"clock-osc-24m", "arm_pll_out", "sys_pll2_500m", "sys_pll2_1000m",
					"sys_pll1_800m", "sys_pll1_400m", "audio_pll1_out", "sys_pll3_out", };

static const char *imx8mn_ahb_sels[] = {"clock-osc-24m", "sys_pll1_133m", "sys_pll1_800m", "sys_pll1_400m",
					"sys_pll2_125m", "sys_pll3_out", "audio_pll1_out", "video_pll1_out", };

static const char *imx8mn_enet_axi_sels[] = {"clock-osc-24m", "sys_pll1_266m", "sys_pll1_800m", "sys_pll2_250m",
					     "sys_pll2_200m", "audio_pll1_out", "video_pll1_out", "sys_pll3_out", };

#ifndef CONFIG_SPL_BUILD
static const char *imx8mn_enet_ref_sels[] = {"clock-osc-24m", "sys_pll2_125m", "sys_pll2_50m", "sys_pll2_100m",
					     "sys_pll1_160m", "audio_pll1_out", "video_pll1_out", "clk_ext4", };

static const char *imx8mn_enet_timer_sels[] = {"clock-osc-24m", "sys_pll2_100m", "audio_pll1_out", "clk_ext1", "clk_ext2",
					       "clk_ext3", "clk_ext4", "video_pll1_out", };

static const char *imx8mn_enet_phy_sels[] = {"clock-osc-24m", "sys_pll2_50m", "sys_pll2_125m", "sys_pll2_200m",
					     "sys_pll2_500m", "video_pll1_out", "audio_pll2_out", };
#endif

static const char *imx8mn_nand_usdhc_sels[] = {"clock-osc-24m", "sys_pll1_266m", "sys_pll1_800m", "sys_pll2_200m",
					       "sys_pll1_133m", "sys_pll3_out", "sys_pll2_250m", "audio_pll1_out", };

static const char * const imx8mn_disp_axi_sels[] = {"clock-osc-24m", "sys_pll2_1000m", "sys_pll1_800m",
						    "sys_pll3_out", "sys_pll1_40m", "audio_pll2_out",
						    "clk_ext1", "clk_ext4", };

static const char * const imx8mn_disp_apb_sels[] = {"clock-osc-24m", "sys_pll2_125m", "sys_pll1_800m",
						    "sys_pll3_out", "sys_pll1_40m", "audio_pll2_out",
						    "clk_ext1", "clk_ext3", };

static const char * const imx8mn_usb_bus_sels[] = {"clock-osc-24m", "sys_pll2_500m", "sys_pll1_800m",
						"sys_pll2_100m", "sys_pll2_200m", "clk_ext2",
						"clk_ext4", "audio_pll2_out", };

static const char * const imx8mn_disp_pixel_sels[] = {"clock-osc-24m", "video_pll1_out", "audio_pll2_out",
						      "audio_pll1_out", "sys_pll1_800m", "sys_pll2_1000m",
						      "sys_pll3_out", "clk_ext4", };

static const char *imx8mn_usdhc1_sels[] = {"clock-osc-24m", "sys_pll1_400m", "sys_pll1_800m", "sys_pll2_500m",
					   "sys_pll3_out", "sys_pll1_266m", "audio_pll2_out", "sys_pll1_100m", };

static const char *imx8mn_usdhc2_sels[] = {"clock-osc-24m", "sys_pll1_400m", "sys_pll1_800m", "sys_pll2_500m",
					   "sys_pll3_out", "sys_pll1_266m", "audio_pll2_out", "sys_pll1_100m", };

#if CONFIG_IS_ENABLED(DM_SPI)
static const char *imx8mn_ecspi1_sels[] = {"osc_24m", "sys_pll2_200m", "sys_pll1_40m",
					   "sys_pll1_160m", "sys_pll1_800m", "sys_pll3_out",
					   "sys_pll2_250m", "audio_pll2_out", };

static const char *imx8mn_ecspi2_sels[] = {"osc_24m", "sys_pll2_200m", "sys_pll1_40m",
					   "sys_pll1_160m", "sys_pll1_800m", "sys_pll3_out",
					   "sys_pll2_250m", "audio_pll2_out", };

static const char *imx8mn_ecspi3_sels[] = {"osc_24m", "sys_pll2_200m", "sys_pll1_40m",
					   "sys_pll1_160m", "sys_pll1_800m", "sys_pll3_out",
					   "sys_pll2_250m", "audio_pll2_out", };
#endif

static const char *imx8mn_i2c1_sels[] = {"clock-osc-24m", "sys_pll1_160m", "sys_pll2_50m", "sys_pll3_out", "audio_pll1_out",
					 "video_pll1_out", "audio_pll2_out", "sys_pll1_133m", };

static const char *imx8mn_i2c2_sels[] = {"clock-osc-24m", "sys_pll1_160m", "sys_pll2_50m", "sys_pll3_out", "audio_pll1_out",
					 "video_pll1_out", "audio_pll2_out", "sys_pll1_133m", };

static const char *imx8mn_i2c3_sels[] = {"clock-osc-24m", "sys_pll1_160m", "sys_pll2_50m", "sys_pll3_out", "audio_pll1_out",
					 "video_pll1_out", "audio_pll2_out", "sys_pll1_133m", };

static const char *imx8mn_i2c4_sels[] = {"clock-osc-24m", "sys_pll1_160m", "sys_pll2_50m", "sys_pll3_out", "audio_pll1_out",
					 "video_pll1_out", "audio_pll2_out", "sys_pll1_133m", };

static const char * const imx8mn_pwm1_sels[] = {"clock-osc-24m", "sys_pll2_100m", "sys_pll1_160m",
						"sys_pll1_40m", "sys_pll3_out", "clk_ext1",
						"sys_pll1_80m", "video_pll1_out", };

static const char * const imx8mn_pwm2_sels[] = {"clock-osc-24m", "sys_pll2_100m", "sys_pll1_160m",
						"sys_pll1_40m", "sys_pll3_out", "clk_ext1",
						"sys_pll1_80m", "video_pll1_out", };

static const char * const imx8mn_pwm3_sels[] = {"clock-osc-24m", "sys_pll2_100m", "sys_pll1_160m",
						"sys_pll1_40m", "sys_pll3_out", "clk_ext2",
						"sys_pll1_80m", "video_pll1_out", };

static const char * const imx8mn_pwm4_sels[] = {"clock-osc-24m", "sys_pll2_100m", "sys_pll1_160m",
						"sys_pll1_40m", "sys_pll3_out", "clk_ext2",
						"sys_pll1_80m", "video_pll1_out", };

static const char *imx8mn_wdog_sels[] = {"clock-osc-24m", "sys_pll1_133m", "sys_pll1_160m", "vpu_pll_out",
					 "sys_pll2_125m", "sys_pll3_out", "sys_pll1_80m", "sys_pll2_166m", };

static const char * const imx8mn_dsi_core_sels[] = {"clock-osc-24m", "sys_pll1_266m", "sys_pll2_250m",
						    "sys_pll1_800m", "sys_pll2_1000m", "sys_pll3_out",
						    "audio_pll2_out", "video_pll1_out", };

static const char * const imx8mn_dsi_phy_sels[] = {"clock-osc-24m", "sys_pll2_125m", "sys_pll2_100m",
						   "sys_pll1_800m", "sys_pll2_1000m", "clk_ext2",
						   "audio_pll2_out", "video_pll1_out", };

static const char * const imx8mn_dsi_dbi_sels[] = {"clock-osc-24m", "sys_pll1_266m", "sys_pll2_100m",
						   "sys_pll1_800m", "sys_pll2_1000m", "sys_pll3_out",
						   "audio_pll2_out", "video_pll1_out", };

static const char *imx8mn_usdhc3_sels[] = {"clock-osc-24m", "sys_pll1_400m", "sys_pll1_800m", "sys_pll2_500m",
					   "sys_pll3_out", "sys_pll1_266m", "audio_pll2_clk", "sys_pll1_100m", };

static const char *imx8mn_qspi_sels[] = {"clock-osc-24m", "sys_pll1_400m", "sys_pll2_333m", "sys_pll2_500m",
					   "audio_pll2_out", "sys_pll1_266m", "sys_pll3_out", "sys_pll1_100m", };

static const char * const imx8mn_usb_core_sels[] = {"clock-osc-24m", "sys_pll1_100m", "sys_pll1_40m",
						"sys_pll2_100m", "sys_pll2_200m", "clk_ext2",
						"clk_ext3", "audio_pll2_out", };

static const char * const imx8mn_usb_phy_sels[] = {"clock-osc-24m", "sys_pll1_100m", "sys_pll1_40m",
						"sys_pll2_100m", "sys_pll2_200m", "clk_ext2",
						"clk_ext3", "audio_pll2_out", };

static inline void clk_dm2(ulong id, ofnode np, const char *name)
{
	struct clk clk_tmp;
	struct clk *pclk;
	int ret = clk_get_by_name_nodev(np, name, &clk_tmp);

	if (!ret) {
		pclk = dev_get_clk_ptr(clk_tmp.dev);
		pclk->id = id;
	}
}

static int imx8mn_clk_probe(struct udevice *dev)
{
	ofnode np = dev_ofnode(dev);
	void __iomem *base;

	base = (void *)ANATOP_BASE_ADDR;

	clk_dm2(IMX8MN_CLK_DUMMY, np, "dummy");
	clk_dm2(IMX8MN_CLK_32K, np, "osc_32k");
	clk_dm2(IMX8MN_CLK_24M, np, "osc_24m");
	clk_dm2(IMX8MN_CLK_EXT1, np, "clk_ext1");
	clk_dm2(IMX8MN_CLK_EXT2, np, "clk_ext2");
	clk_dm2(IMX8MN_CLK_EXT3, np, "clk_ext3");
	clk_dm2(IMX8MN_CLK_EXT4, np, "clk_ext4");

	clk_dm(IMX8MN_VIDEO_PLL1_REF_SEL,
	       imx_clk_mux("video_pll1_ref_sel", base + 0x28, 0, 2, pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));
	clk_dm(IMX8MN_DRAM_PLL_REF_SEL,
	       imx_clk_mux("dram_pll_ref_sel", base + 0x50, 0, 2,
			   pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));
	clk_dm(IMX8MN_ARM_PLL_REF_SEL,
	       imx_clk_mux("arm_pll_ref_sel", base + 0x84, 0, 2,
			   pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));
	clk_dm(IMX8MN_SYS_PLL1_REF_SEL,
	       imx_clk_mux("sys_pll1_ref_sel", base + 0x94, 0, 2,
			   pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));
	clk_dm(IMX8MN_SYS_PLL2_REF_SEL,
	       imx_clk_mux("sys_pll2_ref_sel", base + 0x104, 0, 2,
			   pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));
	clk_dm(IMX8MN_SYS_PLL3_REF_SEL,
	       imx_clk_mux("sys_pll3_ref_sel", base + 0x114, 0, 2,
			   pll_ref_sels, ARRAY_SIZE(pll_ref_sels)));

	clk_dm(IMX8MN_VIDEO_PLL1,
	       imx_dev_clk_hw_pll14xx(dev, "video_pll1", "video_pll1_ref_sel", base + 0x28, &imx_1443x_pll));
	clk_dm(IMX8MN_DRAM_PLL,
	       imx_dev_clk_hw_pll14xx(dev, "dram_pll", "dram_pll_ref_sel",
			       base + 0x50, &imx_1443x_dram_pll));
	clk_dm(IMX8MN_ARM_PLL,
	       imx_clk_pll14xx("arm_pll", "arm_pll_ref_sel",
			       base + 0x84, &imx_1416x_pll));
	clk_dm(IMX8MN_SYS_PLL1,
	       imx_clk_pll14xx("sys_pll1", "sys_pll1_ref_sel",
			       base + 0x94, &imx_1416x_pll));
	clk_dm(IMX8MN_SYS_PLL2,
	       imx_clk_pll14xx("sys_pll2", "sys_pll2_ref_sel",
			       base + 0x104, &imx_1416x_pll));
	clk_dm(IMX8MN_SYS_PLL3,
	       imx_clk_pll14xx("sys_pll3", "sys_pll3_ref_sel",
			       base + 0x114, &imx_1416x_pll));

	/* PLL bypass out */
	clk_dm(IMX8MN_VIDEO_PLL1_BYPASS,
	       imx_clk_mux_flags("video_pll1_bypass", base + 0x28, 16, 1, video_pll1_bypass_sels, ARRAY_SIZE(video_pll1_bypass_sels), CLK_SET_RATE_PARENT));
	clk_dm(IMX8MN_DRAM_PLL_BYPASS,
	       imx_clk_mux_flags("dram_pll_bypass", base + 0x50, 4, 1,
				 dram_pll_bypass_sels,
				 ARRAY_SIZE(dram_pll_bypass_sels),
				 CLK_SET_RATE_PARENT));
	clk_dm(IMX8MN_ARM_PLL_BYPASS,
	       imx_clk_mux_flags("arm_pll_bypass", base + 0x84, 4, 1,
				 arm_pll_bypass_sels,
				 ARRAY_SIZE(arm_pll_bypass_sels),
				 CLK_SET_RATE_PARENT));
	clk_dm(IMX8MN_SYS_PLL1_BYPASS,
	       imx_clk_mux_flags("sys_pll1_bypass", base + 0x94, 4, 1,
				 sys_pll1_bypass_sels,
				 ARRAY_SIZE(sys_pll1_bypass_sels),
				 CLK_SET_RATE_PARENT));
	clk_dm(IMX8MN_SYS_PLL2_BYPASS,
	       imx_clk_mux_flags("sys_pll2_bypass", base + 0x104, 4, 1,
				 sys_pll2_bypass_sels,
				 ARRAY_SIZE(sys_pll2_bypass_sels),
				 CLK_SET_RATE_PARENT));
	clk_dm(IMX8MN_SYS_PLL3_BYPASS,
	       imx_clk_mux_flags("sys_pll3_bypass", base + 0x114, 4, 1,
				 sys_pll3_bypass_sels,
				 ARRAY_SIZE(sys_pll3_bypass_sels),
				 CLK_SET_RATE_PARENT));

	/* PLL out gate */
	clk_dm(IMX8MN_VIDEO_PLL1_OUT,
	       imx_clk_gate("video_pll1_out", "video_pll1_bypass", base + 0x28, 13));
	clk_dm(IMX8MN_DRAM_PLL_OUT,
	       imx_clk_gate("dram_pll_out", "dram_pll_bypass",
			    base + 0x50, 13));
	clk_dm(IMX8MN_ARM_PLL_OUT,
	       imx_clk_gate("arm_pll_out", "arm_pll_bypass",
			    base + 0x84, 11));
	clk_dm(IMX8MN_SYS_PLL1_OUT,
	       imx_clk_gate("sys_pll1_out", "sys_pll1_bypass",
			    base + 0x94, 11));
	clk_dm(IMX8MN_SYS_PLL2_OUT,
	       imx_clk_gate("sys_pll2_out", "sys_pll2_bypass",
			    base + 0x104, 11));
	clk_dm(IMX8MN_SYS_PLL3_OUT,
	       imx_clk_gate("sys_pll3_out", "sys_pll3_bypass",
			    base + 0x114, 11));

	/* SYS PLL fixed output */
	clk_dm(IMX8MN_SYS_PLL1_40M,
	       imx_clk_fixed_factor("sys_pll1_40m", "sys_pll1_out", 1, 20));
	clk_dm(IMX8MN_SYS_PLL1_80M,
	       imx_clk_fixed_factor("sys_pll1_80m", "sys_pll1_out", 1, 10));
	clk_dm(IMX8MN_SYS_PLL1_100M,
	       imx_clk_fixed_factor("sys_pll1_100m", "sys_pll1_out", 1, 8));
	clk_dm(IMX8MN_SYS_PLL1_133M,
	       imx_clk_fixed_factor("sys_pll1_133m", "sys_pll1_out", 1, 6));
	clk_dm(IMX8MN_SYS_PLL1_160M,
	       imx_clk_fixed_factor("sys_pll1_160m", "sys_pll1_out", 1, 5));
	clk_dm(IMX8MN_SYS_PLL1_200M,
	       imx_clk_fixed_factor("sys_pll1_200m", "sys_pll1_out", 1, 4));
	clk_dm(IMX8MN_SYS_PLL1_266M,
	       imx_clk_fixed_factor("sys_pll1_266m", "sys_pll1_out", 1, 3));
	clk_dm(IMX8MN_SYS_PLL1_400M,
	       imx_clk_fixed_factor("sys_pll1_400m", "sys_pll1_out", 1, 2));
	clk_dm(IMX8MN_SYS_PLL1_800M,
	       imx_clk_fixed_factor("sys_pll1_800m", "sys_pll1_out", 1, 1));

	clk_dm(IMX8MN_SYS_PLL2_50M,
	       imx_clk_fixed_factor("sys_pll2_50m", "sys_pll2_out", 1, 20));
	clk_dm(IMX8MN_SYS_PLL2_100M,
	       imx_clk_fixed_factor("sys_pll2_100m", "sys_pll2_out", 1, 10));
	clk_dm(IMX8MN_SYS_PLL2_125M,
	       imx_clk_fixed_factor("sys_pll2_125m", "sys_pll2_out", 1, 8));
	clk_dm(IMX8MN_SYS_PLL2_166M,
	       imx_clk_fixed_factor("sys_pll2_166m", "sys_pll2_out", 1, 6));
	clk_dm(IMX8MN_SYS_PLL2_200M,
	       imx_clk_fixed_factor("sys_pll2_200m", "sys_pll2_out", 1, 5));
	clk_dm(IMX8MN_SYS_PLL2_250M,
	       imx_clk_fixed_factor("sys_pll2_250m", "sys_pll2_out", 1, 4));
	clk_dm(IMX8MN_SYS_PLL2_333M,
	       imx_clk_fixed_factor("sys_pll2_333m", "sys_pll2_out", 1, 3));
	clk_dm(IMX8MN_SYS_PLL2_500M,
	       imx_clk_fixed_factor("sys_pll2_500m", "sys_pll2_out", 1, 2));
	clk_dm(IMX8MN_SYS_PLL2_1000M,
	       imx_clk_fixed_factor("sys_pll2_1000m", "sys_pll2_out", 1, 1));

	base = dev_read_addr_ptr(dev);
	if (!base)
		return -EINVAL;

	clk_dm(IMX8MN_CLK_A53_SRC,
	       imx_clk_mux2("arm_a53_src", base + 0x8000, 24, 3,
			    imx8mn_a53_sels, ARRAY_SIZE(imx8mn_a53_sels)));
	clk_dm(IMX8MN_CLK_A53_CG,
	       imx_clk_gate3("arm_a53_cg", "arm_a53_src", base + 0x8000, 28));
	clk_dm(IMX8MN_CLK_A53_DIV,
	       imx_clk_divider2("arm_a53_div", "arm_a53_cg",
				base + 0x8000, 0, 3));

	/* BUS */
	clk_dm(IMX8MN_CLK_ENET_AXI,
	       imx8m_clk_composite("enet_axi", imx8mn_enet_axi_sels,
				   base + 0x8880));
	clk_dm(IMX8MN_CLK_NAND_USDHC_BUS,
	       imx8m_clk_composite_critical("nand_usdhc_bus",
					    imx8mn_nand_usdhc_sels,
					    base + 0x8900));
	clk_dm(IMX8MN_CLK_DISP_AXI,
	       imx8m_clk_composite("disp_axi", imx8mn_disp_axi_sels, base + 0x8a00));
	clk_dm(IMX8MN_CLK_DISP_APB,
	       imx8m_clk_composite("disp_apb", imx8mn_disp_apb_sels, base + 0x8a80));
	clk_dm(IMX8MN_CLK_USB_BUS,
	       imx8m_clk_composite("usb_bus", imx8mn_usb_bus_sels, base + 0x8b80));
	clk_dm(IMX8MN_CLK_AHB,
	       imx8m_clk_composite_critical("ahb", imx8mn_ahb_sels, base + 0x9000));
	clk_dm(IMX8MN_CLK_IPG_ROOT,
	       imx_clk_divider2("ipg_root", "ahb", base + 0x9080, 0, 1));
	clk_dm(IMX8MN_CLK_DISP_PIXEL,
	       imx8m_clk_composite("disp_pixel", imx8mn_disp_pixel_sels, base + 0xa500));

	/* IP */
	clk_dm(IMX8MN_CLK_USDHC1,
	       imx8m_clk_composite("usdhc1", imx8mn_usdhc1_sels,
				   base + 0xac00));
	clk_dm(IMX8MN_CLK_USDHC2,
	       imx8m_clk_composite("usdhc2", imx8mn_usdhc2_sels,
				   base + 0xac80));
	clk_dm(IMX8MN_CLK_I2C1,
	       imx8m_clk_composite("i2c1", imx8mn_i2c1_sels, base + 0xad00));
	clk_dm(IMX8MN_CLK_I2C2,
	       imx8m_clk_composite("i2c2", imx8mn_i2c2_sels, base + 0xad80));
	clk_dm(IMX8MN_CLK_I2C3,
	       imx8m_clk_composite("i2c3", imx8mn_i2c3_sels, base + 0xae00));
	clk_dm(IMX8MN_CLK_I2C4,
	       imx8m_clk_composite("i2c4", imx8mn_i2c4_sels, base + 0xae80));
	clk_dm(IMX8MN_CLK_PWM1,
	       imx8m_clk_composite("pwm1", imx8mn_pwm1_sels, base + 0xb380));
	clk_dm(IMX8MN_CLK_PWM2,
	       imx8m_clk_composite("pwm2", imx8mn_pwm2_sels, base + 0xb400));
	clk_dm(IMX8MN_CLK_PWM3,
	       imx8m_clk_composite("pwm3", imx8mn_pwm3_sels, base + 0xb480));
	clk_dm(IMX8MN_CLK_PWM4,
	       imx8m_clk_composite("pwm4", imx8mn_pwm4_sels, base + 0xb500));
	clk_dm(IMX8MN_CLK_WDOG,
	       imx8m_clk_composite("wdog", imx8mn_wdog_sels, base + 0xb900));
	clk_dm(IMX8MN_CLK_DSI_CORE,
	       imx8m_clk_composite("dsi_core", imx8mn_dsi_core_sels, base + 0xbb00));
	clk_dm(IMX8MN_CLK_DSI_PHY_REF,
	       imx8m_clk_composite("dsi_phy_ref", imx8mn_dsi_phy_sels, base + 0xbb80));
	clk_dm(IMX8MN_CLK_DSI_DBI,
	       imx8m_clk_composite("dsi_dbi", imx8mn_dsi_dbi_sels, base + 0xbc00));
	clk_dm(IMX8MN_CLK_USDHC3,
	       imx8m_clk_composite("usdhc3", imx8mn_usdhc3_sels,
				   base + 0xbc80));
	clk_dm(IMX8MN_CLK_QSPI,
	       imx8m_clk_composite("qspi", imx8mn_qspi_sels, base + 0xab80));
	clk_dm(IMX8MN_CLK_USB_CORE_REF,
		imx8m_clk_composite("usb_core_ref", imx8mn_usb_core_sels, base + 0xb100));
	clk_dm(IMX8MN_CLK_USB_PHY_REF,
		imx8m_clk_composite("usb_phy_ref", imx8mn_usb_phy_sels, base + 0xb180));

	clk_dm(IMX8MN_CLK_I2C1_ROOT,
	       imx_clk_gate4("i2c1_root_clk", "i2c1", base + 0x4170, 0));
	clk_dm(IMX8MN_CLK_I2C2_ROOT,
	       imx_clk_gate4("i2c2_root_clk", "i2c2", base + 0x4180, 0));
	clk_dm(IMX8MN_CLK_I2C3_ROOT,
	       imx_clk_gate4("i2c3_root_clk", "i2c3", base + 0x4190, 0));
	clk_dm(IMX8MN_CLK_I2C4_ROOT,
	       imx_clk_gate4("i2c4_root_clk", "i2c4", base + 0x41a0, 0));
	clk_dm(IMX8MN_CLK_OCOTP_ROOT,
	       imx_clk_gate4("ocotp_root_clk", "ipg_root", base + 0x4220, 0));
	clk_dm(IMX8MN_CLK_PWM1_ROOT,
	       imx_clk_gate4("pwm1_root_clk", "pwm1", base + 0x4280, 0));
	clk_dm(IMX8MN_CLK_PWM2_ROOT,
	       imx_clk_gate4("pwm2_root_clk", "pwm2", base + 0x4290, 0));
	clk_dm(IMX8MN_CLK_PWM3_ROOT,
	       imx_clk_gate4("pwm3_root_clk", "pwm3", base + 0x42a0, 0));
	clk_dm(IMX8MN_CLK_PWM4_ROOT,
	       imx_clk_gate4("pwm4_root_clk", "pwm4", base + 0x42b0, 0));
	clk_dm(IMX8MN_CLK_USDHC1_ROOT,
	       imx_clk_gate4("usdhc1_root_clk", "usdhc1", base + 0x4510, 0));
	clk_dm(IMX8MN_CLK_USDHC2_ROOT,
	       imx_clk_gate4("usdhc2_root_clk", "usdhc2", base + 0x4520, 0));
	clk_dm(IMX8MN_CLK_WDOG1_ROOT,
	       imx_clk_gate4("wdog1_root_clk", "wdog", base + 0x4530, 0));
	clk_dm(IMX8MN_CLK_WDOG2_ROOT,
	       imx_clk_gate4("wdog2_root_clk", "wdog", base + 0x4540, 0));
	clk_dm(IMX8MN_CLK_WDOG3_ROOT,
	       imx_clk_gate4("wdog3_root_clk", "wdog", base + 0x4550, 0));
	clk_dm(IMX8MN_CLK_DISP_AXI_ROOT,
	       imx_clk_gate2_shared2("disp_axi_root_clk", "disp_axi", base + 0x45d0, 0, &share_count_disp));
	clk_dm(IMX8MN_CLK_DISP_APB_ROOT,
	       imx_clk_gate2_shared2("disp_apb_root_clk", "disp_apb", base + 0x45d0, 0, &share_count_disp));
	clk_dm(IMX8MN_CLK_DISP_PIXEL_ROOT,
	       imx_clk_gate2_shared2("disp_pixel_clk", "disp_pixel", base + 0x45d0, 0, &share_count_disp));
	clk_dm(IMX8MN_CLK_USDHC3_ROOT,
	       imx_clk_gate4("usdhc3_root_clk", "usdhc3", base + 0x45e0, 0));
	clk_dm(IMX8MN_CLK_QSPI_ROOT,
	       imx_clk_gate4("qspi_root_clk", "qspi", base + 0x42f0, 0));
	clk_dm(IMX8MN_CLK_USB1_CTRL_ROOT,
		imx_clk_gate4("usb1_ctrl_root_clk", "usb_bus", base + 0x44d0, 0));

	/* clks not needed in SPL stage */
#ifndef CONFIG_SPL_BUILD
	clk_dm(IMX8MN_CLK_ENET_REF,
	       imx8m_clk_composite("enet_ref", imx8mn_enet_ref_sels,
	       base + 0xa980));
	clk_dm(IMX8MN_CLK_ENET_TIMER,
	       imx8m_clk_composite("enet_timer", imx8mn_enet_timer_sels,
	       base + 0xaa00));
	clk_dm(IMX8MN_CLK_ENET_PHY_REF,
	       imx8m_clk_composite("enet_phy", imx8mn_enet_phy_sels,
	       base + 0xaa80));
	clk_dm(IMX8MN_CLK_ENET1_ROOT,
	       imx_clk_gate4("enet1_root_clk", "enet_axi",
	       base + 0x40a0, 0));
#endif

#if CONFIG_IS_ENABLED(DM_SPI)
	clk_dm(IMX8MN_CLK_ECSPI1,
	       imx8m_clk_composite("ecspi1", imx8mn_ecspi1_sels, base + 0xb280));
	clk_dm(IMX8MN_CLK_ECSPI2,
	       imx8m_clk_composite("ecspi2", imx8mn_ecspi2_sels, base + 0xb300));
	clk_dm(IMX8MN_CLK_ECSPI3,
	       imx8m_clk_composite("ecspi3", imx8mn_ecspi3_sels, base + 0xc180));
	clk_dm(IMX8MN_CLK_ECSPI1_ROOT,
	       imx_clk_gate4("ecspi1_root_clk", "ecspi1", base + 0x4070, 0));
	clk_dm(IMX8MN_CLK_ECSPI2_ROOT,
	       imx_clk_gate4("ecspi2_root_clk", "ecspi2", base + 0x4080, 0));
	clk_dm(IMX8MN_CLK_ECSPI3_ROOT,
	       imx_clk_gate4("ecspi3_root_clk", "ecspi3", base + 0x4090, 0));
#endif

	return 0;
}

static const struct udevice_id imx8mn_clk_ids[] = {
	{ .compatible = "fsl,imx8mn-ccm" },
	{ },
};

U_BOOT_DRIVER(imx8mn_clk) = {
	.name = "clk_imx8mn",
	.id = UCLASS_CLK,
	.of_match = imx8mn_clk_ids,
	.ops = &ccf_clk_ops,
	.probe = imx8mn_clk_probe,
	.flags = DM_FLAG_PRE_RELOC,
};
