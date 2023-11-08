/*
 * Copyright (C) 2010-2013 Freescale Semiconductor, Inc.
 * Copyright (C) 2013, Boundary Devices <info@boundarydevices.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#include <malloc.h>
#include <asm/arch/mx6-pins.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/fbpanel.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/spi.h>
#include <div64.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mxc_hdmi.h>
#include <i2c.h>
#include <input.h>
#include <linux/fb.h>
#include <splash.h>
#include <usb/ehci-ci.h>
#include "../common/bd_common.h"
#include "../common/padctrl.h"

DECLARE_GLOBAL_DATA_PTR;

#define AUD_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_LOW | PAD_CTL_DSE_40ohm |			\
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define BUTTON_PAD_CTRL (PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_HYS)

#define CEC_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_PUS_22K_UP | PAD_CTL_ODE | \
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_SRE_FAST)

#define CSI_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm |			\
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define I2C_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm | PAD_CTL_HYS |	\
	PAD_CTL_ODE | PAD_CTL_SRE_FAST)

#define RGB_PAD_CTRL	PAD_CTL_DSE_120ohm

#define SPI_PAD_CTRL	(PAD_CTL_HYS | PAD_CTL_SPEED_MED |	\
	PAD_CTL_DSE_40ohm | PAD_CTL_SRE_FAST)

#define UART_PAD_CTRL	(PAD_CTL_PUS_100K_UP |			\
	PAD_CTL_SPEED_MED | PAD_CTL_DSE_40ohm |			\
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define USDHC_CLK_PAD_CTRL (PAD_CTL_SPEED_LOW | PAD_CTL_DSE_40ohm | \
	PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define USDHC_PAD_CTRL	(USDHC_CLK_PAD_CTRL | PAD_CTL_PUS_47K_UP)

/*
 *
 */
