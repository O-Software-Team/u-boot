/*
 * Copyright (C) 2010-2013 Freescale Semiconductor, Inc.
 * Copyright (C) 2014, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#include <malloc.h>
#include <asm/arch/mx6-pins.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/fbpanel.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/spi.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <asm/arch/crm_regs.h>
#include <i2c.h>
#include <input.h>
#include <splash.h>
#include <usb/ehci-ci.h>
#include "../common/bd_common.h"
#include "../common/padctrl.h"

DECLARE_GLOBAL_DATA_PTR;

#define AUD_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_LOW | PAD_CTL_DSE_40ohm |			\
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define BUTTON_PAD_CTRL (PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_HYS)

#define CEC_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_22K_UP | PAD_CTL_ODE | \
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_SRE_FAST)

#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_HYS |	\
	PAD_CTL_ODE | PAD_CTL_SRE_FAST)

#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED |		\
	PAD_CTL_DSE_40ohm     | PAD_CTL_SRE_FAST)

#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm |			\
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

/* 3.3 V */
#define USDHC3_CLK_PAD_CTRL (PAD_CTL_SPEED_LOW | PAD_CTL_DSE_40ohm | \
	PAD_CTL_SRE_FAST  | PAD_CTL_HYS)

#define USDHC3_PAD_CTRL (USDHC3_CLK_PAD_CTRL | PAD_CTL_PUS_47K_UP)

/* 1.8 V */
#define USDHC4_CLK_PAD_CTRL (PAD_CTL_SPEED_LOW | PAD_CTL_DSE_40ohm | \
	PAD_CTL_SRE_FAST  | PAD_CTL_HYS)

#define USDHC4_PAD_CTRL (USDHC4_CLK_PAD_CTRL | PAD_CTL_PUS_47K_UP)

