/*
 * Copyright (C) 2021 Boundary Devices, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/fbpanel.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <i2c.h>
#include <linux/sizes.h>
#include <malloc.h>
#include <mmc.h>
#include <pwm.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#include "../common/bd_common.h"
#include "../common/padctrl.h"
#include <debug_uart.h>

DECLARE_GLOBAL_DATA_PTR;

#define I2C_PAD_CTRL    (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
	PAD_CTL_DSE_40ohm | PAD_CTL_HYS | PAD_CTL_ODE)

#define SPI_PAD_CTRL (PAD_CTL_HYS | PAD_CTL_SPEED_MED |		\
	PAD_CTL_DSE_40ohm | PAD_CTL_SRE_FAST)

#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
	PAD_CTL_DSE_40ohm | PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define USDHC1_CLK_PAD_CTRL (PAD_CTL_SPEED_LOW | \
	PAD_CTL_DSE_40ohm | PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define USDHC1_PAD_CTRL (USDHC1_CLK_PAD_CTRL | PAD_CTL_PUS_47K_UP)

#define USDHC2_CLK_PAD_CTRL (PAD_CTL_SPEED_LOW | \
	PAD_CTL_DSE_40ohm | PAD_CTL_HYS | PAD_CTL_SRE_FAST)

#define USDHC2_PAD_CTRL (USDHC2_CLK_PAD_CTRL | PAD_CTL_PUS_47K_UP)

static const iomux_v3_cfg_t init_pads[] = {
#define GP_BACKLIGHT_LCD	IMX_GPIO_NR(1, 9)
	IOMUX_PAD_CTRL(GPIO1_IO09__GPIO1_IO09, WEAK_PULLDN_OUTPUT),

#define GP_BT_RFKILL_RESET	IMX_GPIO_NR(4, 23)
	IOMUX_PAD_CTRL(CSI_DATA02__GPIO4_IO23, 0x030b0),

	/* ECSPI1 (serial nor eeprom) */
	IOMUX_PAD_CTRL(CSI_DATA07__ECSPI1_MISO, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI_DATA06__ECSPI1_MOSI, SPI_PAD_CTRL),
	IOMUX_PAD_CTRL(CSI_DATA04__ECSPI1_SCLK, SPI_PAD_CTRL),
#define GP_ECSPI1_NOR_CS	IMX_GPIO_NR(4, 26)
	IOMUX_PAD_CTRL(CSI_DATA05__GPIO4_IO26, WEAK_PULLUP_OUTPUT),

	/* Hog */
#define GP_COIN_C		IMX_GPIO_NR(2, 3)
	IOMUX_PAD_CTRL(ENET1_TX_DATA0__GPIO2_IO03, 0x1b0b0),
#define GP_COIN_A		IMX_GPIO_NR(2, 4)
	IOMUX_PAD_CTRL(ENET1_TX_DATA1__GPIO2_IO04, 0x1b0b0),
#define GP_COIN_IN		IMX_GPIO_NR(2, 5)
	IOMUX_PAD_CTRL(ENET1_TX_EN__GPIO2_IO05, 0x1b0b0),
#define GP_COIN_DROP_PWR	IMX_GPIO_NR(2, 6)
	IOMUX_PAD_CTRL(ENET1_TX_CLK__GPIO2_IO06, 0x1b0b0),
#define GP_GPIO_0		IMX_GPIO_NR(2, 0)
	IOMUX_PAD_CTRL(ENET1_RX_DATA0__GPIO2_IO00, 0x1b0b0),
#define GP_GPIO_1		IMX_GPIO_NR(2, 1)
	IOMUX_PAD_CTRL(ENET1_RX_DATA1__GPIO2_IO01, 0x1b0b0),
#define GP_GPIO_2		IMX_GPIO_NR(2, 2)
	IOMUX_PAD_CTRL(ENET1_RX_EN__GPIO2_IO02, 0x1b0b0),
#define GP_GPIO_3		IMX_GPIO_NR(2, 14)
	IOMUX_PAD_CTRL(ENET2_TX_CLK__GPIO2_IO14, 0x1b0b0),
#define GP_GPIO_4		IMX_GPIO_NR(2, 15)
	IOMUX_PAD_CTRL(ENET2_RX_ER__GPIO2_IO15, 0x1b0b0),
#define GP_PROX			IMX_GPIO_NR(2, 7)
	IOMUX_PAD_CTRL(ENET1_RX_ER__GPIO2_IO07, 0x1b0b0),