static const iomux_v3_cfg_t init_pads[] = {
	/* Main power on, High shuts down system */
#define GP_MAIN_POWER_EN	IMX_GPIO_NR(1, 19)
	IOMUX_PAD_CTRL(SD1_DAT2__GPIO1_IO19, WEAK_PULLDN),
#define GP_LED_BLUE		IMX_GPIO_NR(2, 24)
	IOMUX_PAD_CTRL(EIM_CS1__GPIO2_IO24, WEAK_PULLDN),

	/* AUDMUX */
	IOMUX_PAD_CTRL(CSI0_DAT7__AUD3_RXD, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT4__AUD3_TXC, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT5__AUD3_TXD, AUD_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT6__AUD3_TXFS, AUD_PAD_CTRL),

	/* ECSPI1 */
	IOMUX_PAD_CTRL(EIM_D17__ECSPI1_MISO, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D18__ECSPI1_MOSI, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D16__ECSPI1_SCLK, SPI_PAD_CTRL),
#define GP_ECSPI1_CS1	IMX_GPIO_NR(3, 19)
	IOMUX_PAD_CTRL(EIM_D19__GPIO3_IO19, WEAK_PULLUP), /* SS1 */

	/* GPIO_KEYS */
#define GP_MAIN_POWER_BUTTON	IMX_GPIO_NR(1, 2)
	IOMUX_PAD_CTRL(GPIO_2__GPIO1_IO02, WEAK_PULLUP),
#define GP_MENU		IMX_GPIO_NR(2, 1)
	IOMUX_PAD_CTRL(NANDF_D1__GPIO2_IO01, BUTTON_PAD_CTRL),
#define GP_BACK		IMX_GPIO_NR(4, 5)
	IOMUX_PAD_CTRL(GPIO_19__GPIO4_IO05, BUTTON_PAD_CTRL),
	/* Labeled Search (mapped to Power under Android) */
#define GP_SEARCH	IMX_GPIO_NR(2, 3)
	IOMUX_PAD_CTRL(NANDF_D3__GPIO2_IO03, BUTTON_PAD_CTRL),
#define GP_VOLUME_UP	IMX_GPIO_NR(7, 13)
	IOMUX_PAD_CTRL(GPIO_18__GPIO7_IO13, BUTTON_PAD_CTRL),

	/* 2 momentary switches */
#define GP_INPUT1		IMX_GPIO_NR(4, 8)
	IOMUX_PAD_CTRL(KEY_COL1__GPIO4_IO08, WEAK_PULLUP),	/* SW3 gpio */
#define GP_INPUT2		IMX_GPIO_NR(4, 9)
	IOMUX_PAD_CTRL(KEY_ROW1__GPIO4_IO09, WEAK_PULLUP),	/* SW2 gpio */

	/* HDMI */
	IOMUX_PAD_CTRL(EIM_A25__HDMI_TX_CEC_LINE, CEC_PAD_CTRL),

	/* I2C3MUX */
#define GP_I2C3_PCIE_EN		IMX_GPIO_NR(2, 25)
	IOMUX_PAD_CTRL(EIM_OE__GPIO2_IO25, WEAK_PULLDN_OUTPUT),
#define GP_I2C3_MAX77818_EN	IMX_GPIO_NR(3, 2)
	IOMUX_PAD_CTRL(EIM_DA2__GPIO3_IO02, WEAK_PULLDN_OUTPUT),

	/* I2C3 MAX77818 */
#define GP_MAX77818_INOKB	IMX_GPIO_NR(3, 4)	/* INOKB, WCHG_VALID_INT */
	IOMUX_PAD_CTRL(EIM_DA4__GPIO3_IO04, WEAK_PULLUP),
#define GP_MAX77818_WCINOKB	IMX_GPIO_NR(3, 5)	/* WCINOKB, WCHG_INT */
	IOMUX_PAD_CTRL(EIM_DA5__GPIO3_IO05, WEAK_PULLUP),
#define GP_MAX77818_INTB	IMX_GPIO_NR(3, 6)	/* INTB, CHG_INT */
	IOMUX_PAD_CTRL(EIM_DA6__GPIO3_IO06, WEAK_PULLUP),

	/* I2C3 touchscreen connector(J55) */
#define GP_TOUCH_RESET		IMX_GPIO_NR(2, 22)
	IOMUX_PAD_CTRL(EIM_A16__GPIO2_IO22, WEAK_PULLDN_OUTPUT),
#define GP_TOUCH_IRQ		IMX_GPIO_NR(2, 27)
	IOMUX_PAD_CTRL(EIM_LBA__GPIO2_IO27, WEAK_PULLUP),

	/* PCIe */
#define GP_PCIE_RESET		IMX_GPIO_NR(6, 31)
	IOMUX_PAD_CTRL(EIM_BCLK__GPIO6_IO31, WEAK_PULLDN_OUTPUT),

	/* PWM1: Backlight on RGB connector */
#define GP_RGB_BACKLIGHT	 IMX_GPIO_NR(1, 21)
	IOMUX_PAD_CTRL(SD1_DAT3__GPIO1_IO21, WEAK_PULLDN_OUTPUT),

	/* rtc - i2c1 */
#define GP_RTC_RV4162_IRQ	IMX_GPIO_NR(4, 6)
	IOMUX_PAD_CTRL(KEY_COL0__GPIO4_IO06, WEAK_PULLUP),


	/* SGTL5000 */
	IOMUX_PAD_CTRL(GPIO_0__CCM_CLKO1, OUTPUT_40OHM),	/* SGTL5000 sys_mclk */
#define GP_SGTL5000_MUTE	IMX_GPIO_NR(1, 29)		/* Low is muted */
	IOMUX_PAD_CTRL(ENET_TXD1__GPIO1_IO29, WEAK_PULLDN_OUTPUT),
#define GP_HEADPHONE_DET	IMX_GPIO_NR(4, 7)
	IOMUX_PAD_CTRL(KEY_ROW0__GPIO4_IO07, WEAK_PULLUP),
#define GP_LINE_IN_JACK_DETECT	IMX_GPIO_NR(1, 17)
	IOMUX_PAD_CTRL(SD1_DAT1__GPIO1_IO17, WEAK_PULLUP),
#define GP_MIC_DETECT	IMX_GPIO_NR(7, 8)
	IOMUX_PAD_CTRL(SD3_RST__GPIO7_IO08, WEAK_PULLUP),

	/* UART1  */
	IOMUX_PAD_CTRL(SD3_DAT7__UART1_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT6__UART1_RX_DATA, UART_PAD_CTRL),

	/* UART2 for debug */
#ifndef CONFIG_SILENT_UART
	IOMUX_PAD_CTRL(EIM_D26__UART2_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D27__UART2_RX_DATA, UART_PAD_CTRL),
#else
	IOMUX_PAD_CTRL(EIM_D26__GPIO3_IO26, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D27__GPIO3_IO27, UART_PAD_CTRL),
#endif
	/* UART3 - Broadcom Bluetooth*/
	IOMUX_PAD_CTRL(EIM_D24__UART3_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D25__UART3_RX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D23__UART3_CTS_B, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(EIM_D31__UART3_RTS_B, UART_PAD_CTRL),

	/* UART4 - GPS */
	IOMUX_PAD_CTRL(CSI0_DAT12__UART4_TX_DATA, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI0_DAT13__UART4_RX_DATA, UART_PAD_CTRL),
#define GP_GPS_RESET		IMX_GPIO_NR(6, 0)
	IOMUX_PAD_CTRL(CSI0_DAT14__GPIO6_IO00, WEAK_PULLDN_OUTPUT),
#define GP_GPS_IRQ		IMX_GPIO_NR(6, 1)
	IOMUX_PAD_CTRL(CSI0_DAT15__GPIO6_IO01, WEAK_PULLUP),
#define GP_GPS_HEARTBEAT	IMX_GPIO_NR(6, 2)
	IOMUX_PAD_CTRL(CSI0_DAT16__GPIO6_IO02, WEAK_PULLUP),

	/* USBH1 */
#define GP_USB_HUB_RESET	IMX_GPIO_NR(7, 12)
	IOMUX_PAD_CTRL(GPIO_17__GPIO7_IO12, WEAK_PULLDN_OUTPUT),	/* USB Hub Reset for USB2512 4 port hub */
#define GP_USB_DN1_PWR_EN	IMX_GPIO_NR(1, 4)		/* low is off */
	IOMUX_PAD_CTRL(GPIO_4__GPIO1_IO04, WEAK_PULLDN_OUTPUT),
#define GP_5V_EN		IMX_GPIO_NR(1, 7)		/* usb and hdmi 5v*/
	IOMUX_PAD_CTRL(GPIO_7__GPIO1_IO07, WEAK_PULLDN_OUTPUT),
	/*
	 * port1 - DN1 power controlled by GPIO_4 on J6
	 * port2 - usb power controlled by hub on J7
	 * port3 - usb power always on, on J1 and PCIe
	 */

	/* USBOTG - J3 */
	IOMUX_PAD_CTRL(GPIO_1__USB_OTG_ID, WEAK_PULLUP),
	IOMUX_PAD_CTRL(KEY_COL4__USB_OTG_OC, WEAK_PULLUP),
#define GP_USB_OTG_PWR		IMX_GPIO_NR(3, 22)
	IOMUX_PAD_CTRL(EIM_D22__GPIO3_IO22, WEAK_PULLDN_OUTPUT),

	/* USDHC2:  Broadcom Wifi */
	IOMUX_PAD_CTRL(SD2_CLK__SD2_CLK, USDHC_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD2_CMD__SD2_CMD, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD2_DAT0__SD2_DATA0, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD2_DAT1__SD2_DATA1, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD2_DAT2__SD2_DATA2, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD2_DAT3__SD2_DATA3, USDHC_PAD_CTRL),

#define GP_BRM_BT_RESET		IMX_GPIO_NR(6, 8)
	IOMUX_PAD_CTRL(NANDF_ALE__GPIO6_IO08, WEAK_PULLDN_OUTPUT),
#define GP_BRM_BT_EN		IMX_GPIO_NR(6, 15)
	IOMUX_PAD_CTRL(NANDF_CS2__GPIO6_IO15, WEAK_PULLDN_OUTPUT),
#define GP_BRM_BT_WAKE_IRQ	IMX_GPIO_NR(2, 7)
	IOMUX_PAD_CTRL(NANDF_D7__GPIO2_IO07, WEAK_PULLUP),
#define GP_BRM_BT_WAKEUP	IMX_GPIO_NR(6, 16)
	IOMUX_PAD_CTRL(NANDF_CS3__GPIO6_IO16, WEAK_PULLDN),

#define GP_BRM_WL_WAKE_IRQ	IMX_GPIO_NR(6, 11)
	IOMUX_PAD_CTRL(NANDF_CS0__GPIO6_IO11, WEAK_PULLDN),
#define GP_BRM_CLOCK_REQUEST	IMX_GPIO_NR(6, 9)
	IOMUX_PAD_CTRL(NANDF_WP_B__GPIO6_IO09, WEAK_PULLUP),
#define GP_BRM_WL_EN		IMX_GPIO_NR(6, 7)
	IOMUX_PAD_CTRL(NANDF_CLE__GPIO6_IO07, WEAK_PULLDN_OUTPUT),
//	IOMUX_PAD_CTRL(SD1_CLK__OSC32K_32K_OUT, OUTPUT_40OHM),	/* slow clock */

	/* USDHC3 - micro sd */
	IOMUX_PAD_CTRL(SD3_CLK__SD3_CLK, USDHC_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_CMD__SD3_CMD, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT0__SD3_DATA0, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT1__SD3_DATA1, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT2__SD3_DATA2, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD3_DAT3__SD3_DATA3, USDHC_PAD_CTRL),
#define GP_USDHC3_CD	IMX_GPIO_NR(7, 0)
	IOMUX_PAD_CTRL(SD3_DAT5__GPIO7_IO00, WEAK_PULLUP), /* CD */

	/* USDHC4 - eMMC */
	IOMUX_PAD_CTRL(SD4_CLK__SD4_CLK, USDHC_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_CMD__SD4_CMD, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT0__SD4_DATA0, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT1__SD4_DATA1, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT2__SD4_DATA2, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT3__SD4_DATA3, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT4__SD4_DATA4, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT5__SD4_DATA5, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT6__SD4_DATA6, USDHC_PAD_CTRL),
	IOMUX_PAD_CTRL(SD4_DAT7__SD4_DATA7, USDHC_PAD_CTRL),
#define GP_EMMC_RESET	IMX_GPIO_NR(2, 6)
	IOMUX_PAD_CTRL(NANDF_D6__GPIO2_IO06, WEAK_PULLDN_OUTPUT),
};

#ifdef CONFIG_CMD_FBPANEL
static const iomux_v3_cfg_t rgb_pads[] = {
	IOMUX_PAD_CTRL(DI0_DISP_CLK__IPU1_DI0_DISP_CLK, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DI0_PIN15__IPU1_DI0_PIN15, RGB_PAD_CTRL),	/* DRDY */
	IOMUX_PAD_CTRL(DI0_PIN2__IPU1_DI0_PIN02, RGB_PAD_CTRL),		/* HSYNC */
	IOMUX_PAD_CTRL(DI0_PIN3__IPU1_DI0_PIN03, RGB_PAD_CTRL),		/* VSYNC */
	IOMUX_PAD_CTRL(DI0_PIN4__GPIO4_IO20, RGB_PAD_CTRL),		/* Contrast */
	IOMUX_PAD_CTRL(DISP0_DAT0__IPU1_DISP0_DATA00, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT1__IPU1_DISP0_DATA01, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT2__IPU1_DISP0_DATA02, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT3__IPU1_DISP0_DATA03, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT4__IPU1_DISP0_DATA04, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT5__IPU1_DISP0_DATA05, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT6__IPU1_DISP0_DATA06, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT7__IPU1_DISP0_DATA07, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT8__IPU1_DISP0_DATA08, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT9__IPU1_DISP0_DATA09, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT10__IPU1_DISP0_DATA10, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT11__IPU1_DISP0_DATA11, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT12__IPU1_DISP0_DATA12, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT13__IPU1_DISP0_DATA13, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT14__IPU1_DISP0_DATA14, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT15__IPU1_DISP0_DATA15, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT16__IPU1_DISP0_DATA16, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT17__IPU1_DISP0_DATA17, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT18__IPU1_DISP0_DATA18, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT19__IPU1_DISP0_DATA19, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT20__IPU1_DISP0_DATA20, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT21__IPU1_DISP0_DATA21, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT22__IPU1_DISP0_DATA22, RGB_PAD_CTRL),
	IOMUX_PAD_CTRL(DISP0_DAT23__IPU1_DISP0_DATA23, RGB_PAD_CTRL),
};
#endif

static const iomux_v3_cfg_t rgb_gpio_pads[] = {
	IOMUX_PAD_CTRL(DI0_DISP_CLK__GPIO4_IO16, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DI0_PIN15__GPIO4_IO17, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DI0_PIN2__GPIO4_IO18, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DI0_PIN3__GPIO4_IO19, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DI0_PIN4__GPIO4_IO20, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT0__GPIO4_IO21, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT1__GPIO4_IO22, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT2__GPIO4_IO23, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT3__GPIO4_IO24, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT4__GPIO4_IO25, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT5__GPIO4_IO26, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT6__GPIO4_IO27, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT7__GPIO4_IO28, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT8__GPIO4_IO29, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT9__GPIO4_IO30, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT10__GPIO4_IO31, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT11__GPIO5_IO05, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT12__GPIO5_IO06, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT13__GPIO5_IO07, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT14__GPIO5_IO08, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT15__GPIO5_IO09, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT16__GPIO5_IO10, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT17__GPIO5_IO11, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT18__GPIO5_IO12, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT19__GPIO5_IO13, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT20__GPIO5_IO14, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT21__GPIO5_IO15, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT22__GPIO5_IO16, WEAK_PULLUP),
	IOMUX_PAD_CTRL(DISP0_DAT23__GPIO5_IO17, WEAK_PULLUP),
};

static const struct i2c_pads_info i2c_pads[] = {
	/* I2C1, SGTL5000, RTC(rv4162) */
	I2C_PADS_INFO_ENTRY(I2C1, EIM_D21, 3, 21, EIM_D28, 3, 28, I2C_PAD_CTRL),
	/* I2C2 - hdmi */
	I2C_PADS_INFO_ENTRY(I2C2, KEY_COL3, 4, 12, KEY_ROW3, 4, 13, I2C_PAD_CTRL),
	/* I2C3, Charger, PCIe */
	I2C_PADS_INFO_ENTRY(I2C3, GPIO_5, 1, 05, GPIO_16, 7, 11, I2C_PAD_CTRL),
};
#define I2C_BUS_CNT	3

#ifdef CONFIG_USB_EHCI_MX6
static void charge_from_usb(int enable)
{
	u8 val8 = enable ? 0x27 : 7;
	u8 orig_i2c_bus = i2c_get_bus_num();

	i2c_set_bus_num(2);
	i2c_write(0x69, 0xc3, 1, &val8, 1);
	i2c_set_bus_num(orig_i2c_bus);
}

int board_ehci_hcd_init(int port)
{
	if (port) {
		/* Reset USB hub */
		gpio_direction_output(GP_USB_HUB_RESET, 0);
		mdelay(2);
		gpio_set_value(GP_USB_HUB_RESET, 1);
	}
	return 0;
}

int board_ehci_power(int port, int on)
{
	int gp = port ? GP_USB_DN1_PWR_EN : GP_USB_OTG_PWR;

	if (!port && on)
		charge_from_usb(0);
	gpio_set_value(gp, on);
	if (!port && !on)
		charge_from_usb(1);
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
	return (bus == 0 && cs == 0) ? GP_ECSPI1_CS1 : -1;
}

#endif

#ifdef CONFIG_CMD_FBPANEL
void board_enable_lcd(const struct display_info_t *di, int enable)
{
	if (enable)
		SETUP_IOMUX_PADS(rgb_pads);
	else
		SETUP_IOMUX_PADS(rgb_gpio_pads);
	gpio_direction_output(GP_RGB_BACKLIGHT, enable);
}

static const struct display_info_t displays[] = {
	/* hdmi */
	VD_1280_720M_60(HDMI, fbp_detect_i2c, 1, 0x50),
	VD_1920_1080M_60(HDMI, NULL, 1, 0x50),
	VD_1024_768M_60(HDMI, NULL, 1, 0x50),

	/* tsc2004 */
	VD_OKAYA_480_272(LCD, fbp_detect_i2c, 2, 0x48, FBTS_TSC2004),
};
#define display_cnt	ARRAY_SIZE(displays)
#else
#define displays	NULL
#define display_cnt	0
#endif

static const unsigned short gpios_out_low[] = {
	GP_MAIN_POWER_EN,
	GP_RGB_BACKLIGHT,
	GP_BRM_WL_EN,		/* disable wireless */
	GP_BRM_BT_EN,	 	/* disable bluetooth */
	GP_SGTL5000_MUTE,	/* MUTE */
	GP_LED_BLUE,
	GP_TOUCH_RESET,
	GP_PCIE_RESET,
	GP_I2C3_PCIE_EN,
	GP_GPS_RESET,
	GP_USB_HUB_RESET,
	GP_USB_DN1_PWR_EN,
	GP_USB_OTG_PWR,		/* disable USB otg power */
	GP_BRM_BT_RESET,
	GP_BRM_BT_EN,
	GP_BRM_WL_EN,
	GP_EMMC_RESET,
};

static const unsigned short gpios_out_high[] = {
	GP_ECSPI1_CS1,
	GP_I2C3_MAX77818_EN,
};

static const unsigned short gpios_out_high2[] = {
	GP_5V_EN,
};

static const unsigned short gpios_in[] = {
	GP_HEADPHONE_DET,
	GP_LINE_IN_JACK_DETECT,
	GP_MIC_DETECT,
	GP_MENU,
	GP_BACK,
	GP_SEARCH,
	GP_VOLUME_UP,
	GP_INPUT1,
	GP_INPUT2,
	GP_BRM_WL_WAKE_IRQ,
	GP_TOUCH_IRQ,
	GP_RTC_RV4162_IRQ,
	GP_MAIN_POWER_BUTTON,
	GP_MAX77818_INOKB,
	GP_MAX77818_WCINOKB,
	GP_MAX77818_INTB,
	GP_GPS_IRQ,
	GP_GPS_HEARTBEAT,
	GP_BRM_BT_WAKE_IRQ,
	GP_BRM_BT_WAKEUP,
	GP_BRM_WL_WAKE_IRQ,
	GP_BRM_CLOCK_REQUEST,
	GP_USDHC3_CD,
};

int board_early_init_f(void)
{
	set_gpios_in(gpios_in, ARRAY_SIZE(gpios_in));
	set_gpios(gpios_out_high, ARRAY_SIZE(gpios_out_high), 1);
	set_gpios(gpios_out_low, ARRAY_SIZE(gpios_out_low), 0);
	SETUP_IOMUX_PADS(init_pads);
	SETUP_IOMUX_PADS(rgb_gpio_pads);
	return 0;
}

void board_poweroff(void)
{
	struct snvs_regs *snvs = (struct snvs_regs *)(SNVS_BASE_ADDR);

	/* Doing both gpio1:19 and pmic_req makes the board not turn on again */
//	gpio_set_value(GP_MAIN_POWER_EN, 1);
	writel(0x60, &snvs->lpcr);
	mdelay(500);
}

int board_init(void)
{
	common_board_init(i2c_pads, I2C_BUS_CNT, IOMUXC_GPR1_OTG_ID_GPIO1,
			displays, display_cnt, 0);

	set_gpios(gpios_out_high2, ARRAY_SIZE(gpios_out_high2), 1);
	return 0;
}

static unsigned long long us_to_tick(unsigned long long usec)
{
        usec = usec * get_tbclk() + 999999;
        do_div(usec, 1000000);

        return usec;
}

void board_late_specific_init(void)
{
	unsigned long long stop = get_ticks() + us_to_tick(800000);
	int reason = *(int *)(CONFIG_RESET_CAUSE_ADDR + 4);

	/* return if not power-on reset */
	if ((reason != 0x01) && (reason != 0x11))
		return;

	while (get_ticks() < stop) {
		int ret = gpio_get_value(GP_MAIN_POWER_BUTTON);
		if (ret) {
			printf("On button not held\n");
			board_poweroff();
		}
		mdelay(10);
	}
}

const struct button_key board_buttons[] = {
	{"input1",	GP_INPUT1,	'1', 1},
	{"input2",	GP_INPUT2,	'2', 1},
	{"power",	GP_MAIN_POWER_BUTTON,	'P', 1},
	{NULL, 0, 0, 0},
};

#ifdef CONFIG_CMD_BMODE
const struct boot_mode board_boot_modes[] = {
	/* 4 bit bus width */
	{"mmc0",	MAKE_CFGVAL(0x40, 0x30, 0x00, 0x00)},
	{"mmc1",	MAKE_CFGVAL(0x40, 0x38, 0x00, 0x00)},
	{NULL,		0},
};
#endif

static int _do_poweroff(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	board_poweroff();
	return 0;
}

U_BOOT_CMD(
	poweroff, 70, 0, _do_poweroff,
	"power down board",
	""
);