static const iomux_v3_cfg_t init_pads[] = {
	/* AUDMUX  - SGTL5000 */
	IOMUX_PAD_CTRL(CSI0_DAT7__AUD3_RXD, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT4__AUD3_TXC, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT5__AUD3_TXD, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT6__AUD3_TXFS, AUD_PAD_CTRL),

	/* ECSPI1 pads (serial nor eeprom) */
	IOMUX_PAD_CTRL(EIM_D17__ECSPI1_MISO, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D18__ECSPI1_MOSI, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D16__ECSPI1_SCLK, SPI_PAD_CTRL),
#define GP_ECSPI1_NOR_CS	IMX_GPIO_NR(3, 19)
	IOMUX_PAD_CTRL(EIM_D19__GPIO3_IO19, WEAK_PULLUP),

	/* ENET pads that don't change for PHY reset */
	IOMUX_PAD_CTRL(ENET_MDIO__ENET_MDIO, PAD_CTRL_ENET_MDIO),
	IOMUX_PAD_CTRL(ENET_MDC__ENET_MDC, PAD_CTRL_ENET_MDC),
	IOMUX_PAD_CTRL(RGMII_TXC__RGMII_TXC, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(RGMII_TD0__RGMII_TD0, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(RGMII_TD1__RGMII_TD1, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(RGMII_TD2__RGMII_TD2, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(RGMII_TD3__RGMII_TD3, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(RGMII_TX_CTL__RGMII_TX_CTL, PAD_CTRL_ENET_TX),
	IOMUX_PAD_CTRL(ENET_REF_CLK__ENET_TX_CLK, PAD_CTRL_ENET_TX),
	/* pin 42 PHY nRST */
#define GP_RGMII_PHY_RESET	IMX_GPIO_NR(1, 27)
	IOMUX_PAD_CTRL(ENET_RXD0__GPIO1_IO27, OUTPUT_40OHM),
#define GP_ENET_PHY_INT		IMX_GPIO_NR(1, 28)
	IOMUX_PAD_CTRL(ENET_TX_EN__GPIO1_IO28, WEAK_PULLUP),

	/* FLEXCAN */
	IOMUX_PAD_CTRL(KEY_COL2__FLEXCAN1_TX, WEAK_PULLUP),
	IOMUX_PAD_CTRL(KEY_ROW2__FLEXCAN1_RX, WEAK_PULLUP),

	/* GPIO Keys */
	/* J23: Furnace, J24: Spare, J25: Gas delivery, J26:Auto sampler, J27: Front end power */
#define GP_INTERLOCK_IRQ	IMX_GPIO_NR(2, 20)
	IOMUX_PAD_CTRL(EIM_A18__GPIO2_IO20, WEAK_PULLUP),
#define GP_ZERO_CROSSING_IRQ	IMX_GPIO_NR(2, 19)
	IOMUX_PAD_CTRL(EIM_A19__GPIO2_IO19, WEAK_PULLUP),
#define GP_SYNC_IRQ		IMX_GPIO_NR(3, 12)
	IOMUX_PAD_CTRL(EIM_DA12__GPIO3_IO12, WEAK_PULLUP),
#define GP_HEATER_FAULT_IRQ	IMX_GPIO_NR(3, 3)
	IOMUX_PAD_CTRL(EIM_DA3__GPIO3_IO03, WEAK_PULLUP),
#define GP_EXCH_FAULT1		IMX_GPIO_NR(3, 6)
	IOMUX_PAD_CTRL(EIM_DA6__GPIO3_IO06, WEAK_PULLUP),
#define GP_EXCH_FAULT2		IMX_GPIO_NR(3, 5)
	IOMUX_PAD_CTRL(EIM_DA5__GPIO3_IO05, WEAK_PULLUP),
#define GP_EXCH_FAULT_IRQ	IMX_GPIO_NR(3, 10)
	IOMUX_PAD_CTRL(EIM_DA10__GPIO3_IO10, WEAK_PULLUP),

	/* GPIO Outputs */
	/* Exchange */
#define GP_EXCH_OFF		IMX_GPIO_NR(3, 11)
	IOMUX_PAD_CTRL(EIM_DA11__GPIO3_IO11, WEAK_PULLDN),
	/* Heater */
#define GP_HEATER_OFF		IMX_GPIO_NR(3, 4)
	IOMUX_PAD_CTRL(EIM_DA4__GPIO3_IO04, WEAK_PULLDN),
	/* LEDS */
#define GP_CAN_CONNECT		IMX_GPIO_NR(3, 13)
	IOMUX_PAD_CTRL(EIM_DA13__GPIO3_IO13, WEAK_PULLDN),
#define GP_LED_RED		IMX_GPIO_NR(3, 0)
	IOMUX_PAD_CTRL(EIM_DA0__GPIO3_IO00, WEAK_PULLDN_OUTPUT),
	/* dry contact relays */
#define GP_RELAY_EVENT		IMX_GPIO_NR(3, 7)
	IOMUX_PAD_CTRL(EIM_DA7__GPIO3_IO07, WEAK_PULLDN_OUTPUT),
#define GP_RELAY_GAS		IMX_GPIO_NR(3, 9)
	IOMUX_PAD_CTRL(EIM_DA9__GPIO3_IO09, WEAK_PULLDN_OUTPUT),

	/* I2C1 - SGT5000 */
	/* I2C2 - Nothing */
	/* I2C3 - touch connector */
#define GP_I2C3_IRQ		IMX_GPIO_NR(1, 9)
	IOMUX_PAD_CTRL(GPIO_9__GPIO1_IO09, WEAK_PULLUP),

	/* LVDS */
#define GP_LVDS_BKL_EN		IMX_GPIO_NR(4, 20)
	IOMUX_PAD_CTRL(DI0_PIN4__GPIO4_IO20, WEAK_PULLDN),
#define GP_LVDS_BACKLIGHT	IMX_GPIO_NR(1, 18)
	IOMUX_PAD_CTRL(SD1_CMD__GPIO1_IO18, OUTPUT_40OHM),

	/* Test points */
#define GP_TP71			IMX_GPIO_NR(1, 30)
	IOMUX_PAD_CTRL(ENET_TXD0__GPIO1_IO30, WEAK_PULLUP),
#define GP_TP74			IMX_GPIO_NR(3, 8)
	IOMUX_PAD_CTRL(EIM_DA8__GPIO3_IO08, WEAK_PULLUP),
#define GP_TP77			IMX_GPIO_NR(4, 24)
	IOMUX_PAD_CTRL(DISP0_DAT3__GPIO4_IO24, WEAK_PULLUP),
#define GP_TP78			IMX_GPIO_NR(4, 26)
	IOMUX_PAD_CTRL(DISP0_DAT5__GPIO4_IO26, WEAK_PULLUP),
#define GP_TP79			IMX_GPIO_NR(3, 2)
	IOMUX_PAD_CTRL(EIM_DA2__GPIO3_IO02, WEAK_PULLUP),
#define GP_TP80			IMX_GPIO_NR(3, 1)
	IOMUX_PAD_CTRL(EIM_DA1__GPIO3_IO01, WEAK_PULLUP),

	/* SGTL5000 */
	IOMUX_PAD_CTRL(GPIO_0__CCM_CLKO1, OUTPUT_40OHM),

	/* UART1 */
	IOMUX_PAD_CTRL(SD3_DAT7__UART1_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT6__UART1_RX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D24__UART1_DTR_B, UART_PAD_CTRL),

	/* UART2 - console */
	IOMUX_PAD_CTRL(EIM_D26__UART2_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D27__UART2_RX_DATA, UART_PAD_CTRL),

	/* UART5 */
	IOMUX_PAD_CTRL(KEY_COL1__UART5_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(KEY_ROW1__UART5_RX_DATA, UART_PAD_CTRL),

	/* USBH1 */
	IOMUX_PAD_CTRL(EIM_D30__USB_H1_OC, WEAK_PULLUP),
#define GP_USBH1_PWR		IMX_GPIO_NR(2, 28)
	IOMUX_PAD_CTRL(EIM_EB0__GPIO2_IO28, WEAK_PULLDN_OUTPUT),

	/* USB OTG */
	IOMUX_PAD_CTRL(GPIO_1__USB_OTG_ID, WEAK_PULLUP),
	IOMUX_PAD_CTRL(KEY_COL4__USB_OTG_OC, WEAK_PULLUP),
#define GP_USB_OTG_PWR		IMX_GPIO_NR(3, 22)
	IOMUX_PAD_CTRL(EIM_D22__GPIO3_IO22, WEAK_PULLDN_OUTPUT),

	/* USDHC3 - micro SD card */
	IOMUX_PAD_CTRL(SD3_CLK__SD3_CLK, USDHC3_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_CMD__SD3_CMD, USDHC3_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT0__SD3_DATA0, USDHC3_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT1__SD3_DATA1, USDHC3_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT2__SD3_DATA2, USDHC3_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT3__SD3_DATA3, USDHC3_PAD_CTRL),
#define GP_USDHC3_CD		IMX_GPIO_NR(7, 0)
	IOMUX_PAD_CTRL(SD3_DAT5__GPIO7_IO00, WEAK_PULLUP),

	/* USDHC4 - eMMC */
	IOMUX_PAD_CTRL(SD4_CLK__SD4_CLK, USDHC4_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_CMD__SD4_CMD, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT0__SD4_DATA0, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT1__SD4_DATA1, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT2__SD4_DATA2, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT3__SD4_DATA3, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT4__SD4_DATA4, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT5__SD4_DATA5, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT6__SD4_DATA6, USDHC4_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT7__SD4_DATA7, USDHC4_PAD_CTRL),
#define GP_EMMC_RESET		IMX_GPIO_NR(2, 6)
	IOMUX_PAD_CTRL(NANDF_D6__GPIO2_IO06, WEAK_PULLUP),
};

static const struct i2c_pads_info i2c_pads[] = {
	/* I2C1, rv4162 */
	I2C_PADS_INFO_ENTRY(I2C1, EIM_D21, 3, 21, EIM_D28, 3, 28, I2C_PAD_CTRL),
	I2C_PADS_INFO_ENTRY(I2C2, KEY_COL3, 4, 12, KEY_ROW3, 4, 13, I2C_PAD_CTRL),
	I2C_PADS_INFO_ENTRY(I2C3, GPIO_5, 1, 05, GPIO_16, 7, 11, I2C_PAD_CTRL),
};
#define I2C_BUS_CNT	3

#ifdef CONFIG_USB_EHCI_MX6
int board_ehci_hcd_init(int port)
{
	return 0;
}

int board_ehci_power(int port, int on)
{
	int gp = port ? GP_USBH1_PWR : GP_USB_OTG_PWR;
	gpio_set_value(gp, on);
	return 0;
}

#endif

#ifdef CONFIG_FSL_ESDHC_IMX
struct fsl_esdhc_cfg board_usdhc_cfg[] = {
	{.esdhc_base = USDHC3_BASE_ADDR, .bus_width = 4,
			.gp_cd = GP_USDHC3_CD},
	{.esdhc_base = USDHC4_BASE_ADDR, .bus_width = 8,
			.gp_reset = GP_EMMC_RESET},
};
#endif

#ifdef CONFIG_MXC_SPI
int board_spi_cs_gpio(unsigned bus, unsigned cs)
{
	int gp = (bus == 0 && cs == 0) ? GP_ECSPI1_NOR_CS : -1;
	return gp;
}
#endif

#ifdef CONFIG_CMD_FBPANEL
void board_enable_lvds(const struct display_info_t *di, int enable)
{
	gpio_direction_output(GP_LVDS_BACKLIGHT, enable);
}

static const struct display_info_t displays[] = {
	/* ft5x06 */
	VD_HANNSTAR7(LVDS, fbp_detect_i2c, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x38, FBTS_FT5X06),
	VD_M101NWWB(LVDS, NULL, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x38, FBTS_FT5X06),
	VD_WSVGA(LVDS, NULL, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x38, FBTS_FT5X06),
	VD_TM070JDHG30(LVDS, NULL, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x38, FBTS_FT5X06),

	VD_WXGA_J(LVDS, NULL, fbp_bus_gp(0, 0, GP_LVDS_BKL_EN, 0), 0x00),
	VD_WXGA(LVDS, NULL, fbp_bus_gp(0, 0, GP_LVDS_BKL_EN, 0), 0x00),

	/* goodix */
	VD_TM070JDHG30_14(LVDS, fbp_detect_i2c, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x14, FBTS_GOODIX),
	VD_TM070JDHG30_5D(LVDS, fbp_detect_i2c, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x5d, FBTS_GOODIX2),

	/* egalax_ts */
	VD_HANNSTAR(LVDS, fbp_detect_i2c, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x04, FBTS_EGALAX),
	VD_LG9_7(LVDS, NULL, fbp_bus_gp(2, 0, GP_LVDS_BKL_EN, 0), 0x04, FBTS_EGALAX),
};
#define display_cnt	ARRAY_SIZE(displays)
#else
#define displays	NULL
#define display_cnt	0
#endif

static const unsigned short gpios_out_low[] = {
	GP_RGMII_PHY_RESET,
	GP_RELAY_EVENT,
	GP_RELAY_GAS,
	GP_LVDS_BKL_EN,
	GP_LVDS_BACKLIGHT,
	GP_USBH1_PWR,
	GP_USB_OTG_PWR,
	GP_EMMC_RESET,
	GP_EXCH_OFF,
	GP_HEATER_OFF,
};

static const unsigned short gpios_out_high[] = {
	GP_LED_RED,
	GP_ECSPI1_NOR_CS,
};

static const unsigned short gpios_in[] = {
	GP_ENET_PHY_INT,
	GP_CAN_CONNECT,
	GP_INTERLOCK_IRQ,
	GP_ZERO_CROSSING_IRQ,
	GP_SYNC_IRQ,
	GP_HEATER_FAULT_IRQ,
	GP_EXCH_FAULT1,
	GP_EXCH_FAULT2,
	GP_EXCH_FAULT_IRQ,
	GP_I2C3_IRQ,
	GP_TP71,
	GP_TP74,
	GP_TP77,
	GP_TP78,
	GP_TP79,
	GP_TP80,
	GP_USDHC3_CD,
};

int board_early_init_f(void)
{
	set_gpios_in(gpios_in, ARRAY_SIZE(gpios_in));
	set_gpios(gpios_out_high, ARRAY_SIZE(gpios_out_high), 1);
	set_gpios(gpios_out_low, ARRAY_SIZE(gpios_out_low), 0);
	SETUP_IOMUX_PADS(init_pads);
	return 0;
}

int board_init(void)
{
	common_board_init(i2c_pads, I2C_BUS_CNT, IOMUXC_GPR1_OTG_ID_GPIO1,
			displays, display_cnt, 0);
	return 0;
}

const struct button_key board_buttons[] = {
	{"b1",		GP_TP71,	'1', 1},
	{NULL, 0, 0, 0},
};

#ifdef CONFIG_CMD_BMODE
const struct boot_mode board_boot_modes[] = {
	/* 4 bit bus width */
	{"mmc0",	MAKE_CFGVAL(0x40, 0x30, 0x00, 0x00)},
	{"mmc1",	MAKE_CFGVAL(0x60, 0x58, 0x00, 0x00)},	/* 8-bit eMMC */
	{NULL,		0},
};
#endif