#define GP_CARD_SENSE		IMX_GPIO_NR(1, 7)
	IOMUX_PAD_CTRL(GPIO1_IO07__GPIO1_IO07, 0x1b0b0),
	/* Test points */

	/* i2c1 - mxc4005 irq */
#define GPIRQ_ACC	IMX_GPIO_NR(4, 24)
	IOMUX_PAD_CTRL(CSI_DATA03__GPIO4_IO24, WEAK_PULLUP),

	/* i2c1 - pn7150 */
#define GP_EN_PN7150	IMX_GPIO_NR(1, 6)
	IOMUX_PAD_CTRL(GPIO1_IO06__GPIO1_IO06, 0x030b0),
#define GPIRQ_PN7150		IMX_GPIO_NR(1, 5)
	IOMUX_PAD_CTRL(GPIO1_IO05__GPIO1_IO05, 0x1b0b0),

	/* i2c2 - is31fl3236 */
#define GP_I2C2_IS31_SHUTDOWN	IMX_GPIO_NR(1, 8)
	IOMUX_PAD_CTRL(GPIO1_IO08__GPIO1_IO08, 0x030b0),

	/* Lcdif */
	IOMUX_PAD_CTRL(LCD_CLK__LCDIF_CLK, 0x79),
	IOMUX_PAD_CTRL(LCD_ENABLE__GPIO3_IO01, 0x30b0),
	IOMUX_PAD_CTRL(LCD_HSYNC__LCDIF_HSYNC, 0x79),
	IOMUX_PAD_CTRL(LCD_VSYNC__LCDIF_VSYNC, 0x79),
	IOMUX_PAD_CTRL(LCD_RESET__LCDIF_RESET, 0x030b0),
	IOMUX_PAD_CTRL(LCD_DATA00__LCDIF_DATA00, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA01__LCDIF_DATA01, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA02__LCDIF_DATA02, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA03__LCDIF_DATA03, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA04__LCDIF_DATA04, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA05__LCDIF_DATA05, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA06__LCDIF_DATA06, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA07__LCDIF_DATA07, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA08__LCDIF_DATA08, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA09__LCDIF_DATA09, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA10__LCDIF_DATA10, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA11__LCDIF_DATA11, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA12__LCDIF_DATA12, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA13__LCDIF_DATA13, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA14__LCDIF_DATA14, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA15__LCDIF_DATA15, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA16__LCDIF_DATA16, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA17__LCDIF_DATA17, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA18__LCDIF_DATA18, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA19__LCDIF_DATA19, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA20__LCDIF_DATA20, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA21__LCDIF_DATA21, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA22__LCDIF_DATA22, 0x79),
	IOMUX_PAD_CTRL(LCD_DATA23__LCDIF_DATA23, 0x79),

	/* pwm3 - backlight */
	IOMUX_PAD_CTRL(GPIO1_IO04__PWM3_OUT, WEAK_PULLDN_OUTPUT),

	/* Regulators */
#define GP_REG_WLAN_VMMC	IMX_GPIO_NR(4, 22)
	IOMUX_PAD_CTRL(CSI_DATA01__GPIO4_IO22, WEAK_PULLDN_OUTPUT),

#define GPIRQ_TS_FT5X06		IMX_GPIO_NR(1, 1)
	IOMUX_PAD_CTRL(GPIO1_IO01__GPIO1_IO01, 0x1b0b0),
