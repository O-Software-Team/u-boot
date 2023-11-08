#ifdef CONFIG_MT8195
static int mt8195_regs[] = {
	[PWRAP_INIT_DONE2] =		0x0,
	[PWRAP_STAUPD_CTRL] =		0x4C,
	[PWRAP_TIMER_EN] =		0x3E4,
	[PWRAP_INT_EN] =		0x420,
	[PWRAP_INT_FLG] =		0x428,
	[PWRAP_INT_CLR] =		0x42C,
	[PWRAP_INT1_EN] =		0x450,
	[PWRAP_INT1_FLG] =		0x458,
	[PWRAP_INT1_CLR] =		0x45C,
	[PWRAP_WACS2_CMD] =		0x880,
	[PWRAP_SWINF_2_WDATA_31_0] =	0x884,
	[PWRAP_SWINF_2_RDATA_31_0] =	0x894,
	[PWRAP_WACS2_VLDCLR] =		0x8A4,
	[PWRAP_WACS2_RDATA] =		0x8A8,
};

static struct pmic_wrapper_type pwrap_mt8195 = {
	.regs = mt8195_regs,
	.type = PWRAP_MT8195,
	.arb_en_all = 0x777f, /* NEED CONFIRM */
	.int_en_all = 0x180000, /* NEED CONFIRM */
	.int1_en_all = 0,
	.spi_w = PWRAP_MAN_CMD_SPI_WRITE,
	.wdt_src = PWRAP_WDT_SRC_MASK_ALL,
	.caps = PWRAP_CAP_INT1_EN | PWRAP_CAP_ARB,
	.init_reg_clock = pwrap_common_init_reg_clock,
	.init_soc_specific = NULL,
};

#define WRAP_MT8195_COMPAT	{ .compatible = "mediatek,mt8195-pwrap", .data = (ulong)&pwrap_mt8195, },
#else
#define WRAP_MT8195_COMPAT
#endif
