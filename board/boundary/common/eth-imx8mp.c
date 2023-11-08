/*
 * Copyright (C) 2018, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#define GP_PHY_RD0		IMX_GPIO_NR(4, 6)
#define GP_PHY_RD1		IMX_GPIO_NR(4, 7)
#define GP_PHY_RD2		IMX_GPIO_NR(4, 8)
#define GP_PHY_RD3		IMX_GPIO_NR(4, 9)
#define GP_PHY_RX_CTL		IMX_GPIO_NR(4, 10)
#define GP_PHY_RXC		IMX_GPIO_NR(4, 11)

#define GP_PHY2_RD0		IMX_GPIO_NR(1, 26)
#define GP_PHY2_RD1		IMX_GPIO_NR(1, 27)
#define GP_PHY2_RD2		IMX_GPIO_NR(1, 28)
#define GP_PHY2_RD3		IMX_GPIO_NR(1, 29)
#define GP_PHY2_RX_CTL		IMX_GPIO_NR(1, 24)
#define GP_PHY2_RXC		IMX_GPIO_NR(1, 25)

#if !defined(GP_RGMII_PHY_RESET) && defined(CONFIG_FEC_MXC)
#define GP_RGMII_PHY_RESET	IMX_GPIO_NR(5, 8)	/* fec */
#endif
#if !defined(GP_RGMII2_PHY_RESET) && defined(CONFIG_DWC_ETH_QOS)
#define GP_RGMII2_PHY_RESET	IMX_GPIO_NR(3, 16)	/* eqos */
#endif

#define AR_STRAP	(0x28 | (CONFIG_FEC_MXC_PHYADDR & 3))

#define STRAP_KSZ_CLK125_EN	0x10
#define STRAP_KSZ_BASE		0x0f
#define AR_STRAP_KSZ9021	(STRAP_KSZ_BASE | ((CONFIG_FEC_MXC_PHYADDR & 4) ? 0x20 : 0))

#if !defined(CONFIG_FEC_ENET1) && defined(CONFIG_FEC_MXC)
#define CONFIG_FEC_ENET1
#endif

#if !defined(CONFIG_FEC_ENET2) && defined(CONFIG_DWC_ETH_QOS)
#define CONFIG_FEC_ENET2
#endif

#if defined(CONFIG_FEC_ENET1)
#define STRAP_AR8035	AR_STRAP
#define STRAP_KSZ9021	AR_STRAP_KSZ9021
#endif

#if defined(CONFIG_FEC_ENET2)
#define STRAP2_AR8035	AR_STRAP
#define STRAP2_KSZ9021	AR_STRAP_KSZ9021
#endif

#if !defined(ENET2_BASE_ADDR) && defined(CONFIG_DWC_ETH_QOS)
#define ENET2_BASE_ADDR		EQOS_BASE_ADDR
#endif

#ifdef CONFIG_FEC_RESET_PULLUP
#define RESET_PINCTRL	WEAK_PULLUP_OUTPUT
#else
#define RESET_PINCTRL	WEAK_PULLDN_OUTPUT
#endif