#define GP_TS_FT5X06_RESET	IMX_GPIO_NR(1, 2)
	IOMUX_PAD_CTRL(GPIO1_IO02__GPIO1_IO02, 0x030b0),

	/* uart1 */
	IOMUX_PAD_CTRL(UART1_TX_DATA__UART1_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART1_RX_DATA__UART1_DCE_RX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART1_RTS_B__UART1_DCE_RTS, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART1_CTS_B__UART1_DCE_CTS, UART_PAD_CTRL),

	/* uart2 */
	IOMUX_PAD_CTRL(UART2_TX_DATA__UART2_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART2_RX_DATA__UART2_DCE_RX, UART_PAD_CTRL),

	/* uart3 */
	IOMUX_PAD_CTRL(NAND_READY_B__UART3_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_CE0_B__UART3_DCE_RX, UART_PAD_CTRL),

	/* uart4 */
	IOMUX_PAD_CTRL(UART4_TX_DATA__UART4_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART4_RX_DATA__UART4_DCE_RX, UART_PAD_CTRL),

	/* uart5 */
	IOMUX_PAD_CTRL(UART5_TX_DATA__UART5_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(UART5_RX_DATA__UART5_DCE_RX, UART_PAD_CTRL),

	/* uart7 */
	IOMUX_PAD_CTRL(ENET2_RX_EN__UART7_DCE_TX, UART_PAD_CTRL),
	IOMUX_PAD_CTRL(ENET2_TX_DATA0__UART7_DCE_RX, UART_PAD_CTRL),

	/* USB OTG1 */
	IOMUX_PAD_CTRL(GPIO1_IO00__ANATOP_OTG1_ID, WEAK_PULLUP),
	IOMUX_PAD_CTRL(ENET2_RX_DATA0__USB_OTG1_PWR, 0x030b0),
	IOMUX_PAD_CTRL(ENET2_RX_DATA1__USB_OTG1_OC, 0x1b0b0),

	/* USB OTG2 */
	IOMUX_PAD_CTRL(ENET2_TX_DATA1__USB_OTG2_PWR, 0x030b0),
	IOMUX_PAD_CTRL(ENET2_TX_EN__USB_OTG2_OC, 0x1b0b0),

	/* usdhc1 - wifi */
	IOMUX_PAD_CTRL(SD1_CLK__USDHC1_CLK, USDHC1_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(SD1_CMD__USDHC1_CMD, USDHC1_PAD_CTRL),
	IOMUX_PAD_CTRL(SD1_DATA0__USDHC1_DATA0, USDHC1_PAD_CTRL),
	IOMUX_PAD_CTRL(SD1_DATA1__USDHC1_DATA1, USDHC1_PAD_CTRL),
	IOMUX_PAD_CTRL(SD1_DATA2__USDHC1_DATA2, USDHC1_PAD_CTRL),
	IOMUX_PAD_CTRL(SD1_DATA3__USDHC1_DATA3, USDHC1_PAD_CTRL),
#if 0
	IOMUX_PAD_CTRL(GPIO1_IO03__OSC32K_32K_OUT, 0x100b0),		/* slow clock */
#endif
#define GP_BT_UART_WH		IMX_GPIO_NR(4, 21)
	IOMUX_PAD_CTRL(CSI_DATA00__GPIO4_IO21, 0x1b0b0),
#define GPIRQ_WLAN		IMX_GPIO_NR(4, 16)
	IOMUX_PAD_CTRL(NAND_DQS__GPIO4_IO16, 0x1b0b0),

	/* usdhc2 - eMMC */
	IOMUX_PAD_CTRL(NAND_RE_B__USDHC2_CLK, USDHC2_CLK_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_WE_B__USDHC2_CMD, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA00__USDHC2_DATA0, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA01__USDHC2_DATA1, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA02__USDHC2_DATA2, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA03__USDHC2_DATA3, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA04__USDHC2_DATA4, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA05__USDHC2_DATA5, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA06__USDHC2_DATA6, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_DATA07__USDHC2_DATA7, USDHC2_PAD_CTRL),
	IOMUX_PAD_CTRL(NAND_ALE__USDHC2_RESET_B, USDHC2_PAD_CTRL),
};

static const iomux_v3_cfg_t lcd_pwm_pads[] = {
	IOMUX_PAD_CTRL(GPIO1_IO04__PWM3_OUT, WEAK_PULLDN_OUTPUT),
};

static const iomux_v3_cfg_t lcd_pwm_gpio_pads[] = {
#define GP_BACKLIGHT_LCD_PWM3	IMX_GPIO_NR(1, 4)
	IOMUX_PAD_CTRL(GPIO1_IO04__GPIO1_IO04, WEAK_PULLDN_OUTPUT),
};

static const struct i2c_pads_info i2c_pads[] = {
	I2C_PADS_INFO_ENTRY(I2C1, CSI_PIXCLK, 4, 18, CSI_MCLK, 4, 17, I2C_PAD_CTRL),
	I2C_PADS_INFO_ENTRY(I2C2, CSI_HSYNC, 4, 20, CSI_VSYNC, 4, 19, I2C_PAD_CTRL),
};
#define I2C_BUS_CNT	2

#ifdef CONFIG_MXC_SPI
int board_spi_cs_gpio(unsigned bus, unsigned cs)
{
	return (bus == 0 && cs == 0) ? GP_ECSPI1_NOR_CS : (cs >> 8) ? (cs >> 8) : -1;
}
#endif

#ifdef CONFIG_USB_EHCI_MX6
#define USB_OTHERREGS_OFFSET	0x800
#define UCTRL_PWR_POL		(1 << 9)

int board_usb_phy_mode(int port)
{
	if (port == 1)
		return USB_INIT_HOST;
	return usb_phy_mode(port);
}

int board_ehci_hcd_init(int port)
{
	u32 *usbnc_usb_ctrl;

	if (port > 1)
		return -EINVAL;
	usbnc_usb_ctrl = (u32 *)(USB_BASE_ADDR + USB_OTHERREGS_OFFSET +
			port * 4);
	setbits_le32(usbnc_usb_ctrl, UCTRL_PWR_POL);

	return 0;
}

int board_ehci_power(int port, int on)
{
	return 0;
}
#endif

#ifdef CONFIG_FSL_ESDHC_IMX
struct fsl_esdhc_cfg board_usdhc_cfg[] = {
	{.esdhc_base = USDHC2_BASE_ADDR, .bus_width = 8,
			.vs18_enable = 1},
};
#endif

#ifdef CONFIG_CMD_FBPANEL
void board_enable_lcd(const struct display_info_t *di, int enable)
{
	if (enable) {
		/* enable backlight PWM3 */
		pwm_init(2, 0, 0);

		/* 33.3 KHz, duty cycle, period: 30 usec */
		pwm_config(2, 30000*8/10, 30000);
		pwm_enable(2);
		SETUP_IOMUX_PADS(lcd_pwm_pads);
		gpio_set_value(GP_BACKLIGHT_LCD, 1);
	} else {
		gpio_set_value(GP_BACKLIGHT_LCD, 0);
		SETUP_IOMUX_PADS(lcd_pwm_gpio_pads);
		gpio_set_value(GP_BACKLIGHT_LCD_PWM3, 0);
	}
}

static const struct display_info_t displays[] = {

	/* ft5446 */
	VD_PV03505YP54D(LCD, NULL, 1, 0x38),
};
#define display_cnt	ARRAY_SIZE(displays)
#else
#define displays	NULL
#define display_cnt	0
#endif

static const unsigned short gpios_out_low[] = {
	GP_BACKLIGHT_LCD,
	GP_BT_RFKILL_RESET,
	GP_EN_PN7150,
	GP_I2C2_IS31_SHUTDOWN,
	GP_TS_FT5X06_RESET,
	GP_REG_WLAN_VMMC,
};

static const unsigned short gpios_out_high[] = {
	GP_ECSPI1_NOR_CS,
};

static const unsigned short gpios_in[] = {
	GP_COIN_C,
	GP_COIN_A,
	GP_COIN_IN,
	GP_COIN_DROP_PWR,
	GP_GPIO_0,
	GP_GPIO_1,
	GP_GPIO_2,
	GP_GPIO_3,
	GP_GPIO_4,
	GP_PROX,
	GP_CARD_SENSE,
	GP_BT_UART_WH,
	GPIRQ_WLAN,
	GPIRQ_ACC,
	GPIRQ_PN7150,
	GPIRQ_TS_FT5X06,
};

int board_early_init_f(void)
{
	struct mxc_ccm_reg *ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	set_gpios_in(gpios_in, ARRAY_SIZE(gpios_in));
	set_gpios(gpios_out_high, ARRAY_SIZE(gpios_out_high), 1);
	set_gpios(gpios_out_low, ARRAY_SIZE(gpios_out_low), 0);
#if 1
	/* use 24M clock */
	clrsetbits_le32(&ccm->cscdr1, MXC_CCM_CSCDR1_UART_CLK_PODF_MASK,
			MXC_CCM_CSCDR1_UART_CLK_SEL);
#else
	/* ddr-stress test assumes 80M clock */
	clrsetbits_le32(&ccm->cscdr1, MXC_CCM_CSCDR1_UART_CLK_PODF_MASK, 0);
#endif
	SETUP_IOMUX_PADS(init_pads);
	return 0;
}

int board_init(void)
{
	common_board_init(i2c_pads, I2C_BUS_CNT, 0, displays, display_cnt, 0);
	return 0;
}

const struct button_key board_buttons[] = {
	{"card", GP_CARD_SENSE,	'c', 1},
	{NULL, 0, 0, 0},
};

#ifdef CONFIG_CMD_BMODE
const struct boot_mode board_boot_modes[] = {
	{"mmc1", MAKE_CFGVAL(0x60, 0x58, 0x00, 0x00)},
	{NULL, 0},
};
#endif
