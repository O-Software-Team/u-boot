# Copyright 2018 NXP
#
# SPDX-License-Identifier: GPL-2.0

obj-$(CONFIG_$(SPL_TPL_)CLK_CCF) += clk-gate2.o clk-pllv3.o clk-pfd.o clk-pfdv2.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX6Q) += clk-imx6q.o
obj-$(CONFIG_CLK_IMX8) += clk-imx8.o

ifdef CONFIG_CLK_IMX8
obj-$(CONFIG_IMX8QXP) += clk-imx8qxp.o
obj-$(CONFIG_IMX8QM) += clk-imx8qm.o
endif
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX8MM) += clk-imx8mm.o clk-pll14xx.o \
				clk-composite-8m.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX8MN) += clk-imx8mn.o clk-pll14xx.o \
				clk-composite-8m.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX8MP) += clk-imx8mp.o clk-hdmimix.o clk-pll14xx.o \
				clk-composite-8m.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX8MQ) += clk-imx8mq.o clk-pll14xx.o \
				clk-composite-8m.o clk-frac-pll.o clk-sccg-pll.o clk-cpu.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMX8ULP) += clk-imx8ulp.o \
				clk-composite-7ulp.o clk-pllv4.o

obj-$(CONFIG_$(SPL_TPL_)CLK_IMXRT1020) += clk-imxrt1020.o
obj-$(CONFIG_$(SPL_TPL_)CLK_IMXRT1050) += clk-imxrt1050.o