#ifdef CONFIG_PHY_ATHEROS
#ifdef CONFIG_FEC_ENET1
static const iomux_v3_cfg_t enet_ar8035_gpio_pads[] = {
#if GP_RGMII_PHY_RESET == IMX_GPIO_NR(5, 8)
	IOMUX_PAD_CTRL(ECSPI1_MISO__GPIO5_IO08, RESET_PINCTRL),
#elif GP_RGMII_PHY_RESET == IMX_GPIO_NR(1, 12)
	IOMUX_PAD_CTRL(GPIO1_IO12__GPIO1_IO12, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(SAI1_RXD4__GPIO4_IO06, PULL_GP(STRAP_AR8035, 0)),
	IOMUX_PAD_CTRL(SAI1_RXD5__GPIO4_IO07, PULL_GP(STRAP_AR8035, 1)),
	IOMUX_PAD_CTRL(SAI1_RXD6__GPIO4_IO08, PULL_GP(STRAP_AR8035, 2)),
	IOMUX_PAD_CTRL(SAI1_RXD7__GPIO4_IO09, PULL_GP(STRAP_AR8035, 3)),
	IOMUX_PAD_CTRL(SAI1_TXFS__GPIO4_IO10, PULL_GP(STRAP_AR8035, 4)),
	IOMUX_PAD_CTRL(SAI1_TXC__GPIO4_IO11, PULL_GP(STRAP_AR8035, 5)),
};

static const iomux_v3_cfg_t enet_ar8035_pads[] = {
	IOMUX_PAD_CTRL(SAI1_RXD4__ENET1_RGMII_RD0, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD5__ENET1_RGMII_RD1, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD6__ENET1_RGMII_RD2, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD7__ENET1_RGMII_RD3, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_TXFS__ENET1_RGMII_RX_CTL, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_TXC__ENET1_RGMII_RXC, PAD_CTRL_ENET_RX),
};
#endif

#ifdef CONFIG_FEC_ENET2
static const iomux_v3_cfg_t enet2_ar8035_gpio_pads[] = {
#if GP_RGMII2_PHY_RESET == IMX_GPIO_NR(3, 16)
	IOMUX_PAD_CTRL(NAND_READY_B__GPIO3_IO16, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(ENET_RD0__GPIO1_IO26, PULL_GP(STRAP2_AR8035, 0)),
	IOMUX_PAD_CTRL(ENET_RD1__GPIO1_IO27, PULL_GP(STRAP2_AR8035, 1)),
	IOMUX_PAD_CTRL(ENET_RD2__GPIO1_IO28, PULL_GP(STRAP2_AR8035, 2)),
	IOMUX_PAD_CTRL(ENET_RD3__GPIO1_IO29, PULL_GP(STRAP2_AR8035, 3)),
	IOMUX_PAD_CTRL(ENET_RX_CTL__GPIO1_IO24, PULL_GP(STRAP2_AR8035, 4)),
	IOMUX_PAD_CTRL(ENET_RXC__GPIO1_IO25, PULL_GP(STRAP2_AR8035, 5)),
};

static const iomux_v3_cfg_t enet2_ar8035_pads[] = {
	IOMUX_PAD_CTRL(ENET_RD0__ENET_QOS_RGMII_RD0, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET_RD1__ENET_QOS_RGMII_RD1, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET_RD2__ENET_QOS_RGMII_RD2, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET_RD3__ENET_QOS_RGMII_RD3, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET_RX_CTL__ENET_QOS_RGMII_RX_CTL, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET_RXC__CCM_ENET_QOS_CLOCK_GENERATE_RX_CLK, PAD_CTRL_ENET_RX),
};
#endif
#endif

#ifdef CONFIG_PHY_MICREL
#ifdef CONFIG_FEC_ENET1
static const iomux_v3_cfg_t enet_ksz9021_gpio_pads[] = {
#if GP_RGMII_PHY_RESET == IMX_GPIO_NR(5, 8)
	IOMUX_PAD_CTRL(ECSPI1_MISO__GPIO5_IO08, RESET_PINCTRL),
#elif GP_RGMII_PHY_RESET == IMX_GPIO_NR(1, 12)
	IOMUX_PAD_CTRL(GPIO1_IO12__GPIO1_IO12, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(SAI1_RXD4__GPIO4_IO06, PULL_GP(STRAP_KSZ9021, 0)),
	IOMUX_PAD_CTRL(SAI1_RXD5__GPIO4_IO07, PULL_GP(STRAP_KSZ9021, 1)),
	IOMUX_PAD_CTRL(SAI1_RXD6__GPIO4_IO08, PULL_GP(STRAP_KSZ9021, 2)),
	IOMUX_PAD_CTRL(SAI1_RXD7__GPIO4_IO09, PULL_GP(STRAP_KSZ9021, 3)),
	IOMUX_PAD_CTRL(SAI1_TXFS__GPIO4_IO10, PULL_GP(STRAP_KSZ9021, 4)),
	IOMUX_PAD_CTRL(SAI1_TXC__GPIO4_IO11, PULL_GP(STRAP_KSZ9021, 5)),
};

static const iomux_v3_cfg_t enet_ksz9021_pads[] = {
	IOMUX_PAD_CTRL(SAI1_RXD4__ENET1_RGMII_RD0, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD5__ENET1_RGMII_RD1, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD6__ENET1_RGMII_RD2, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_RXD7__ENET1_RGMII_RD3, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_TXFS__ENET1_RGMII_RX_CTL, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(SAI1_TXC__ENET1_RGMII_RXC, PAD_CTRL_ENET_RX),
};
#endif

#ifdef CONFIG_FEC_ENET2
static const iomux_v3_cfg_t enet2_ksz9021_gpio_pads[] = {
#if GP_RGMII2_PHY_RESET == IMX_GPIO_NR(3, 16)
	IOMUX_PAD_CTRL(NAND_READY_B__GPIO3_IO16, RESET_PINCTRL),
#endif
	IOMUX_PAD_CTRL(ENET_RD0__GPIO1_IO26, PULL_GP(STRAP2_KSZ9021, 0)),
	IOMUX_PAD_CTRL(ENET_RD1__GPIO1_IO27, PULL_GP(STRAP2_KSZ9021, 1)),
	IOMUX_PAD_CTRL(ENET_RD2__GPIO1_IO28, PULL_GP(STRAP2_KSZ9021, 2)),
	IOMUX_PAD_CTRL(ENET_RD3__GPIO1_IO29, PULL_GP(STRAP2_KSZ9021, 3)),
	IOMUX_PAD_CTRL(ENET_RX_CTL__GPIO1_IO24, PULL_GP(STRAP2_KSZ9021, 4)),
	IOMUX_PAD_CTRL(ENET_RXC__GPIO1_IO25, PULL_GP(STRAP2_KSZ9021, 5)),
};

static const iomux_v3_cfg_t enet2_ksz9021_pads[] = {
	IOMUX_PAD_CTRL(ENET_RD0__ENET_QOS_RGMII_RD0, PULL_ENET(STRAP2_KSZ9021, 0)),
	IOMUX_PAD_CTRL(ENET_RD1__ENET_QOS_RGMII_RD1, PULL_ENET(STRAP2_KSZ9021, 1)),
	IOMUX_PAD_CTRL(ENET_RD2__ENET_QOS_RGMII_RD2, PULL_ENET(STRAP2_KSZ9021, 2)),
	IOMUX_PAD_CTRL(ENET_RD3__ENET_QOS_RGMII_RD3, PULL_ENET(STRAP2_KSZ9021, 3)),
	IOMUX_PAD_CTRL(ENET_RX_CTL__ENET_QOS_RGMII_RX_CTL, PULL_ENET(STRAP2_KSZ9021, 4)),
	IOMUX_PAD_CTRL(ENET_RXC__CCM_ENET_QOS_CLOCK_GENERATE_RX_CLK, PULL_ENET(STRAP2_KSZ9021, 5)),
};
#endif
#endif
