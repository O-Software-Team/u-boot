/*
 * Copyright (C) 2017, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#if !defined(CONFIG_FEC_ENET1) && !defined(CONFIG_FEC_ENET2) && defined(CONFIG_FEC_MXC)
#define CONFIG_FEC_ENET1
#endif

#ifdef CONFIG_FEC_ENET1
#define GP_PHY_RD0	IMX_GPIO_NR(7, 0)
#define GP_PHY_RD1	IMX_GPIO_NR(7, 1)
#define GP_PHY_RD2	IMX_GPIO_NR(7, 2)
#define GP_PHY_RD3	IMX_GPIO_NR(7, 3)
#define GP_PHY_RX_CTL	IMX_GPIO_NR(7, 4)
#define GP_PHY_RXC	IMX_GPIO_NR(7, 5)
#endif

#ifdef CONFIG_PHY_ATHEROS
#ifndef STRAP_AR8035
#define STRAP_AR8035	(0x28 | (CONFIG_FEC_MXC_PHYADDR & 3))
#endif

#ifdef CONFIG_FEC_ENET1
	/* really AR8031 for nitrogen7 */
static const iomux_v3_cfg_t enet_ar8035_gpio_pads[] = {
	IOMUX_PAD_CTRL(ENET1_RGMII_RD0__GPIO7_IO0, PULL_GP(STRAP_AR8035, 0)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RD1__GPIO7_IO1, PULL_GP(STRAP_AR8035, 1)),
	/* MODE - 1100 */
	IOMUX_PAD_CTRL(ENET1_RGMII_RD2__GPIO7_IO2, PULL_GP(STRAP_AR8035, 2)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RD3__GPIO7_IO3, PULL_GP(STRAP_AR8035, 3)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RX_CTL__GPIO7_IO4, PULL_GP(STRAP_AR8035, 4)),
	/* 1.8V(1)/1.5V select(0) */
	IOMUX_PAD_CTRL(ENET1_RGMII_RXC__GPIO7_IO5, PULL_GP(STRAP_AR8035, 5)),
};

static const iomux_v3_cfg_t enet_ar8035_pads[] = {
	IOMUX_PAD_CTRL(ENET1_RGMII_RD0__ENET1_RGMII_RD0, PULL_ENET(STRAP_AR8035, 0)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RD1__ENET1_RGMII_RD1, PULL_ENET(STRAP_AR8035, 1)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RD2__ENET1_RGMII_RD2, PULL_ENET(STRAP_AR8035, 2)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RD3__ENET1_RGMII_RD3, PULL_ENET(STRAP_AR8035, 3)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RX_CTL__ENET1_RGMII_RX_CTL, PULL_ENET(STRAP_AR8035, 4)),
	IOMUX_PAD_CTRL(ENET1_RGMII_RXC__ENET1_RGMII_RXC, PULL_ENET(STRAP_AR8035, 5)),
};
#endif
#endif
