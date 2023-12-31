/*
 * Copyright (C) 2017, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifdef CONFIG_FEC_ENET1
#define GP_PHY_RD0	IMX_GPIO_NR(5, 0)
#define GP_PHY_RD1	IMX_GPIO_NR(5, 1)
#define GP_PHY_RD2	IMX_GPIO_NR(5, 2)
#define GP_PHY_RD3	IMX_GPIO_NR(5, 3)
#define GP_PHY_RX_CTL	IMX_GPIO_NR(5, 4)
#define GP_PHY_RXC	IMX_GPIO_NR(5, 5)

#ifndef GP_RGMII_PHY_RESET
#define GP_RGMII_PHY_RESET	IMX_GPIO_NR(2, 7)
#endif
#endif

#ifdef CONFIG_FEC_ENET2
#define GP_PHY2_RD0	IMX_GPIO_NR(5, 12)
#define GP_PHY2_RD1	IMX_GPIO_NR(5, 13)
#define GP_PHY2_RD2	IMX_GPIO_NR(5, 14)
#define GP_PHY2_RD3	IMX_GPIO_NR(5, 15)
#define GP_PHY2_RX_CTL	IMX_GPIO_NR(5, 16)
#define GP_PHY2_RXC	IMX_GPIO_NR(5, 17)

#ifndef GP_RGMII2_PHY_RESET
#define GP_RGMII2_PHY_RESET	IMX_GPIO_NR(2, 6)
#endif
#endif

#ifdef CONFIG_FEC_RESET_PULLUP
#define RESET_PINCTRL	WEAK_PULLUP_OUTPUT
#else
#define RESET_PINCTRL	WEAK_PULLDN_OUTPUT
#endif

#ifdef CONFIG_PHY_ATHEROS
#if defined(CONFIG_FEC_ENET1)
#ifndef STRAP_AR8035
#define STRAP_AR8035	(0x28 | (CONFIG_FEC_MXC_PHYADDR & 3))
#endif
#endif

#if defined(CONFIG_FEC_ENET2)
#ifndef STRAP2_AR8035
#define STRAP2_AR8035	(0x28 | (CONFIG_FEC_MXC_PHYADDR2 & 3))
#endif
#endif

#ifdef CONFIG_FEC_ENET1
static const iomux_v3_cfg_t enet_ar8035_gpio_pads[] = {
#if GP_RGMII_PHY_RESET == IMX_GPIO_NR(2, 7)
	IOMUX_PAD_CTRL(ENET2_CRS__GPIO2_IO_7, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(RGMII1_RD0__GPIO5_IO_0, PULL_GP(STRAP_AR8035, 0)),
	IOMUX_PAD_CTRL(RGMII1_RD1__GPIO5_IO_1, PULL_GP(STRAP_AR8035, 1)),
	IOMUX_PAD_CTRL(RGMII1_RD2__GPIO5_IO_2, PULL_GP(STRAP_AR8035, 2)),
	IOMUX_PAD_CTRL(RGMII1_RD3__GPIO5_IO_3, PULL_GP(STRAP_AR8035, 3)),
	IOMUX_PAD_CTRL(RGMII1_RX_CTL__GPIO5_IO_4, PULL_GP(STRAP_AR8035, 4)),
	/* 1.8V(1)/1.5V select(0) */
	IOMUX_PAD_CTRL(RGMII1_RXC__GPIO5_IO_5, PULL_GP(STRAP_AR8035, 5)),
};

static const iomux_v3_cfg_t enet_ar8035_pads[] = {
	IOMUX_PAD_CTRL(RGMII1_RD0__ENET1_RX_DATA_0, PULL_ENET(STRAP_AR8035, 0)),
	IOMUX_PAD_CTRL(RGMII1_RD1__ENET1_RX_DATA_1, PULL_ENET(STRAP_AR8035, 1)),
	IOMUX_PAD_CTRL(RGMII1_RD2__ENET1_RX_DATA_2, PULL_ENET(STRAP_AR8035, 2)),
	IOMUX_PAD_CTRL(RGMII1_RD3__ENET1_RX_DATA_3, PULL_ENET(STRAP_AR8035, 3)),
	IOMUX_PAD_CTRL(RGMII1_RX_CTL__ENET1_RX_EN, PULL_ENET(STRAP_AR8035, 4)),
	IOMUX_PAD_CTRL(RGMII1_RXC__ENET1_RX_CLK, PULL_ENET(STRAP_AR8035, 5)),

};
#endif

