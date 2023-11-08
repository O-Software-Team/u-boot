/*
 * Copyright (C) 2017, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifdef CONFIG_FEC_ENET2
#define GP_PHY2_RD0	IMX_GPIO_NR(2, 8)	/* pin 29, port 2, 0 flow based on autoneg, 1 - force flow control */
#define GP_PHY2_RD1	IMX_GPIO_NR(2, 9)	/* pin 28, port 2, 1 - full duplex */
#define GP_PHY2_RD2	IMX_GPIO_NR(1, 24)	/* pin 27, port 2, 1 - 100BT, 0 - 10BT */
#define GP_PHY2_RD3	IMX_GPIO_NR(1, 25)	/* pin 26, port 2, 1 - autoneg */
//#define GP_PHY2_RXC	IMX_GPIO_NR(1, 26)
#define GP_PHY2_RX_EN	IMX_GPIO_NR(2, 10)	/* pin 25, port 1, 1 - full duplex */
#define GP_PHY2_ER	IMX_GPIO_NR(2, 15)
#define GP_PHY2_CRS	IMX_GPIO_NR(1, 30)	/* pin 34 */
#define GP_PHY2_COL	IMX_GPIO_NR(1, 31)

#define GP_PHY2_TD0	IMX_GPIO_NR(2, 11)	/* pin 20, 1 */
#define GP_PHY2_TD1	IMX_GPIO_NR(2, 12)	/* pin 19, 1 */
#define GP_PHY2_TD2	IMX_GPIO_NR(1, 28)	/* pin 18, 0 - 50M to X1, 1 - 25M to X1  */
#define GP_PHY2_TD3	IMX_GPIO_NR(1, 29)	/* pin 17, 0 - disable REFCLKO_3 output*/
#endif

#ifdef CONFIG_PHY_MICREL_KSZ8XXX
#define STRAP2_KSZ8863	(0x03fe)

#ifdef CONFIG_FEC_ENET2
static const iomux_v3_cfg_t enet2_ksz8863_gpio_pads[] = {
	IOMUX_PAD_CTRL(ENET2_RX_DATA0__GPIO2_IO08, PULL_GP(STRAP2_KSZ8863, 0)),
	IOMUX_PAD_CTRL(ENET2_RX_DATA1__GPIO2_IO09, PULL_GP(STRAP2_KSZ8863, 1)),
	IOMUX_PAD_CTRL(UART3_TX_DATA__GPIO1_IO24, PULL_GP(STRAP2_KSZ8863, 2)),
	IOMUX_PAD_CTRL(UART3_RX_DATA__GPIO1_IO25, PULL_GP(STRAP2_KSZ8863, 3)),

//	IOMUX_PAD_CTRL(UART3_CTS_B__GPIO1_IO26, PULL_GP(STRAP2_KSZ8863, 4)),
	IOMUX_PAD_CTRL(ENET2_RX_EN__GPIO2_IO10, PULL_GP(STRAP2_KSZ8863, 4)),
	IOMUX_PAD_CTRL(ENET2_RX_ER__GPIO2_IO15, PULL_GP(STRAP2_KSZ8863, 5)),
	IOMUX_PAD_CTRL(UART5_TX_DATA__GPIO1_IO30, PULL_GP(STRAP2_KSZ8863, 6)),
	IOMUX_PAD_CTRL(UART5_RX_DATA__GPIO1_IO31, PULL_GP(STRAP2_KSZ8863, 7)),
	IOMUX_PAD_CTRL(ENET2_TX_DATA0__GPIO2_IO11, PULL_GP(STRAP2_KSZ8863, 8)),
	IOMUX_PAD_CTRL(ENET2_TX_DATA1__GPIO2_IO12, PULL_GP(STRAP2_KSZ8863, 9)),
	IOMUX_PAD_CTRL(UART4_TX_DATA__GPIO1_IO28, PULL_GP(STRAP2_KSZ8863, 10)),
	IOMUX_PAD_CTRL(UART4_RX_DATA__GPIO1_IO29, PULL_GP(STRAP2_KSZ8863, 11)),
};

static const iomux_v3_cfg_t enet2_ksz8863_pads[] = {
	IOMUX_PAD_CTRL(ENET2_RX_DATA0__ENET2_RDATA00, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET2_RX_DATA1__ENET2_RDATA01, PAD_CTRL_ENET_RX),
//	IOMUX_PAD_CTRL(UART3_TX_DATA__ENET2_RDATA02, PAD_CTRL_ENET_RX),
//	IOMUX_PAD_CTRL(UART3_RX_DATA__ENET2_RDATA03, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET2_RX_EN__ENET2_RX_EN, PAD_CTRL_ENET_RX),
//	IOMUX_PAD_CTRL(UART3_CTS_B__ENET2_RX_CLK, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET2_RX_ER__ENET2_RX_ER, PAD_CTRL_ENET_RX),
//	IOMUX_PAD_CTRL(UART5_TX_DATA__ENET2_CRS, PAD_CTRL_ENET_RX),
//	IOMUX_PAD_CTRL(UART5_RX_DATA__ENET2_COL, PAD_CTRL_ENET_RX),
	IOMUX_PAD_CTRL(ENET2_TX_DATA0__ENET2_TDATA00, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(ENET2_TX_DATA1__ENET2_TDATA01, PAD_CTRL_ENET_TX),
//	IOMUX_PAD_CTRL(UART4_TX_DATA__ENET2_TDATA02, PAD_CTRL_ENET_TX),
//	IOMUX_PAD_CTRL(UART4_RX_DATA__ENET2_TDATA03, PAD_CTRL_ENET_TX),
};
#endif
#endif
