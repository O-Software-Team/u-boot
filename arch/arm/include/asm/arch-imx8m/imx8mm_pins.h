/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2018-2019 NXP
 */

#ifndef __ASM_ARCH_IMX8MM_PINS_H__
#define __ASM_ARCH_IMX8MM_PINS_H__

#include <asm/mach-imx/iomux-v3.h>

enum {
	IMX8MM_PAD_GPIO1_IO00__GPIO1_IO0                               =  IOMUX_PAD(0x0290, 0x0028, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO00__CCM_ENET_PHY_REF_CLK_ROOT               =  IOMUX_PAD(0x0290, 0x0028, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO00__XTALOSC_REF_CLK_32K                     =  IOMUX_PAD(0x0290, 0x0028, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO00__CCM_EXT_CLK1                            =  IOMUX_PAD(0x0290, 0x0028, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO01__GPIO1_IO1                               =  IOMUX_PAD(0x0294, 0x002C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO01__PWM1_OUT                                =  IOMUX_PAD(0x0294, 0x002C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO01__XTALOSC_REF_CLK_24M                     =  IOMUX_PAD(0x0294, 0x002C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO01__CCM_EXT_CLK2                            =  IOMUX_PAD(0x0294, 0x002C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO02__GPIO1_IO2                               =  IOMUX_PAD(0x0298, 0x0030, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO02__WDOG1_WDOG_B                            =  IOMUX_PAD(0x0298, 0x0030, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO02__WDOG1_WDOG_ANY                          =  IOMUX_PAD(0x0298, 0x0030, 5, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO03__GPIO1_IO3                               =  IOMUX_PAD(0x029C, 0x0034, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO03__USDHC1_VSELECT                          =  IOMUX_PAD(0x029C, 0x0034, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO03__SDMA1_EXT_EVENT0                        =  IOMUX_PAD(0x029C, 0x0034, 5, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO04__GPIO1_IO4                               =  IOMUX_PAD(0x02A0, 0x0038, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO04__USDHC2_VSELECT                          =  IOMUX_PAD(0x02A0, 0x0038, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO04__SDMA1_EXT_EVENT1                        =  IOMUX_PAD(0x02A0, 0x0038, 5, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO05__GPIO1_IO5                               =  IOMUX_PAD(0x02A4, 0x003C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO05__ARM_PLATFORM_M4_NMI                     =  IOMUX_PAD(0x02A4, 0x003C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO05__CCM_PMIC_READY                          =  IOMUX_PAD(0x02A4, 0x003C, 5, 0x04BC, 0, 0),
	IMX8MM_PAD_GPIO1_IO05__SRC_INT_BOOT                            =  IOMUX_PAD(0x02A4, 0x003C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO06__GPIO1_IO6                               =  IOMUX_PAD(0x02A8, 0x0040, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO06__ENET1_MDC                               =  IOMUX_PAD(0x02A8, 0x0040, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO06__USDHC1_CD_B                             =  IOMUX_PAD(0x02A8, 0x0040, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO06__CCM_EXT_CLK3                            =  IOMUX_PAD(0x02A8, 0x0040, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO07__GPIO1_IO7                               =  IOMUX_PAD(0x02AC, 0x0044, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO07__ENET1_MDIO                              =  IOMUX_PAD(0x02AC, 0x0044, 1, 0x04C0, 0, 0),
	IMX8MM_PAD_GPIO1_IO07__USDHC1_WP                               =  IOMUX_PAD(0x02AC, 0x0044, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO07__CCM_EXT_CLK4                            =  IOMUX_PAD(0x02AC, 0x0044, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO08__GPIO1_IO8                               =  IOMUX_PAD(0x02B0, 0x0048, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO08__ENET1_1588_EVENT0_IN                    =  IOMUX_PAD(0x02B0, 0x0048, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO08__USDHC2_RESET_B                          =  IOMUX_PAD(0x02B0, 0x0048, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO08__CCM_WAIT                                =  IOMUX_PAD(0x02B0, 0x0048, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO09__GPIO1_IO9                               =  IOMUX_PAD(0x02B4, 0x004C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO09__ENET1_1588_EVENT0_OUT                   =  IOMUX_PAD(0x02B4, 0x004C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO09__USDHC3_RESET_B                          =  IOMUX_PAD(0x02B4, 0x004C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO09__SDMA2_EXT_EVENT0                        =  IOMUX_PAD(0x02B4, 0x004C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO09__CCM_STOP                                =  IOMUX_PAD(0x02B4, 0x004C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO10__GPIO1_IO10                              =  IOMUX_PAD(0x02B8, 0x0050, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO10__USB1_OTG_ID                             =  IOMUX_PAD(0x02B8, 0x0050, 1, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO11__GPIO1_IO11                              =  IOMUX_PAD(0x02BC, 0x0054, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO11__USB2_OTG_ID                             =  IOMUX_PAD(0x02BC, 0x0054, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO11__USDHC3_VSELECT                          =  IOMUX_PAD(0x02BC, 0x0054, 4, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO11__CCM_PMIC_READY                          =  IOMUX_PAD(0x02BC, 0x0054, 5, 0x04BC, 1, 0),
	IMX8MM_PAD_GPIO1_IO11__CCM_OUT0                                =  IOMUX_PAD(0x02BC, 0x0054, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO12__GPIO1_IO12                              =  IOMUX_PAD(0x02C0, 0x0058, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO12__USB1_OTG_PWR                            =  IOMUX_PAD(0x02C0, 0x0058, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO12__SDMA2_EXT_EVENT1                        =  IOMUX_PAD(0x02C0, 0x0058, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO12__CCM_OUT1                                =  IOMUX_PAD(0x02C0, 0x0058, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO13__GPIO1_IO13                              =  IOMUX_PAD(0x02C4, 0x005C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO13__USB1_OTG_OC                             =  IOMUX_PAD(0x02C4, 0x005C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO13__PWM2_OUT                                =  IOMUX_PAD(0x02C4, 0x005C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO13__CCM_OUT2                                =  IOMUX_PAD(0x02C4, 0x005C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO14__GPIO1_IO14                              =  IOMUX_PAD(0x02C8, 0x0060, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO14__USB2_OTG_PWR                            =  IOMUX_PAD(0x02C8, 0x0060, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO14__USDHC3_CD_B                             =  IOMUX_PAD(0x02C8, 0x0060, 4, 0x0544, 2, 0),
	IMX8MM_PAD_GPIO1_IO14__PWM3_OUT                                =  IOMUX_PAD(0x02C8, 0x0060, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO14__CCM_CLKO1                               =  IOMUX_PAD(0x02C8, 0x0060, 6, 0x0000, 0, 0),

	IMX8MM_PAD_GPIO1_IO15__GPIO1_IO15                              =  IOMUX_PAD(0x02CC, 0x0064, 0, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO15__USB2_OTG_OC                             =  IOMUX_PAD(0x02CC, 0x0064, 1, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO15__USDHC3_WP                               =  IOMUX_PAD(0x02CC, 0x0064, 4, 0x0548, 2, 0),
	IMX8MM_PAD_GPIO1_IO15__PWM4_OUT                                =  IOMUX_PAD(0x02CC, 0x0064, 5, 0x0000, 0, 0),
	IMX8MM_PAD_GPIO1_IO15__CCM_CLKO2                               =  IOMUX_PAD(0x02CC, 0x0064, 6, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_MDC__ENET1_MDC                                 =  IOMUX_PAD(0x02D0, 0x0068, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_MDC__GPIO1_IO16                                =  IOMUX_PAD(0x02D0, 0x0068, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_MDIO__ENET1_MDIO                               =  IOMUX_PAD(0x02D4, 0x006C, 0, 0x04C0, 1, 0),
	IMX8MM_PAD_ENET_MDIO__GPIO1_IO17                               =  IOMUX_PAD(0x02D4, 0x006C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TD3__ENET1_RGMII_TD3                           =  IOMUX_PAD(0x02D8, 0x0070, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD3__GPIO1_IO18                                =  IOMUX_PAD(0x02D8, 0x0070, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TD2__ENET1_RGMII_TD2                           =  IOMUX_PAD(0x02DC, 0x0074, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD2__ENET1_TX_CLK                              =  IOMUX_PAD(0x02DC, 0x0074, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD2__CCM_ENET_REF_CLK_ROOT                     =  IOMUX_PAD(0x02DC, 0x0074, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD2__GPIO1_IO19                                =  IOMUX_PAD(0x02DC, 0x0074, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TD1__ENET1_RGMII_TD1                           =  IOMUX_PAD(0x02E0, 0x0078, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD1__GPIO1_IO20                                =  IOMUX_PAD(0x02E0, 0x0078, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TD0__ENET1_RGMII_TD0                           =  IOMUX_PAD(0x02E4, 0x007C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TD0__GPIO1_IO21                                =  IOMUX_PAD(0x02E4, 0x007C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TX_CTL__ENET1_RGMII_TX_CTL                     =  IOMUX_PAD(0x02E8, 0x0080, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TX_CTL__GPIO1_IO22                             =  IOMUX_PAD(0x02E8, 0x0080, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_TXC__ENET1_RGMII_TXC                           =  IOMUX_PAD(0x02EC, 0x0084, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TXC__ENET1_TX_ER                               =  IOMUX_PAD(0x02EC, 0x0084, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_TXC__GPIO1_IO23                                =  IOMUX_PAD(0x02EC, 0x0084, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RX_CTL__ENET1_RGMII_RX_CTL                     =  IOMUX_PAD(0x02F0, 0x0088, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RX_CTL__GPIO1_IO24                             =  IOMUX_PAD(0x02F0, 0x0088, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RXC__ENET1_RGMII_RXC                           =  IOMUX_PAD(0x02F4, 0x008C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RXC__ENET1_RX_ER                               =  IOMUX_PAD(0x02F4, 0x008C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RXC__GPIO1_IO25                                =  IOMUX_PAD(0x02F4, 0x008C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RD0__ENET1_RGMII_RD0                           =  IOMUX_PAD(0x02F8, 0x0090, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RD0__GPIO1_IO26                                =  IOMUX_PAD(0x02F8, 0x0090, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RD1__ENET1_RGMII_RD1                           =  IOMUX_PAD(0x02FC, 0x0094, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RD1__GPIO1_IO27                                =  IOMUX_PAD(0x02FC, 0x0094, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RD2__ENET1_RGMII_RD2                           =  IOMUX_PAD(0x0300, 0x0098, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RD2__GPIO1_IO28                                =  IOMUX_PAD(0x0300, 0x0098, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ENET_RD3__ENET1_RGMII_RD3                           =  IOMUX_PAD(0x0304, 0x009C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ENET_RD3__GPIO1_IO29                                =  IOMUX_PAD(0x0304, 0x009C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_CLK__USDHC1_CLK                                 =  IOMUX_PAD(0x0308, 0x00A0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_CLK__GPIO2_IO0                                  =  IOMUX_PAD(0x0308, 0x00A0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_CMD__USDHC1_CMD                                 =  IOMUX_PAD(0x030C, 0x00A4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_CMD__GPIO2_IO1                                  =  IOMUX_PAD(0x030C, 0x00A4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA0__USDHC1_DATA0                             =  IOMUX_PAD(0x0310, 0x00A8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA0__GPIO2_IO2                                =  IOMUX_PAD(0x0310, 0x00A8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA1__USDHC1_DATA1                             =  IOMUX_PAD(0x0314, 0x00AC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA1__GPIO2_IO3                                =  IOMUX_PAD(0x0314, 0x00AC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA2__USDHC1_DATA2                             =  IOMUX_PAD(0x0318, 0x00B0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA2__GPIO2_IO4                                =  IOMUX_PAD(0x0318, 0x00B0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA3__USDHC1_DATA3                             =  IOMUX_PAD(0x031C, 0x00B4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA3__GPIO2_IO5                                =  IOMUX_PAD(0x031C, 0x00B4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA4__USDHC1_DATA4                             =  IOMUX_PAD(0x0320, 0x00B8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA4__GPIO2_IO6                                =  IOMUX_PAD(0x0320, 0x00B8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA5__USDHC1_DATA5                             =  IOMUX_PAD(0x0324, 0x00BC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA5__GPIO2_IO7                                =  IOMUX_PAD(0x0324, 0x00BC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA6__USDHC1_DATA6                             =  IOMUX_PAD(0x0328, 0x00C0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA6__GPIO2_IO8                                =  IOMUX_PAD(0x0328, 0x00C0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_DATA7__USDHC1_DATA7                             =  IOMUX_PAD(0x032C, 0x00C4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_DATA7__GPIO2_IO9                                =  IOMUX_PAD(0x032C, 0x00C4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_RESET_B__USDHC1_RESET_B                         =  IOMUX_PAD(0x0330, 0x00C8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_RESET_B__GPIO2_IO10                             =  IOMUX_PAD(0x0330, 0x00C8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD1_STROBE__USDHC1_STROBE                           =  IOMUX_PAD(0x0334, 0x00CC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD1_STROBE__GPIO2_IO11                              =  IOMUX_PAD(0x0334, 0x00CC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_CD_B__USDHC2_CD_B                               =  IOMUX_PAD(0x0338, 0x00D0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_CD_B__GPIO2_IO12                                =  IOMUX_PAD(0x0338, 0x00D0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_CLK__USDHC2_CLK                                 =  IOMUX_PAD(0x033C, 0x00D4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_CLK__GPIO2_IO13                                 =  IOMUX_PAD(0x033C, 0x00D4, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_CLK__CCM_OBSERVE0                               =  IOMUX_PAD(0x033C, 0x00D4, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_CMD__USDHC2_CMD                                 =  IOMUX_PAD(0x0340, 0x00D8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_CMD__GPIO2_IO14                                 =  IOMUX_PAD(0x0340, 0x00D8, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_CMD__CCM_OBSERVE1                               =  IOMUX_PAD(0x0340, 0x00D8, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_DATA0__USDHC2_DATA0                             =  IOMUX_PAD(0x0344, 0x00DC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA0__GPIO2_IO15                               =  IOMUX_PAD(0x0344, 0x00DC, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA0__CCM_OBSERVE2                             =  IOMUX_PAD(0x0344, 0x00DC, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_DATA1__USDHC2_DATA1                             =  IOMUX_PAD(0x0348, 0x00E0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA1__GPIO2_IO16                               =  IOMUX_PAD(0x0348, 0x00E0, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA1__CCM_WAIT                                 =  IOMUX_PAD(0x0348, 0x00E0, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_DATA2__USDHC2_DATA2                             =  IOMUX_PAD(0x034C, 0x00E4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA2__GPIO2_IO17                               =  IOMUX_PAD(0x034C, 0x00E4, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA2__CCM_STOP                                 =  IOMUX_PAD(0x034C, 0x00E4, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_DATA3__USDHC2_DATA3                             =  IOMUX_PAD(0x0350, 0x00E8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA3__GPIO2_IO18                               =  IOMUX_PAD(0x0350, 0x00E8, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_DATA3__SRC_EARLY_RESET                          =  IOMUX_PAD(0x0350, 0x00E8, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_RESET_B__USDHC2_RESET_B                         =  IOMUX_PAD(0x0354, 0x00EC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_RESET_B__GPIO2_IO19                             =  IOMUX_PAD(0x0354, 0x00EC, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_RESET_B__SRC_SYSTEM_RESET                       =  IOMUX_PAD(0x0354, 0x00EC, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SD2_WP__USDHC2_WP                                   =  IOMUX_PAD(0x0358, 0x00F0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SD2_WP__GPIO2_IO20                                  =  IOMUX_PAD(0x0358, 0x00F0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_ALE__RAWNAND_ALE                               =  IOMUX_PAD(0x035C, 0x00F4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_ALE__QSPI_A_SCLK                               =  IOMUX_PAD(0x035C, 0x00F4, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_ALE__GPIO3_IO0                                 =  IOMUX_PAD(0x035C, 0x00F4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_CE0_B__RAWNAND_CE0_B                           =  IOMUX_PAD(0x0360, 0x00F8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE0_B__QSPI_A_SS0_B                            =  IOMUX_PAD(0x0360, 0x00F8, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE0_B__GPIO3_IO1                               =  IOMUX_PAD(0x0360, 0x00F8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_CE1_B__RAWNAND_CE1_B                           =  IOMUX_PAD(0x0364, 0x00FC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE1_B__QSPI_A_SS1_B                            =  IOMUX_PAD(0x0364, 0x00FC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE1_B__USDHC3_STROBE                           =  IOMUX_PAD(0x0364, 0x00FC, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE1_B__GPIO3_IO2                               =  IOMUX_PAD(0x0364, 0x00FC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_CE2_B__RAWNAND_CE2_B                           =  IOMUX_PAD(0x0368, 0x0100, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE2_B__QSPI_B_SS0_B                            =  IOMUX_PAD(0x0368, 0x0100, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE2_B__USDHC3_DATA5                            =  IOMUX_PAD(0x0368, 0x0100, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE2_B__GPIO3_IO3                               =  IOMUX_PAD(0x0368, 0x0100, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_CE3_B__RAWNAND_CE3_B                           =  IOMUX_PAD(0x036C, 0x0104, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE3_B__QSPI_B_SS1_B                            =  IOMUX_PAD(0x036C, 0x0104, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE3_B__USDHC3_DATA6                            =  IOMUX_PAD(0x036C, 0x0104, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CE3_B__GPIO3_IO4                               =  IOMUX_PAD(0x036C, 0x0104, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_CLE__RAWNAND_CLE                               =  IOMUX_PAD(0x0370, 0x0108, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CLE__QSPI_B_SCLK                               =  IOMUX_PAD(0x0370, 0x0108, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CLE__USDHC3_DATA7                              =  IOMUX_PAD(0x0370, 0x0108, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_CLE__GPIO3_IO5                                 =  IOMUX_PAD(0x0370, 0x0108, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA00__RAWNAND_DATA00                         =  IOMUX_PAD(0x0374, 0x010C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA00__QSPI_A_DATA0                           =  IOMUX_PAD(0x0374, 0x010C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA00__GPIO3_IO6                              =  IOMUX_PAD(0x0374, 0x010C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA01__RAWNAND_DATA01                         =  IOMUX_PAD(0x0378, 0x0110, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA01__QSPI_A_DATA1                           =  IOMUX_PAD(0x0378, 0x0110, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA01__GPIO3_IO7                              =  IOMUX_PAD(0x0378, 0x0110, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA02__RAWNAND_DATA02                         =  IOMUX_PAD(0x037C, 0x0114, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA02__QSPI_A_DATA2                           =  IOMUX_PAD(0x037C, 0x0114, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA02__USDHC3_CD_B                            =  IOMUX_PAD(0x037C, 0x0114, 2, 0x0544, 0, 0),
	IMX8MM_PAD_NAND_DATA02__GPIO3_IO8                              =  IOMUX_PAD(0x037C, 0x0114, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA03__RAWNAND_DATA03                         =  IOMUX_PAD(0x0380, 0x0118, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA03__QSPI_A_DATA3                           =  IOMUX_PAD(0x0380, 0x0118, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA03__USDHC3_WP                              =  IOMUX_PAD(0x0380, 0x0118, 2, 0x0548, 0, 0),
	IMX8MM_PAD_NAND_DATA03__GPIO3_IO9                              =  IOMUX_PAD(0x0380, 0x0118, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA04__RAWNAND_DATA04                         =  IOMUX_PAD(0x0384, 0x011C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA04__QSPI_B_DATA0                           =  IOMUX_PAD(0x0384, 0x011C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA04__USDHC3_DATA0                           =  IOMUX_PAD(0x0384, 0x011C, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA04__GPIO3_IO10                             =  IOMUX_PAD(0x0384, 0x011C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA05__RAWNAND_DATA05                         =  IOMUX_PAD(0x0388, 0x0120, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA05__QSPI_B_DATA1                           =  IOMUX_PAD(0x0388, 0x0120, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA05__USDHC3_DATA1                           =  IOMUX_PAD(0x0388, 0x0120, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA05__GPIO3_IO11                             =  IOMUX_PAD(0x0388, 0x0120, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA06__RAWNAND_DATA06                         =  IOMUX_PAD(0x038C, 0x0124, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA06__QSPI_B_DATA2                           =  IOMUX_PAD(0x038C, 0x0124, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA06__USDHC3_DATA2                           =  IOMUX_PAD(0x038C, 0x0124, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA06__GPIO3_IO12                             =  IOMUX_PAD(0x038C, 0x0124, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DATA07__RAWNAND_DATA07                         =  IOMUX_PAD(0x0390, 0x0128, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA07__QSPI_B_DATA3                           =  IOMUX_PAD(0x0390, 0x0128, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA07__USDHC3_DATA3                           =  IOMUX_PAD(0x0390, 0x0128, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DATA07__GPIO3_IO13                             =  IOMUX_PAD(0x0390, 0x0128, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_DQS__RAWNAND_DQS                               =  IOMUX_PAD(0x0394, 0x012C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DQS__QSPI_A_DQS                                =  IOMUX_PAD(0x0394, 0x012C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_DQS__GPIO3_IO14                                =  IOMUX_PAD(0x0394, 0x012C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_RE_B__RAWNAND_RE_B                             =  IOMUX_PAD(0x0398, 0x0130, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_RE_B__QSPI_B_DQS                               =  IOMUX_PAD(0x0398, 0x0130, 1, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_RE_B__USDHC3_DATA4                             =  IOMUX_PAD(0x0398, 0x0130, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_RE_B__GPIO3_IO15                               =  IOMUX_PAD(0x0398, 0x0130, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_READY_B__RAWNAND_READY_B                       =  IOMUX_PAD(0x039C, 0x0134, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_READY_B__USDHC3_RESET_B                        =  IOMUX_PAD(0x039C, 0x0134, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_READY_B__GPIO3_IO16                            =  IOMUX_PAD(0x039C, 0x0134, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_WE_B__RAWNAND_WE_B                             =  IOMUX_PAD(0x03A0, 0x0138, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_WE_B__USDHC3_CLK                               =  IOMUX_PAD(0x03A0, 0x0138, 2 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_WE_B__GPIO3_IO17                               =  IOMUX_PAD(0x03A0, 0x0138, 5, 0x0000, 0, 0),

	IMX8MM_PAD_NAND_WP_B__RAWNAND_WP_B                             =  IOMUX_PAD(0x03A4, 0x013C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_WP_B__USDHC3_CMD                               =  IOMUX_PAD(0x03A4, 0x013C, 2, 0x0000, 0, 0),
	IMX8MM_PAD_NAND_WP_B__GPIO3_IO18                               =  IOMUX_PAD(0x03A4, 0x013C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXFS__SAI5_RX_SYNC                             =  IOMUX_PAD(0x03A8, 0x0140, 0, 0x04E4, 0, 0),
	IMX8MM_PAD_SAI5_RXFS__SAI1_TX_DATA0                            =  IOMUX_PAD(0x03A8, 0x0140, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXFS__GPIO3_IO19                               =  IOMUX_PAD(0x03A8, 0x0140, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXC__SAI5_RX_BCLK                              =  IOMUX_PAD(0x03AC, 0x0144, 0, 0x04D0, 0, 0),
	IMX8MM_PAD_SAI5_RXC__SAI1_TX_DATA1                             =  IOMUX_PAD(0x03AC, 0x0144, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXC__PDM_CLK                                   =  IOMUX_PAD(0x03AC, 0x0144, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXC__GPIO3_IO20                                =  IOMUX_PAD(0x03AC, 0x0144, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXD0__SAI5_RX_DATA0                            =  IOMUX_PAD(0x03B0, 0x0148, 0, 0x04D4, 0, 0),
	IMX8MM_PAD_SAI5_RXD0__SAI1_TX_DATA2                            =  IOMUX_PAD(0x03B0, 0x0148, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXD0__PDM_BIT_STREAM0                          =  IOMUX_PAD(0x03B0, 0x0148, 4, 0x0534, 0, 0),
	IMX8MM_PAD_SAI5_RXD0__GPIO3_IO21                               =  IOMUX_PAD(0x03B0, 0x0148, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXD1__SAI5_RX_DATA1                            =  IOMUX_PAD(0x03B4, 0x014C, 0, 0x04D8, 0, 0),
	IMX8MM_PAD_SAI5_RXD1__SAI1_TX_DATA3                            =  IOMUX_PAD(0x03B4, 0x014C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXD1__SAI1_TX_SYNC                             =  IOMUX_PAD(0x03B4, 0x014C, 2, 0x04CC, 0, 0),
	IMX8MM_PAD_SAI5_RXD1__SAI5_TX_SYNC                             =  IOMUX_PAD(0x03B4, 0x014C, 3, 0x04EC, 0, 0),
	IMX8MM_PAD_SAI5_RXD1__PDM_BIT_STREAM1                          =  IOMUX_PAD(0x03B4, 0x014C, 4, 0x0538, 0, 0),
	IMX8MM_PAD_SAI5_RXD1__GPIO3_IO22                               =  IOMUX_PAD(0x03B4, 0x014C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXD2__SAI5_RX_DATA2                            =  IOMUX_PAD(0x03B8, 0x0150, 0, 0x04DC, 0, 0),
	IMX8MM_PAD_SAI5_RXD2__SAI1_TX_DATA4                            =  IOMUX_PAD(0x03B8, 0x0150, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXD2__SAI1_TX_SYNC                             =  IOMUX_PAD(0x03B8, 0x0150, 2, 0x04CC, 1, 0),
	IMX8MM_PAD_SAI5_RXD2__SAI5_TX_BCLK                             =  IOMUX_PAD(0x03B8, 0x0150, 3, 0x04E8, 0, 0),
	IMX8MM_PAD_SAI5_RXD2__PDM_BIT_STREAM2                          =  IOMUX_PAD(0x03B8, 0x0150, 4, 0x053C, 0, 0),
	IMX8MM_PAD_SAI5_RXD2__GPIO3_IO23                               =  IOMUX_PAD(0x03B8, 0x0150, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_RXD3__SAI5_RX_DATA3                            =  IOMUX_PAD(0x03BC, 0x0154, 0, 0x04E0, 0, 0),
	IMX8MM_PAD_SAI5_RXD3__SAI1_TX_DATA5                            =  IOMUX_PAD(0x03BC, 0x0154, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXD3__SAI1_TX_SYNC                             =  IOMUX_PAD(0x03BC, 0x0154, 2, 0x04CC, 2, 0),
	IMX8MM_PAD_SAI5_RXD3__SAI5_TX_DATA0                            =  IOMUX_PAD(0x03BC, 0x0154, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_RXD3__PDM_BIT_STREAM3                          =  IOMUX_PAD(0x03BC, 0x0154, 4, 0x0540, 0, 0),
	IMX8MM_PAD_SAI5_RXD3__GPIO3_IO24                               =  IOMUX_PAD(0x03BC, 0x0154, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI5_MCLK__SAI5_MCLK                                =  IOMUX_PAD(0x03C0, 0x0158, 0, 0x052C, 0, 0),
	IMX8MM_PAD_SAI5_MCLK__SAI1_TX_BCLK                             =  IOMUX_PAD(0x03C0, 0x0158, 1, 0x04C8, 0, 0),
	IMX8MM_PAD_SAI5_MCLK__GPIO3_IO25                               =  IOMUX_PAD(0x03C0, 0x0158, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI5_MCLK__SRC_TESTER_ACK                           =  IOMUX_PAD(0x03C0, 0x0158, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXFS__SAI1_RX_SYNC                             =  IOMUX_PAD(0x03C4, 0x015C, 0, 0x04C4, 0, 0),
	IMX8MM_PAD_SAI1_RXFS__SAI5_RX_SYNC                             =  IOMUX_PAD(0x03C4, 0x015C, 1, 0x04E4, 1, 0),
	IMX8MM_PAD_SAI1_RXFS__ARM_PLATFORM_TRACE_CLK                   =  IOMUX_PAD(0x03C4, 0x015C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXFS__GPIO4_IO0                                =  IOMUX_PAD(0x03C4, 0x015C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXC__SAI1_RX_BCLK                              =  IOMUX_PAD(0x03C8, 0x0160, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXC__SAI5_RX_BCLK                              =  IOMUX_PAD(0x03C8, 0x0160, 1, 0x04D0, 1, 0),
	IMX8MM_PAD_SAI1_RXC__ARM_PLATFORM_TRACE_CTL                    =  IOMUX_PAD(0x03C8, 0x0160, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXC__GPIO4_IO1                                 =  IOMUX_PAD(0x03C8, 0x0160, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD0__SAI1_RX_DATA0                            =  IOMUX_PAD(0x03CC, 0x0164, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD0__SAI5_RX_DATA0                            =  IOMUX_PAD(0x03CC, 0x0164, 1, 0x04D4, 1, 0),
	IMX8MM_PAD_SAI1_RXD0__SAI1_TX_DATA1                            =  IOMUX_PAD(0x03CC, 0x0164, 2, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD0__PDM_BIT_STREAM0                          =  IOMUX_PAD(0x03CC, 0x0164, 3, 0x0534, 1, 0),
	IMX8MM_PAD_SAI1_RXD0__ARM_PLATFORM_TRACE0                      =  IOMUX_PAD(0x03CC, 0x0164, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD0__GPIO4_IO2                                =  IOMUX_PAD(0x03CC, 0x0164, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD0__SRC_BOOT_CFG0                            =  IOMUX_PAD(0x03CC, 0x0164, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD1__SAI1_RX_DATA1                            =  IOMUX_PAD(0x03D0, 0x0168, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD1__SAI5_RX_DATA1                            =  IOMUX_PAD(0x03D0, 0x0168, 1, 0x04D8, 1, 0),
	IMX8MM_PAD_SAI1_RXD1__PDM_BIT_STREAM1                          =  IOMUX_PAD(0x03D0, 0x0168, 3, 0x0538, 1, 0),
	IMX8MM_PAD_SAI1_RXD1__ARM_PLATFORM_TRACE1                      =  IOMUX_PAD(0x03D0, 0x0168, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD1__GPIO4_IO3                                =  IOMUX_PAD(0x03D0, 0x0168, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD1__SRC_BOOT_CFG1                            =  IOMUX_PAD(0x03D0, 0x0168, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD2__SAI1_RX_DATA2                            =  IOMUX_PAD(0x03D4, 0x016C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD2__SAI5_RX_DATA2                            =  IOMUX_PAD(0x03D4, 0x016C, 1, 0x04DC, 1, 0),
	IMX8MM_PAD_SAI1_RXD2__PDM_BIT_STREAM2                          =  IOMUX_PAD(0x03D4, 0x016C, 3, 0x053C, 1, 0),
	IMX8MM_PAD_SAI1_RXD2__ARM_PLATFORM_TRACE2                      =  IOMUX_PAD(0x03D4, 0x016C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD2__GPIO4_IO4                                =  IOMUX_PAD(0x03D4, 0x016C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD2__SRC_BOOT_CFG2                            =  IOMUX_PAD(0x03D4, 0x016C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD3__SAI1_RX_DATA3                            =  IOMUX_PAD(0x03D8, 0x0170, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD3__SAI5_RX_DATA3                            =  IOMUX_PAD(0x03D8, 0x0170, 1, 0x04E0, 1, 0),
	IMX8MM_PAD_SAI1_RXD3__PDM_BIT_STREAM3                          =  IOMUX_PAD(0x03D8, 0x0170, 3, 0x0540, 1, 0),
	IMX8MM_PAD_SAI1_RXD3__ARM_PLATFORM_TRACE3                      =  IOMUX_PAD(0x03D8, 0x0170, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD3__GPIO4_IO5                                =  IOMUX_PAD(0x03D8, 0x0170, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD3__SRC_BOOT_CFG3                            =  IOMUX_PAD(0x03D8, 0x0170, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD4__SAI1_RX_DATA4                            =  IOMUX_PAD(0x03DC, 0x0174, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD4__SAI6_TX_BCLK                             =  IOMUX_PAD(0x03DC, 0x0174, 1, 0x051C, 0, 0),
	IMX8MM_PAD_SAI1_RXD4__SAI6_RX_BCLK                             =  IOMUX_PAD(0x03DC, 0x0174, 2, 0x0510, 0, 0),
	IMX8MM_PAD_SAI1_RXD4__ARM_PLATFORM_TRACE4                      =  IOMUX_PAD(0x03DC, 0x0174, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD4__GPIO4_IO6                                =  IOMUX_PAD(0x03DC, 0x0174, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD4__SRC_BOOT_CFG4                            =  IOMUX_PAD(0x03DC, 0x0174, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD5__SAI1_RX_DATA5                            =  IOMUX_PAD(0x03E0, 0x0178, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD5__SAI6_TX_DATA0                            =  IOMUX_PAD(0x03E0, 0x0178, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD5__SAI6_RX_DATA0                            =  IOMUX_PAD(0x03E0, 0x0178, 2, 0x0514, 0, 0),
	IMX8MM_PAD_SAI1_RXD5__SAI1_RX_SYNC                             =  IOMUX_PAD(0x03E0, 0x0178, 3, 0x04C4, 1, 0),
	IMX8MM_PAD_SAI1_RXD5__ARM_PLATFORM_TRACE5                      =  IOMUX_PAD(0x03E0, 0x0178, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD5__GPIO4_IO7                                =  IOMUX_PAD(0x03E0, 0x0178, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD5__SRC_BOOT_CFG5                            =  IOMUX_PAD(0x03E0, 0x0178, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD6__SAI1_RX_DATA6                            =  IOMUX_PAD(0x03E4, 0x017C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD6__SAI6_TX_SYNC                             =  IOMUX_PAD(0x03E4, 0x017C, 1, 0x0520, 0, 0),
	IMX8MM_PAD_SAI1_RXD6__SAI6_RX_SYNC                             =  IOMUX_PAD(0x03E4, 0x017C, 2, 0x0518, 0, 0),
	IMX8MM_PAD_SAI1_RXD6__ARM_PLATFORM_TRACE6                      =  IOMUX_PAD(0x03E4, 0x017C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD6__GPIO4_IO8                                =  IOMUX_PAD(0x03E4, 0x017C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD6__SRC_BOOT_CFG6                            =  IOMUX_PAD(0x03E4, 0x017C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_RXD7__SAI1_RX_DATA7                            =  IOMUX_PAD(0x03E8, 0x0180, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD7__SAI6_MCLK                                =  IOMUX_PAD(0x03E8, 0x0180, 1, 0x0530, 0, 0),
	IMX8MM_PAD_SAI1_RXD7__SAI1_TX_SYNC                             =  IOMUX_PAD(0x03E8, 0x0180, 2, 0x04CC, 4, 0),
	IMX8MM_PAD_SAI1_RXD7__SAI1_TX_DATA4                            =  IOMUX_PAD(0x03E8, 0x0180, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD7__ARM_PLATFORM_TRACE7                      =  IOMUX_PAD(0x03E8, 0x0180, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD7__GPIO4_IO9                                =  IOMUX_PAD(0x03E8, 0x0180, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_RXD7__SRC_BOOT_CFG7                            =  IOMUX_PAD(0x03E8, 0x0180, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXFS__SAI1_TX_SYNC                             =  IOMUX_PAD(0x03EC, 0x0184, 0, 0x04CC, 3, 0),
	IMX8MM_PAD_SAI1_TXFS__SAI5_TX_SYNC                             =  IOMUX_PAD(0x03EC, 0x0184, 1, 0x04EC, 1, 0),
	IMX8MM_PAD_SAI1_TXFS__ARM_PLATFORM_EVENTO                      =  IOMUX_PAD(0x03EC, 0x0184, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXFS__GPIO4_IO10                               =  IOMUX_PAD(0x03EC, 0x0184, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXC__SAI1_TX_BCLK                              =  IOMUX_PAD(0x03F0, 0x0188, 0, 0x04C8, 1, 0),
	IMX8MM_PAD_SAI1_TXC__SAI5_TX_BCLK                              =  IOMUX_PAD(0x03F0, 0x0188, 1, 0x04E8, 1, 0),
	IMX8MM_PAD_SAI1_TXC__ARM_PLATFORM_EVENTI                       =  IOMUX_PAD(0x03F0, 0x0188, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXC__GPIO4_IO11                                =  IOMUX_PAD(0x03F0, 0x0188, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD0__SAI1_TX_DATA0                            =  IOMUX_PAD(0x03F4, 0x018C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD0__SAI5_TX_DATA0                            =  IOMUX_PAD(0x03F4, 0x018C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD0__ARM_PLATFORM_TRACE8                      =  IOMUX_PAD(0x03F4, 0x018C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD0__GPIO4_IO12                               =  IOMUX_PAD(0x03F4, 0x018C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD0__SRC_BOOT_CFG8                            =  IOMUX_PAD(0x03F4, 0x018C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD1__SAI1_TX_DATA1                            =  IOMUX_PAD(0x03F8, 0x0190, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD1__SAI5_TX_DATA1                            =  IOMUX_PAD(0x03F8, 0x0190, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD1__ARM_PLATFORM_TRACE9                      =  IOMUX_PAD(0x03F8, 0x0190, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD1__GPIO4_IO13                               =  IOMUX_PAD(0x03F8, 0x0190, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD1__SRC_BOOT_CFG9                            =  IOMUX_PAD(0x03F8, 0x0190, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD2__SAI1_TX_DATA2                            =  IOMUX_PAD(0x03FC, 0x0194, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD2__SAI5_TX_DATA2                            =  IOMUX_PAD(0x03FC, 0x0194, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD2__ARM_PLATFORM_TRACE10                     =  IOMUX_PAD(0x03FC, 0x0194, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD2__GPIO4_IO14                               =  IOMUX_PAD(0x03FC, 0x0194, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD2__SRC_BOOT_CFG10                           =  IOMUX_PAD(0x03FC, 0x0194, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD3__SAI1_TX_DATA3                            =  IOMUX_PAD(0x0400, 0x0198, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD3__SAI5_TX_DATA3                            =  IOMUX_PAD(0x0400, 0x0198, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD3__ARM_PLATFORM_TRACE11                     =  IOMUX_PAD(0x0400, 0x0198, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD3__GPIO4_IO15                               =  IOMUX_PAD(0x0400, 0x0198, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD3__SRC_BOOT_CFG11                           =  IOMUX_PAD(0x0400, 0x0198, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD4__SAI1_TX_DATA4                            =  IOMUX_PAD(0x0404, 0x019C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD4__SAI6_RX_BCLK                             =  IOMUX_PAD(0x0404, 0x019C, 1, 0x0510, 1, 0),
	IMX8MM_PAD_SAI1_TXD4__SAI6_TX_BCLK                             =  IOMUX_PAD(0x0404, 0x019C, 2, 0x051C, 1, 0),
	IMX8MM_PAD_SAI1_TXD4__ARM_PLATFORM_TRACE12                     =  IOMUX_PAD(0x0404, 0x019C, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD4__GPIO4_IO16                               =  IOMUX_PAD(0x0404, 0x019C, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD4__SRC_BOOT_CFG12                           =  IOMUX_PAD(0x0404, 0x019C, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD5__SAI1_TX_DATA5                            =  IOMUX_PAD(0x0408, 0x01A0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD5__SAI6_RX_DATA0                            =  IOMUX_PAD(0x0408, 0x01A0, 1, 0x0514, 1, 0),
	IMX8MM_PAD_SAI1_TXD5__SAI6_TX_DATA0                            =  IOMUX_PAD(0x0408, 0x01A0, 2, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD5__ARM_PLATFORM_TRACE13                     =  IOMUX_PAD(0x0408, 0x01A0, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD5__GPIO4_IO17                               =  IOMUX_PAD(0x0408, 0x01A0, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD5__SRC_BOOT_CFG13                           =  IOMUX_PAD(0x0408, 0x01A0, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD6__SAI1_TX_DATA6                            =  IOMUX_PAD(0x040C, 0x01A4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD6__SAI6_RX_SYNC                             =  IOMUX_PAD(0x040C, 0x01A4, 1, 0x0518, 1, 0),
	IMX8MM_PAD_SAI1_TXD6__SAI6_TX_SYNC                             =  IOMUX_PAD(0x040C, 0x01A4, 2, 0x0520, 1, 0),
	IMX8MM_PAD_SAI1_TXD6__ARM_PLATFORM_TRACE14                     =  IOMUX_PAD(0x040C, 0x01A4, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD6__GPIO4_IO18                               =  IOMUX_PAD(0x040C, 0x01A4, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD6__SRC_BOOT_CFG14                           =  IOMUX_PAD(0x040C, 0x01A4, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_TXD7__SAI1_TX_DATA7                            =  IOMUX_PAD(0x0410, 0x01A8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD7__SAI6_MCLK                                =  IOMUX_PAD(0x0410, 0x01A8, 1, 0x0530, 1, 0),
	IMX8MM_PAD_SAI1_TXD7__PDM_CLK                                  =  IOMUX_PAD(0x0410, 0x01A8, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD7__ARM_PLATFORM_TRACE15                     =  IOMUX_PAD(0x0410, 0x01A8, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD7__GPIO4_IO19                               =  IOMUX_PAD(0x0410, 0x01A8, 5, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_TXD7__SRC_BOOT_CFG15                           =  IOMUX_PAD(0x0410, 0x01A8, 6, 0x0000, 0, 0),

	IMX8MM_PAD_SAI1_MCLK__SAI1_MCLK                                =  IOMUX_PAD(0x0414, 0x01AC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_MCLK__SAI5_MCLK                                =  IOMUX_PAD(0x0414, 0x01AC, 1, 0x052C, 1, 0),
	IMX8MM_PAD_SAI1_MCLK__SAI1_TX_BCLK                             =  IOMUX_PAD(0x0414, 0x01AC, 2, 0x04C8, 2, 0),
	IMX8MM_PAD_SAI1_MCLK__PDM_CLK                                  =  IOMUX_PAD(0x0414, 0x01AC, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI1_MCLK__GPIO4_IO20                               =  IOMUX_PAD(0x0414, 0x01AC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_RXFS__SAI2_RX_SYNC                             =  IOMUX_PAD(0x0418, 0x01B0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXFS__SAI5_TX_SYNC                             =  IOMUX_PAD(0x0418, 0x01B0, 1, 0x04EC, 2, 0),
	IMX8MM_PAD_SAI2_RXFS__SAI5_TX_DATA1                            =  IOMUX_PAD(0x0418, 0x01B0, 2, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXFS__SAI2_RX_DATA1                            =  IOMUX_PAD(0x0418, 0x01B0, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXFS__UART1_TX                                 =  IOMUX_PAD(0x0418, 0x01B0, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXFS__UART1_RX                                 =  IOMUX_PAD(0x0418, 0x01B0, 4, 0x04F4, 2, 0),
	IMX8MM_PAD_SAI2_RXFS__GPIO4_IO21                               =  IOMUX_PAD(0x0418, 0x01B0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_RXC__SAI2_RX_BCLK                              =  IOMUX_PAD(0x041C, 0x01B4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXC__SAI5_TX_BCLK                              =  IOMUX_PAD(0x041C, 0x01B4, 1, 0x04E8, 2, 0),
	IMX8MM_PAD_SAI2_RXC__UART1_RX                                  =  IOMUX_PAD(0x041C, 0x01B4, 4, 0x04F4, 3, 0),
	IMX8MM_PAD_SAI2_RXC__UART1_TX                                  =  IOMUX_PAD(0x041C, 0x01B4, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXC__GPIO4_IO22                                =  IOMUX_PAD(0x041C, 0x01B4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_RXD0__SAI2_RX_DATA0                            =  IOMUX_PAD(0x0420, 0x01B8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXD0__SAI5_TX_DATA0                            =  IOMUX_PAD(0x0420, 0x01B8, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXD0__UART1_RTS_B                              =  IOMUX_PAD(0x0420, 0x01B8, 4, 0x04F0, 2, 0),
	IMX8MM_PAD_SAI2_RXD0__UART1_CTS_B                              =  IOMUX_PAD(0x0420, 0x01B8, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_RXD0__GPIO4_IO23                               =  IOMUX_PAD(0x0420, 0x01B8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_TXFS__SAI2_TX_SYNC                             =  IOMUX_PAD(0x0424, 0x01BC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXFS__SAI5_TX_DATA1                            =  IOMUX_PAD(0x0424, 0x01BC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXFS__SAI2_TX_DATA1                            =  IOMUX_PAD(0x0424, 0x01BC, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXFS__UART1_CTS_B                              =  IOMUX_PAD(0x0424, 0x01BC, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXFS__UART1_RTS_B                              =  IOMUX_PAD(0x0424, 0x01BC, 4, 0x04F0, 3, 0),
	IMX8MM_PAD_SAI2_TXFS__GPIO4_IO24                               =  IOMUX_PAD(0x0424, 0x01BC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_TXC__SAI2_TX_BCLK                              =  IOMUX_PAD(0x0428, 0x01C0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXC__SAI5_TX_DATA2                             =  IOMUX_PAD(0x0428, 0x01C0, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXC__GPIO4_IO25                                =  IOMUX_PAD(0x0428, 0x01C0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_TXD0__SAI2_TX_DATA0                            =  IOMUX_PAD(0x042C, 0x01C4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXD0__SAI5_TX_DATA3                            =  IOMUX_PAD(0x042C, 0x01C4, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_TXD0__GPIO4_IO26                               =  IOMUX_PAD(0x042C, 0x01C4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI2_MCLK__SAI2_MCLK                                =  IOMUX_PAD(0x0430, 0x01C8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI2_MCLK__SAI5_MCLK                                =  IOMUX_PAD(0x0430, 0x01C8, 1, 0x052C, 2, 0),
	IMX8MM_PAD_SAI2_MCLK__GPIO4_IO27                               =  IOMUX_PAD(0x0430, 0x01C8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_RXFS__SAI3_RX_SYNC                             =  IOMUX_PAD(0x0434, 0x01CC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXFS__GPT1_CAPTURE1                            =  IOMUX_PAD(0x0434, 0x01CC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXFS__SAI5_RX_SYNC                             =  IOMUX_PAD(0x0434, 0x01CC, 2, 0x04E4, 2, 0),
	IMX8MM_PAD_SAI3_RXFS__SAI3_RX_DATA1                            =  IOMUX_PAD(0x0434, 0x01CC, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXFS__GPIO4_IO28                               =  IOMUX_PAD(0x0434, 0x01CC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_RXC__SAI3_RX_BCLK                              =  IOMUX_PAD(0x0438, 0x01D0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXC__GPT1_CLK                                  =  IOMUX_PAD(0x0438, 0x01D0, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXC__SAI5_RX_BCLK                              =  IOMUX_PAD(0x0438, 0x01D0, 2, 0x04D0, 2, 0),
	IMX8MM_PAD_SAI3_RXC__UART2_CTS_B                               =  IOMUX_PAD(0x0438, 0x01D0, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXC__UART2_RTS_B                               =  IOMUX_PAD(0x0438, 0x01D0, 4, 0x04F8, 2, 0),
	IMX8MM_PAD_SAI3_RXC__GPIO4_IO29                                =  IOMUX_PAD(0x0438, 0x01D0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_RXD__SAI3_RX_DATA0                             =  IOMUX_PAD(0x043C, 0x01D4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXD__GPT1_COMPARE1                             =  IOMUX_PAD(0x043C, 0x01D4, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXD__SAI5_RX_DATA0                             =  IOMUX_PAD(0x043C, 0x01D4, 2, 0x04D4, 2, 0),
	IMX8MM_PAD_SAI3_RXD__UART2_RTS_B                               =  IOMUX_PAD(0x043C, 0x01D4, 4, 0x04F8, 3, 0),
	IMX8MM_PAD_SAI3_RXD__UART2_CTS_B                               =  IOMUX_PAD(0x043C, 0x01D4, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_RXD__GPIO4_IO30                                =  IOMUX_PAD(0x043C, 0x01D4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_TXFS__SAI3_TX_SYNC                             =  IOMUX_PAD(0x0440, 0x01D8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXFS__GPT1_CAPTURE2                            =  IOMUX_PAD(0x0440, 0x01D8, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXFS__SAI5_RX_DATA1                            =  IOMUX_PAD(0x0440, 0x01D8, 2, 0x04D8, 2, 0),
	IMX8MM_PAD_SAI3_TXFS__SAI3_TX_DATA1                            =  IOMUX_PAD(0x0440, 0x01D8, 3, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXFS__UART2_RX                                 =  IOMUX_PAD(0x0440, 0x01D8, 4, 0x04FC, 2, 0),
	IMX8MM_PAD_SAI3_TXFS__UART2_TX                                 =  IOMUX_PAD(0x0440, 0x01D8, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXFS__GPIO4_IO31                               =  IOMUX_PAD(0x0440, 0x01D8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_TXC__SAI3_TX_BCLK                              =  IOMUX_PAD(0x0444, 0x01DC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXC__GPT1_COMPARE2                             =  IOMUX_PAD(0x0444, 0x01DC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXC__SAI5_RX_DATA2                             =  IOMUX_PAD(0x0444, 0x01DC, 2, 0x04DC, 2, 0),
	IMX8MM_PAD_SAI3_TXC__UART2_TX                                  =  IOMUX_PAD(0x0444, 0x01DC, 4, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXC__UART2_RX                                  =  IOMUX_PAD(0x0444, 0x01DC, 4, 0x04FC, 3, 0),
	IMX8MM_PAD_SAI3_TXC__GPIO5_IO0                                 =  IOMUX_PAD(0x0444, 0x01DC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_TXD__SAI3_TX_DATA0                             =  IOMUX_PAD(0x0448, 0x01E0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXD__GPT1_COMPARE3                             =  IOMUX_PAD(0x0448, 0x01E0, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_TXD__SAI5_RX_DATA3                             =  IOMUX_PAD(0x0448, 0x01E0, 2, 0x04E0, 2, 0),
	IMX8MM_PAD_SAI3_TXD__GPIO5_IO1                                 =  IOMUX_PAD(0x0448, 0x01E0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SAI3_MCLK__SAI3_MCLK                                =  IOMUX_PAD(0x044C, 0x01E4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_MCLK__PWM4_OUT                                 =  IOMUX_PAD(0x044C, 0x01E4, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SAI3_MCLK__SAI5_MCLK                                =  IOMUX_PAD(0x044C, 0x01E4, 2, 0x052C, 3, 0),
	IMX8MM_PAD_SAI3_MCLK__GPIO5_IO2                                =  IOMUX_PAD(0x044C, 0x01E4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SPDIF_TX__SPDIF1_OUT                                =  IOMUX_PAD(0x0450, 0x01E8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_TX__PWM3_OUT                                  =  IOMUX_PAD(0x0450, 0x01E8, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_TX__GPIO5_IO3                                 =  IOMUX_PAD(0x0450, 0x01E8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SPDIF_RX__SPDIF1_IN                                 =  IOMUX_PAD(0x0454, 0x01EC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_RX__PWM2_OUT                                  =  IOMUX_PAD(0x0454, 0x01EC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_RX__GPIO5_IO4                                 =  IOMUX_PAD(0x0454, 0x01EC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_SPDIF_EXT_CLK__SPDIF1_EXT_CLK                       =  IOMUX_PAD(0x0458, 0x01F0, 0, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_EXT_CLK__PWM1_OUT                             =  IOMUX_PAD(0x0458, 0x01F0, 1, 0x0000, 0, 0),
	IMX8MM_PAD_SPDIF_EXT_CLK__GPIO5_IO5                            =  IOMUX_PAD(0x0458, 0x01F0, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI1_SCLK__ECSPI1_SCLK                            =  IOMUX_PAD(0x045C, 0x01F4, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_SCLK__UART3_RX                               =  IOMUX_PAD(0x045C, 0x01F4, 1, 0x0504, 0, 0),
	IMX8MM_PAD_ECSPI1_SCLK__UART3_TX                               =  IOMUX_PAD(0x045C, 0x01F4, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_SCLK__GPIO5_IO6                              =  IOMUX_PAD(0x045C, 0x01F4, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI1_MOSI__ECSPI1_MOSI                            =  IOMUX_PAD(0x0460, 0x01F8, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_MOSI__UART3_TX                               =  IOMUX_PAD(0x0460, 0x01F8, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_MOSI__UART3_RX                               =  IOMUX_PAD(0x0460, 0x01F8, 1, 0x0504, 1, 0),
	IMX8MM_PAD_ECSPI1_MOSI__GPIO5_IO7                              =  IOMUX_PAD(0x0460, 0x01F8, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI1_MISO__ECSPI1_MISO                            =  IOMUX_PAD(0x0464, 0x01FC, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_MISO__UART3_CTS_B                            =  IOMUX_PAD(0x0464, 0x01FC, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_MISO__UART3_RTS_B                            =  IOMUX_PAD(0x0464, 0x01FC, 1, 0x0500, 0, 0),
	IMX8MM_PAD_ECSPI1_MISO__GPIO5_IO8                              =  IOMUX_PAD(0x0464, 0x01FC, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI1_SS0__ECSPI1_SS0                              =  IOMUX_PAD(0x0468, 0x0200, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_SS0__UART3_RTS_B                             =  IOMUX_PAD(0x0468, 0x0200, 1, 0x0500, 1, 0),
	IMX8MM_PAD_ECSPI1_SS0__UART3_CTS_B                             =  IOMUX_PAD(0x0468, 0x0200, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI1_SS0__GPIO5_IO9                               =  IOMUX_PAD(0x0468, 0x0200, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI2_SCLK__ECSPI2_SCLK                            =  IOMUX_PAD(0x046C, 0x0204, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_SCLK__UART4_RX                               =  IOMUX_PAD(0x046C, 0x0204, 1, 0x050C, 0, 0),
	IMX8MM_PAD_ECSPI2_SCLK__UART4_TX                               =  IOMUX_PAD(0x046C, 0x0204, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_SCLK__GPIO5_IO10                             =  IOMUX_PAD(0x046C, 0x0204, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI2_MOSI__ECSPI2_MOSI                            =  IOMUX_PAD(0x0470, 0x0208, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_MOSI__UART4_TX                               =  IOMUX_PAD(0x0470, 0x0208, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_MOSI__UART4_RX                               =  IOMUX_PAD(0x0470, 0x0208, 1, 0x050C, 1, 0),
	IMX8MM_PAD_ECSPI2_MOSI__GPIO5_IO11                             =  IOMUX_PAD(0x0470, 0x0208, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI2_MISO__ECSPI2_MISO                            =  IOMUX_PAD(0x0474, 0x020C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_MISO__UART4_CTS_B                            =  IOMUX_PAD(0x0474, 0x020C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_MISO__UART4_RTS_B                            =  IOMUX_PAD(0x0474, 0x020C, 1, 0x0508, 0, 0),
	IMX8MM_PAD_ECSPI2_MISO__GPIO5_IO12                             =  IOMUX_PAD(0x0474, 0x020C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_ECSPI2_SS0__ECSPI2_SS0                              =  IOMUX_PAD(0x0478, 0x0210, 0, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_SS0__UART4_RTS_B                             =  IOMUX_PAD(0x0478, 0x0210, 1, 0x0508, 1, 0),
	IMX8MM_PAD_ECSPI2_SS0__UART4_CTS_B                             =  IOMUX_PAD(0x0478, 0x0210, 1, 0x0000, 0, 0),
	IMX8MM_PAD_ECSPI2_SS0__GPIO5_IO13                              =  IOMUX_PAD(0x0478, 0x0210, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C1_SCL__I2C1_SCL                                  =  IOMUX_PAD(0x047C, 0x0214, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C1_SCL__ENET1_MDC                                 =  IOMUX_PAD(0x047C, 0x0214, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C1_SCL__GPIO5_IO14                                =  IOMUX_PAD(0x047C, 0x0214, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C1_SDA__I2C1_SDA                                  =  IOMUX_PAD(0x0480, 0x0218, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C1_SDA__ENET1_MDIO                                =  IOMUX_PAD(0x0480, 0x0218, 1, 0x04C0, 2, 0),
	IMX8MM_PAD_I2C1_SDA__GPIO5_IO15                                =  IOMUX_PAD(0x0480, 0x0218, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C2_SCL__I2C2_SCL                                  =  IOMUX_PAD(0x0484, 0x021C, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C2_SCL__ENET1_1588_EVENT1_IN                      =  IOMUX_PAD(0x0484, 0x021C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C2_SCL__USDHC3_CD_B                               =  IOMUX_PAD(0x0484, 0x021C, 2, 0x0544, 1, 0),
	IMX8MM_PAD_I2C2_SCL__GPIO5_IO16                                =  IOMUX_PAD(0x0484, 0x021C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C2_SDA__I2C2_SDA                                  =  IOMUX_PAD(0x0488, 0x0220, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C2_SDA__ENET1_1588_EVENT1_OUT                     =  IOMUX_PAD(0x0488, 0x0220, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C2_SDA__USDHC3_WP                                 =  IOMUX_PAD(0x0488, 0x0220, 2, 0x0548, 1, 0),
	IMX8MM_PAD_I2C2_SDA__GPIO5_IO17                                =  IOMUX_PAD(0x0488, 0x0220, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C3_SCL__I2C3_SCL                                  =  IOMUX_PAD(0x048C, 0x0224, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SCL__PWM4_OUT                                  =  IOMUX_PAD(0x048C, 0x0224, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SCL__GPT2_CLK                                  =  IOMUX_PAD(0x048C, 0x0224, 2, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SCL__GPIO5_IO18                                =  IOMUX_PAD(0x048C, 0x0224, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C3_SDA__I2C3_SDA                                  =  IOMUX_PAD(0x0490, 0x0228, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SDA__PWM3_OUT                                  =  IOMUX_PAD(0x0490, 0x0228, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SDA__GPT3_CLK                                  =  IOMUX_PAD(0x0490, 0x0228, 2, 0x0000, 0, 0),
	IMX8MM_PAD_I2C3_SDA__GPIO5_IO19                                =  IOMUX_PAD(0x0490, 0x0228, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C4_SCL__I2C4_SCL                                  =  IOMUX_PAD(0x0494, 0x022C, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C4_SCL__PWM2_OUT                                  =  IOMUX_PAD(0x0494, 0x022C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C4_SCL__PCIE1_CLKREQ_B                            =  IOMUX_PAD(0x0494, 0x022C, 2, 0x0524, 0, 0),
	IMX8MM_PAD_I2C4_SCL__GPIO5_IO20                                =  IOMUX_PAD(0x0494, 0x022C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_I2C4_SDA__I2C4_SDA                                  =  IOMUX_PAD(0x0498, 0x0230, 0 | IOMUX_CONFIG_SION, 0x0000, 0, 0),
	IMX8MM_PAD_I2C4_SDA__PWM1_OUT                                  =  IOMUX_PAD(0x0498, 0x0230, 1, 0x0000, 0, 0),
	IMX8MM_PAD_I2C4_SDA__GPIO5_IO21                                =  IOMUX_PAD(0x0498, 0x0230, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART1_RXD__UART1_DCE_RX                             =  IOMUX_PAD(0x049C, 0x0234, 0, 0x04F4, 0, 0),
	IMX8MM_PAD_UART1_RXD__UART1_DTE_TX                             =  IOMUX_PAD(0x049C, 0x0234, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART1_RXD__ECSPI3_SCLK                              =  IOMUX_PAD(0x049C, 0x0234, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART1_RXD__GPIO5_IO22                               =  IOMUX_PAD(0x049C, 0x0234, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART1_TXD__UART1_DCE_TX                             =  IOMUX_PAD(0x04A0, 0x0238, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART1_TXD__UART1_DTE_RX                             =  IOMUX_PAD(0x04A0, 0x0238, 0, 0x04F4, 1, 0),
	IMX8MM_PAD_UART1_TXD__ECSPI3_MOSI                              =  IOMUX_PAD(0x04A0, 0x0238, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART1_TXD__GPIO5_IO23                               =  IOMUX_PAD(0x04A0, 0x0238, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART2_RXD__UART2_DCE_RX                             =  IOMUX_PAD(0x04A4, 0x023C, 0, 0x04FC, 0, 0),
	IMX8MM_PAD_UART2_RXD__UART2_DTE_TX                             =  IOMUX_PAD(0x04A4, 0x023C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART2_RXD__ECSPI3_MISO                              =  IOMUX_PAD(0x04A4, 0x023C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART2_RXD__GPIO5_IO24                               =  IOMUX_PAD(0x04A4, 0x023C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART2_TXD__UART2_DCE_TX                             =  IOMUX_PAD(0x04A8, 0x0240, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART2_TXD__UART2_DTE_RX                             =  IOMUX_PAD(0x04A8, 0x0240, 0, 0x04FC, 1, 0),
	IMX8MM_PAD_UART2_TXD__ECSPI3_SS0                               =  IOMUX_PAD(0x04A8, 0x0240, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART2_TXD__GPIO5_IO25                               =  IOMUX_PAD(0x04A8, 0x0240, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART3_RXD__UART3_DCE_RX                             =  IOMUX_PAD(0x04AC, 0x0244, 0, 0x0504, 2, 0),
	IMX8MM_PAD_UART3_RXD__UART3_DTE_TX                             =  IOMUX_PAD(0x04AC, 0x0244, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_RXD__UART1_CTS_B                              =  IOMUX_PAD(0x04AC, 0x0244, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_RXD__UART1_RTS_B                              =  IOMUX_PAD(0x04AC, 0x0244, 1, 0x04F0, 0, 0),
	IMX8MM_PAD_UART3_RXD__USDHC3_RESET_B                           =  IOMUX_PAD(0x04AC, 0x0244, 2, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_RXD__GPIO5_IO26                               =  IOMUX_PAD(0x04AC, 0x0244, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART3_TXD__UART3_TX                                 =  IOMUX_PAD(0x04B0, 0x0248, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_TXD__UART3_RX                                 =  IOMUX_PAD(0x04B0, 0x0248, 0, 0x0504, 3, 0),
	IMX8MM_PAD_UART3_TXD__UART1_RTS_B                              =  IOMUX_PAD(0x04B0, 0x0248, 1, 0x04F0, 1, 0),
	IMX8MM_PAD_UART3_TXD__UART1_CTS_B                              =  IOMUX_PAD(0x04B0, 0x0248, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_TXD__USDHC3_VSELECT                           =  IOMUX_PAD(0x04B0, 0x0248, 2, 0x0000, 0, 0),
	IMX8MM_PAD_UART3_TXD__GPIO5_IO27                               =  IOMUX_PAD(0x04B0, 0x0248, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART4_RXD__UART4_RX                                 =  IOMUX_PAD(0x04B4, 0x024C, 0, 0x050C, 2, 0),
	IMX8MM_PAD_UART4_RXD__UART4_TX                                 =  IOMUX_PAD(0x04B4, 0x024C, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART4_RXD__UART2_CTS_B                              =  IOMUX_PAD(0x04B4, 0x024C, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART4_RXD__UART2_RTS_B                              =  IOMUX_PAD(0x04B4, 0x024C, 1, 0x04F8, 0, 0),
	IMX8MM_PAD_UART4_RXD__PCIE1_CLKREQ_B                           =  IOMUX_PAD(0x04B4, 0x024C, 2, 0x0524, 1, 0),
	IMX8MM_PAD_UART4_RXD__GPIO5_IO28                               =  IOMUX_PAD(0x04B4, 0x024C, 5, 0x0000, 0, 0),

	IMX8MM_PAD_UART4_TXD__UART4_TX                                 =  IOMUX_PAD(0x04B8, 0x0250, 0, 0x0000, 0, 0),
	IMX8MM_PAD_UART4_TXD__UART4_RX                                 =  IOMUX_PAD(0x04B8, 0x0250, 0, 0x050C, 3, 0),
	IMX8MM_PAD_UART4_TXD__UART2_RTS_B                              =  IOMUX_PAD(0x04B8, 0x0250, 1, 0x04F8, 1, 0),
	IMX8MM_PAD_UART4_TXD__UART2_CTS_B                              =  IOMUX_PAD(0x04B8, 0x0250, 1, 0x0000, 0, 0),
	IMX8MM_PAD_UART4_TXD__GPIO5_IO29                               =  IOMUX_PAD(0x04B8, 0x0250, 5, 0x0000, 0, 0),
};
#endif