#ifdef CONFIG_FEC_ENET2
static const iomux_v3_cfg_t enet2_ar8035_gpio_pads[] = {
#if GP_RGMII2_PHY_RESET == IMX_GPIO_NR(2, 6)
	IOMUX_PAD_CTRL(ENET2_COL__GPIO2_IO_6, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(RGMII2_RD0__GPIO5_IO_12, PULL_GP(STRAP2_AR8035, 0)),
	IOMUX_PAD_CTRL(RGMII2_RD1__GPIO5_IO_13, PULL_GP(STRAP2_AR8035, 1)),
	IOMUX_PAD_CTRL(RGMII2_RD2__GPIO5_IO_14, PULL_GP(STRAP2_AR8035, 2)),
	/* MODE 2 is LED_100, Internal pull up */
	IOMUX_PAD_CTRL(RGMII2_RD3__GPIO5_IO_15, PULL_GP(STRAP2_AR8035, 3)),
	IOMUX_PAD_CTRL(RGMII2_RX_CTL__GPIO5_IO_16, PULL_GP(STRAP2_AR8035, 4)),
	/* 1.8V(1)/1.5V select(0) */
	IOMUX_PAD_CTRL(RGMII2_RXC__GPIO5_IO_17, PULL_GP(STRAP2_AR8035, 5)),
};

static const iomux_v3_cfg_t enet2_ar8035_pads[] = {
	IOMUX_PAD_CTRL(RGMII2_RD0__ENET2_RX_DATA_0, PULL_ENET(STRAP2_AR8035, 0)),
	IOMUX_PAD_CTRL(RGMII2_RD1__ENET2_RX_DATA_1, PULL_ENET(STRAP2_AR8035, 1)),
	IOMUX_PAD_CTRL(RGMII2_RD2__ENET2_RX_DATA_2, PULL_ENET(STRAP2_AR8035, 2)),
	IOMUX_PAD_CTRL(RGMII2_RD3__ENET2_RX_DATA_3, PULL_ENET(STRAP2_AR8035, 3)),
	IOMUX_PAD_CTRL(RGMII2_RX_CTL__ENET2_RX_EN, PULL_ENET(STRAP2_AR8035, 4)),
	IOMUX_PAD_CTRL(RGMII2_RXC__ENET2_RX_CLK, PULL_ENET(STRAP2_AR8035, 5)),
};
#endif
#endif

#ifdef CONFIG_PHY_MICREL
#define STRAP_KSZ_CLK125_EN	0x10
#define STRAP_KSZ_BASE		0x0f

#if defined(CONFIG_FEC_ENET1)
#ifndef STRAP_KSZ9021
#define STRAP_KSZ9021	(STRAP_KSZ_BASE | ((CONFIG_FEC_MXC_KSZ_PHYADDR & 4) ? 0x20 : 0))
#endif
#endif

#if defined(CONFIG_FEC_ENET2)
#ifndef STRAP2_KSZ9021
#define STRAP2_KSZ9021	(STRAP_KSZ_BASE | ((CONFIG_FEC_MXC_KSZ_PHYADDR2 & 4) ? 0x20 : 0))
#endif
#endif

#ifdef CONFIG_FEC_ENET1
static const iomux_v3_cfg_t enet_ksz9021_gpio_pads[] = {
#if GP_RGMII_PHY_RESET == IMX_GPIO_NR(2, 7)
	IOMUX_PAD_CTRL(ENET2_CRS__GPIO2_IO_7, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(RGMII1_RD0__GPIO5_IO_0, PULL_GP(STRAP_KSZ9021, 0)),
	IOMUX_PAD_CTRL(RGMII1_RD1__GPIO5_IO_1, PULL_GP(STRAP_KSZ9021, 1)),
	IOMUX_PAD_CTRL(RGMII1_RD2__GPIO5_IO_2, PULL_GP(STRAP_KSZ9021, 2)),
	IOMUX_PAD_CTRL(RGMII1_RD3__GPIO5_IO_3, PULL_GP(STRAP_KSZ9021, 3)),
	IOMUX_PAD_CTRL(RGMII1_RX_CTL__GPIO5_IO_4, PULL_GP(STRAP_KSZ9021, 4)),
	IOMUX_PAD_CTRL(RGMII1_RXC__GPIO5_IO_5, PULL_GP(STRAP_KSZ9021, 5)),

};

static const iomux_v3_cfg_t enet_ksz9021_pads[] = {
	IOMUX_PAD_CTRL(RGMII1_RD0__ENET1_RX_DATA_0, PULL_ENET(STRAP_KSZ9021, 0)),
	IOMUX_PAD_CTRL(RGMII1_RD1__ENET1_RX_DATA_1, PULL_ENET(STRAP_KSZ9021, 1)),
	IOMUX_PAD_CTRL(RGMII1_RD2__ENET1_RX_DATA_2, PULL_ENET(STRAP_KSZ9021, 2)),
	IOMUX_PAD_CTRL(RGMII1_RD3__ENET1_RX_DATA_3, PULL_ENET(STRAP_KSZ9021, 3)),
	IOMUX_PAD_CTRL(RGMII1_RX_CTL__ENET1_RX_EN, PULL_ENET(STRAP_KSZ9021, 4)),
	IOMUX_PAD_CTRL(RGMII1_RXC__ENET1_RX_CLK, PULL_ENET(STRAP_KSZ9021, 5)),

};
#endif

#ifdef CONFIG_FEC_ENET2
static const iomux_v3_cfg_t enet2_ksz9021_gpio_pads[] = {
#if GP_RGMII2_PHY_RESET == IMX_GPIO_NR(2, 6)
	IOMUX_PAD_CTRL(ENET2_COL__GPIO2_IO_6, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(RGMII2_RD0__GPIO5_IO_12, PULL_GP(STRAP_KSZ9021, 0)),
	IOMUX_PAD_CTRL(RGMII2_RD1__GPIO5_IO_13, PULL_GP(STRAP_KSZ9021, 1)),
	IOMUX_PAD_CTRL(RGMII2_RD2__GPIO5_IO_14, PULL_GP(STRAP_KSZ9021, 2)),
	IOMUX_PAD_CTRL(RGMII2_RD3__GPIO5_IO_15, PULL_GP(STRAP_KSZ9021, 3)),
	IOMUX_PAD_CTRL(RGMII2_RX_CTL__GPIO5_IO_16, PULL_GP(STRAP_KSZ9021, 4)),
	IOMUX_PAD_CTRL(RGMII2_RXC__GPIO5_IO_17, PULL_GP(STRAP_KSZ9021, 5)),
};

static const iomux_v3_cfg_t enet2_ksz9021_pads[] = {
	IOMUX_PAD_CTRL(RGMII2_RD0__ENET2_RX_DATA_0, PULL_ENET(STRAP_KSZ9021, 0)),
	IOMUX_PAD_CTRL(RGMII2_RD1__ENET2_RX_DATA_1, PULL_ENET(STRAP_KSZ9021, 1)),
	IOMUX_PAD_CTRL(RGMII2_RD2__ENET2_RX_DATA_2, PULL_ENET(STRAP_KSZ9021, 2)),
	IOMUX_PAD_CTRL(RGMII2_RD3__ENET2_RX_DATA_3, PULL_ENET(STRAP_KSZ9021, 3)),
	IOMUX_PAD_CTRL(RGMII2_RX_CTL__ENET2_RX_EN, PULL_ENET(STRAP_KSZ9021, 4)),
	IOMUX_PAD_CTRL(RGMII2_RXC__ENET2_RX_CLK, PULL_ENET(STRAP_KSZ9021, 5)),
};
#endif
#endif
