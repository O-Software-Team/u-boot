/*
 * Copyright 2018 NXP
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __SEC_DSIM_DPHY_LN14LPP_H__
#define __SEC_DSIM_DPHY_LN14LPP_H__

/* DPHY timings structure */
struct sec_mipi_dsim_dphy_timing {
	uint32_t bit_clk;	/* MHz */

	uint32_t clk_prepare;
	uint32_t clk_zero;
	uint32_t clk_post;
	uint32_t clk_trail;

	uint32_t hs_prepare;
	uint32_t hs_zero;
	uint32_t hs_trail;

	uint32_t lpx;
	uint32_t hs_exit;
};

#define DSIM_DPHY_TIMING(bclk, cpre, czero, cpost, ctrail,	\
			 hpre, hzero, htrail, lp, hexit)	\
	.bit_clk	= bclk,					\
	.clk_prepare	= cpre,					\
	.clk_zero	= czero,				\
	.clk_post	= cpost,				\
	.clk_trail	= ctrail,				\
	.hs_prepare	= hpre,					\
	.hs_zero	= hzero,				\
	.hs_trail	= htrail,				\
	.lpx		= lp,					\
	.hs_exit	= hexit

/* descending order based on 'bit_clk' value */
static const struct sec_mipi_dsim_dphy_timing dphy_timing_ln14lpp_v1p2[] = {
	{ DSIM_DPHY_TIMING(2100, 19, 91, 22, 19, 20, 35, 22, 15, 26), },
	{ DSIM_DPHY_TIMING(2090, 19, 91, 22, 19, 19, 35, 22, 15, 26), },
	{ DSIM_DPHY_TIMING(2080, 19, 91, 21, 18, 19, 35, 22, 15, 26), },
	{ DSIM_DPHY_TIMING(2070, 18, 90, 21, 18, 19, 35, 22, 15, 25), },
	{ DSIM_DPHY_TIMING(2060, 18, 90, 21, 18, 19, 34, 22, 15, 25), },
	{ DSIM_DPHY_TIMING(2050, 18, 89, 21, 18, 19, 34, 22, 15, 25), },
	{ DSIM_DPHY_TIMING(2040, 18, 89, 21, 18, 19, 34, 21, 15, 25), },
	{ DSIM_DPHY_TIMING(2030, 18, 88, 21, 18, 19, 34, 21, 15, 25), },
	{ DSIM_DPHY_TIMING(2020, 18, 88, 21, 18, 19, 34, 21, 15, 25), },
	{ DSIM_DPHY_TIMING(2010, 18, 87, 21, 18, 19, 34, 21, 15, 25), },
	{ DSIM_DPHY_TIMING(2000, 18, 87, 21, 18, 19, 33, 21, 15, 25), },
	{ DSIM_DPHY_TIMING(1990, 18, 87, 21, 18, 18, 33, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1980, 18, 86, 21, 18, 18, 33, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1970, 17, 86, 21, 17, 18, 33, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1960, 17, 85, 21, 17, 18, 33, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1950, 17, 85, 21, 17, 18, 32, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1940, 17, 84, 20, 17, 18, 32, 21, 14, 24), },
	{ DSIM_DPHY_TIMING(1930, 17, 84, 20, 17, 18, 32, 20, 14, 24), },
	{ DSIM_DPHY_TIMING(1920, 17, 84, 20, 17, 18, 32, 20, 14, 24), },
	{ DSIM_DPHY_TIMING(1910, 17, 83, 20, 17, 18, 32, 20, 14, 23), },
	{ DSIM_DPHY_TIMING(1900, 17, 83, 20, 17, 18, 32, 20, 14, 23), },
	{ DSIM_DPHY_TIMING(1890, 17, 82, 20, 17, 18, 31, 20, 14, 23), },
	{ DSIM_DPHY_TIMING(1880, 17, 82, 20, 17, 17, 31, 20, 14, 23), },
	{ DSIM_DPHY_TIMING(1870, 17, 81, 20, 17, 17, 31, 20, 14, 23), },
	{ DSIM_DPHY_TIMING(1860, 16, 81, 20, 17, 17, 31, 20, 13, 23), },
	{ DSIM_DPHY_TIMING(1850, 16, 80, 20, 16, 17, 31, 20, 13, 23), },
	{ DSIM_DPHY_TIMING(1840, 16, 80, 20, 16, 17, 30, 20, 13, 23), },
	{ DSIM_DPHY_TIMING(1830, 16, 80, 20, 16, 17, 30, 20, 13, 22), },
	{ DSIM_DPHY_TIMING(1820, 16, 79, 20, 16, 17, 30, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1810, 16, 79, 19, 16, 17, 30, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1800, 16, 78, 19, 16, 17, 30, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1790, 16, 78, 19, 16, 17, 30, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1780, 16, 77, 19, 16, 16, 29, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1770, 16, 77, 19, 16, 16, 29, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1760, 16, 77, 19, 16, 16, 29, 19, 13, 22), },
	{ DSIM_DPHY_TIMING(1750, 15, 76, 19, 16, 16, 29, 19, 13, 21), },
	{ DSIM_DPHY_TIMING(1740, 15, 76, 19, 15, 16, 29, 19, 13, 21), },
	{ DSIM_DPHY_TIMING(1730, 15, 75, 19, 15, 16, 28, 19, 12, 21), },
	{ DSIM_DPHY_TIMING(1720, 15, 75, 19, 15, 16, 28, 19, 12, 21), },
	{ DSIM_DPHY_TIMING(1710, 15, 74, 19, 15, 16, 28, 18, 12, 21), },
	{ DSIM_DPHY_TIMING(1700, 15, 74, 19, 15, 16, 28, 18, 12, 21), },
	{ DSIM_DPHY_TIMING(1690, 15, 73, 19, 15, 16, 28, 18, 12, 21), },
	{ DSIM_DPHY_TIMING(1680, 15, 73, 18, 15, 16, 28, 18, 12, 21), },
	{ DSIM_DPHY_TIMING(1670, 15, 73, 18, 15, 15, 27, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1660, 15, 72, 18, 15, 15, 27, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1650, 14, 72, 18, 15, 15, 27, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1640, 14, 71, 18, 15, 15, 27, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1630, 14, 71, 18, 15, 15, 27, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1620, 14, 70, 18, 14, 15, 26, 18, 12, 20), },
	{ DSIM_DPHY_TIMING(1610, 14, 70, 18, 14, 15, 26, 17, 12, 20), },
	{ DSIM_DPHY_TIMING(1600, 14, 70, 18, 14, 15, 26, 17, 12, 20), },
	{ DSIM_DPHY_TIMING(1590, 14, 69, 18, 14, 15, 26, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1580, 14, 69, 18, 14, 15, 26, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1570, 14, 68, 18, 14, 15, 26, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1560, 14, 68, 18, 14, 14, 25, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1550, 14, 67, 18, 14, 14, 25, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1540, 13, 67, 17, 14, 14, 25, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1530, 13, 66, 17, 14, 14, 25, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1520, 13, 66, 17, 14, 14, 25, 17, 11, 19), },
	{ DSIM_DPHY_TIMING(1510, 13, 66, 17, 13, 14, 24, 17, 11, 18), },
	{ DSIM_DPHY_TIMING(1500, 13, 65, 17, 13, 14, 24, 16, 11, 18), },
	{ DSIM_DPHY_TIMING(1490, 13, 65, 17, 13, 14, 24, 16, 11, 18), },
	{ DSIM_DPHY_TIMING(1480, 13, 64, 17, 13, 14, 24, 16, 11, 18), },
	{ DSIM_DPHY_TIMING(1470, 13, 64, 17, 13, 14, 24, 16, 11, 18), },
	{ DSIM_DPHY_TIMING(1460, 13, 63, 17, 13, 13, 24, 16, 10, 18), },
	{ DSIM_DPHY_TIMING(1450, 13, 63, 17, 13, 13, 23, 16, 10, 18), },
	{ DSIM_DPHY_TIMING(1440, 13, 63, 17, 13, 13, 23, 16, 10, 18), },
	{ DSIM_DPHY_TIMING(1430, 12, 62, 17, 13, 13, 23, 16, 10, 17), },
	{ DSIM_DPHY_TIMING(1420, 12, 62, 17, 13, 13, 23, 16, 10, 17), },
	{ DSIM_DPHY_TIMING(1410, 12, 61, 16, 13, 13, 23, 16, 10, 17), },
	{ DSIM_DPHY_TIMING(1400, 12, 61, 16, 13, 13, 23, 16, 10, 17), },
	{ DSIM_DPHY_TIMING(1390, 12, 60, 16, 12, 13, 22, 15, 10, 17), },
	{ DSIM_DPHY_TIMING(1380, 12, 60, 16, 12, 13, 22, 15, 10, 17), },
	{ DSIM_DPHY_TIMING(1370, 12, 59, 16, 12, 13, 22, 15, 10, 17), },
	{ DSIM_DPHY_TIMING(1360, 12, 59, 16, 12, 13, 22, 15, 10, 17), },
	{ DSIM_DPHY_TIMING(1350, 12, 59, 16, 12, 12, 22, 15, 10, 16), },
	{ DSIM_DPHY_TIMING(1340, 12, 58, 16, 12, 12, 21, 15, 10, 16), },
	{ DSIM_DPHY_TIMING(1330, 11, 58, 16, 12, 12, 21, 15,  9, 16), },
	{ DSIM_DPHY_TIMING(1320, 11, 57, 16, 12, 12, 21, 15,  9, 16), },
	{ DSIM_DPHY_TIMING(1310, 11, 57, 16, 12, 12, 21, 15,  9, 16), },
	{ DSIM_DPHY_TIMING(1300, 11, 56, 16, 12, 12, 21, 15,  9, 16), },
	{ DSIM_DPHY_TIMING(1290, 11, 56, 16, 12, 12, 21, 15,  9, 16), },
	{ DSIM_DPHY_TIMING(1280, 11, 56, 15, 11, 12, 20, 14,  9, 16), },
	{ DSIM_DPHY_TIMING(1270, 11, 55, 15, 11, 12, 20, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1260, 11, 55, 15, 11, 12, 20, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1250, 11, 54, 15, 11, 11, 20, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1240, 11, 54, 15, 11, 11, 20, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1230, 11, 53, 15, 11, 11, 19, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1220, 10, 53, 15, 11, 11, 19, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1210, 10, 52, 15, 11, 11, 19, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1200, 10, 52, 15, 11, 11, 19, 14,  9, 15), },
	{ DSIM_DPHY_TIMING(1190, 10, 52, 15, 11, 11, 19, 14,  8, 14), },
	{ DSIM_DPHY_TIMING(1180, 10, 51, 15, 11, 11, 19, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1170, 10, 51, 15, 10, 11, 18, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1160, 10, 50, 15, 10, 11, 18, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1150, 10, 50, 15, 10, 11, 18, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1140, 10, 49, 14, 10, 10, 18, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1130, 10, 49, 14, 10, 10, 18, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1120, 10, 49, 14, 10, 10, 17, 13,  8, 14), },
	{ DSIM_DPHY_TIMING(1110,  9, 48, 14, 10, 10, 17, 13,  8, 13), },
	{ DSIM_DPHY_TIMING(1100,  9, 48, 14, 10, 10, 17, 13,  8, 13), },
	{ DSIM_DPHY_TIMING(1090,  9, 47, 14, 10, 10, 17, 13,  8, 13), },
	{ DSIM_DPHY_TIMING(1080,  9, 47, 14, 10, 10, 17, 13,  8, 13), },
	{ DSIM_DPHY_TIMING(1070,  9, 46, 14, 10, 10, 17, 12,  8, 13), },
	{ DSIM_DPHY_TIMING(1060,  9, 46, 14, 10, 10, 16, 12,  7, 13), },
	{ DSIM_DPHY_TIMING(1050,  9, 45, 14,  9, 10, 16, 12,  7, 13), },
	{ DSIM_DPHY_TIMING(1040,  9, 45, 14,  9, 10, 16, 12,  7, 13), },
	{ DSIM_DPHY_TIMING(1030,  9, 45, 14,  9,  9, 16, 12,  7, 12), },
	{ DSIM_DPHY_TIMING(1020,  9, 44, 14,  9,  9, 16, 12,  7, 12), },
	{ DSIM_DPHY_TIMING(1010,  8, 44, 13,  9,  9, 15, 12,  7, 12), },
	{ DSIM_DPHY_TIMING(1000,  8, 43, 13,  9,  9, 15, 12,  7, 12), },
	{ DSIM_DPHY_TIMING( 990,  8, 43, 13,  9,  9, 15, 12,  7, 12), },
	{ DSIM_DPHY_TIMING( 980,  8, 42, 13,  9,  9, 15, 12,  7, 12), },
	{ DSIM_DPHY_TIMING( 970,  8, 42, 13,  9,  9, 15, 12,  7, 12), },
	{ DSIM_DPHY_TIMING( 960,  8, 42, 13,  9,  9, 15, 11,  7, 12), },
	{ DSIM_DPHY_TIMING( 950,  8, 41, 13,  9,  9, 14, 11,  7, 11), },
	{ DSIM_DPHY_TIMING( 940,  8, 41, 13,  8,  9, 14, 11,  7, 11), },
	{ DSIM_DPHY_TIMING( 930,  8, 40, 13,  8,  8, 14, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 920,  8, 40, 13,  8,  8, 14, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 910,  8, 39, 13,  8,  8, 14, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 900,  7, 39, 13,  8,  8, 13, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 890,  7, 38, 13,  8,  8, 13, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 880,  7, 38, 12,  8,  8, 13, 11,  6, 11), },
	{ DSIM_DPHY_TIMING( 870,  7, 38, 12,  8,  8, 13, 11,  6, 10), },
	{ DSIM_DPHY_TIMING( 860,  7, 37, 12,  8,  8, 13, 11,  6, 10), },
	{ DSIM_DPHY_TIMING( 850,  7, 37, 12,  8,  8, 13, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 840,  7, 36, 12,  8,  8, 12, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 830,  7, 36, 12,  8,  8, 12, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 820,  7, 35, 12,  7,  7, 12, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 810,  7, 35, 12,  7,  7, 12, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 800,  7, 35, 12,  7,  7, 12, 10,  6, 10), },
	{ DSIM_DPHY_TIMING( 790,  6, 34, 12,  7,  7, 11, 10,  5,  9), },
	{ DSIM_DPHY_TIMING( 780,  6, 34, 12,  7,  7, 11, 10,  5,  9), },
	{ DSIM_DPHY_TIMING( 770,  6, 33, 12,  7,  7, 11, 10,  5,  9), },
	{ DSIM_DPHY_TIMING( 760,  6, 33, 12,  7,  7, 11, 10,  5,  9), },
	{ DSIM_DPHY_TIMING( 750,  6, 32, 12,  7,  7, 11,  9,  5,  9), },
	{ DSIM_DPHY_TIMING( 740,  6, 32, 11,  7,  7, 11,  9,  5,  9), },
	{ DSIM_DPHY_TIMING( 730,  6, 31, 11,  7,  7, 10,  9,  5,  9), },
	{ DSIM_DPHY_TIMING( 720,  6, 31, 11,  7,  6, 10,  9,  5,  9), },
	{ DSIM_DPHY_TIMING( 710,  6, 31, 11,  6,  6, 10,  9,  5,  8), },
	{ DSIM_DPHY_TIMING( 700,  6, 30, 11,  6,  6, 10,  9,  5,  8), },
	{ DSIM_DPHY_TIMING( 690,  5, 30, 11,  6,  6, 10,  9,  5,  8), },
	{ DSIM_DPHY_TIMING( 680,  5, 29, 11,  6,  6,  9,  9,  5,  8), },
	{ DSIM_DPHY_TIMING( 670,  5, 29, 11,  6,  6,  9,  9,  5,  8), },
	{ DSIM_DPHY_TIMING( 660,  5, 28, 11,  6,  6,  9,  9,  4,  8), },
	{ DSIM_DPHY_TIMING( 650,  5, 28, 11,  6,  6,  9,  9,  4,  8), },
	{ DSIM_DPHY_TIMING( 640,  5, 28, 11,  6,  6,  9,  8,  4,  8), },
	{ DSIM_DPHY_TIMING( 630,  5, 27, 11,  6,  6,  9,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 620,  5, 27, 11,  6,  6,  8,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 610,  5, 26, 10,  6,  5,  8,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 600,  5, 26, 10,  6,  5,  8,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 590,  5, 25, 10,  5,  5,  8,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 580,  4, 25, 10,  5,  5,  8,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 570,  4, 24, 10,  5,  5,  7,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 560,  4, 24, 10,  5,  5,  7,  8,  4,  7), },
	{ DSIM_DPHY_TIMING( 550,  4, 24, 10,  5,  5,  7,  8,  4,  6), },
	{ DSIM_DPHY_TIMING( 540,  4, 23, 10,  5,  5,  7,  8,  4,  6), },
	{ DSIM_DPHY_TIMING( 530,  4, 23, 10,  5,  5,  7,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 520,  4, 22, 10,  5,  5,  7,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 510,  4, 22, 10,  5,  5,  6,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 500,  4, 21, 10,  5,  4,  6,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 490,  4, 21, 10,  5,  4,  6,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 480,  4, 21,  9,  4,  4,  6,  7,  3,  6), },
	{ DSIM_DPHY_TIMING( 470,  3, 20,  9,  4,  4,  6,  7,  3,  5), },
	{ DSIM_DPHY_TIMING( 460,  3, 20,  9,  4,  4,  5,  7,  3,  5), },
	{ DSIM_DPHY_TIMING( 450,  3, 19,  9,  4,  4,  5,  7,  3,  5), },
	{ DSIM_DPHY_TIMING( 440,  3, 19,  9,  4,  4,  5,  7,  3,  5), },
	{ DSIM_DPHY_TIMING( 430,  3, 18,  9,  4,  4,  5,  7,  3,  5), },
	{ DSIM_DPHY_TIMING( 420,  3, 18,  9,  4,  4,  5,  6,  3,  5), },
	{ DSIM_DPHY_TIMING( 410,  3, 17,  9,  4,  4,  5,  6,  3,  5), },
	{ DSIM_DPHY_TIMING( 400,  3, 17,  9,  4,  3,  4,  6,  3,  5), },
	{ DSIM_DPHY_TIMING( 390,  3, 17,  9,  4,  3,  4,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 380,  3, 16,  9,  4,  3,  4,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 370,  2, 16,  9,  3,  3,  4,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 360,  2, 15,  9,  3,  3,  4,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 350,  2, 15,  9,  3,  3,  3,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 340,  2, 14,  8,  3,  3,  3,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 330,  2, 14,  8,  3,  3,  3,  6,  2,  4), },
	{ DSIM_DPHY_TIMING( 320,  2, 14,  8,  3,  3,  3,  5,  2,  4), },
	{ DSIM_DPHY_TIMING( 310,  2, 13,  8,  3,  3,  3,  5,  2,  3), },
	{ DSIM_DPHY_TIMING( 300,  2, 13,  8,  3,  3,  3,  5,  2,  3), },
	{ DSIM_DPHY_TIMING( 290,  2, 12,  8,  3,  2,  2,  5,  2,  3), },
	{ DSIM_DPHY_TIMING( 280,  2, 12,  8,  3,  2,  2,  5,  2,  3), },
	{ DSIM_DPHY_TIMING( 270,  2, 11,  8,  3,  2,  2,  5,  2,  3), },
	{ DSIM_DPHY_TIMING( 260,  1, 11,  8,  3,  2,  2,  5,  1,  3), },
	{ DSIM_DPHY_TIMING( 250,  1, 10,  8,  2,  2,  2,  5,  1,  3), },
	{ DSIM_DPHY_TIMING( 240,  1,  9,  8,  2,  2,  1,  5,  1,  3), },
	{ DSIM_DPHY_TIMING( 230,  1,  8,  8,  2,  2,  1,  5,  1,  2), },
	{ DSIM_DPHY_TIMING( 220,  1,  8,  8,  2,  2,  1,  5,  1,  2), },
	{ DSIM_DPHY_TIMING( 210,  1,  7,  7,  2,  2,  1,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 200,  1,  7,  7,  2,  2,  1,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 190,  1,  7,  7,  2,  1,  1,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 180,  1,  6,  7,  2,  1,  0,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 170,  1,  6,  7,  2,  1,  0,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 160,  1,  6,  7,  2,  1,  0,  4,  1,  2), },
	{ DSIM_DPHY_TIMING( 150,  0,  5,  7,  2,  1,  0,  4,  1,  1), },
	{ DSIM_DPHY_TIMING( 140,  0,  5,  7,  1,  1,  0,  4,  1,  1), },
	{ DSIM_DPHY_TIMING( 130,  0,  4,  7,  1,  1,  0,  4,  0,  1), },
	{ DSIM_DPHY_TIMING( 120,  0,  4,  7,  1,  1,  0,  4,  0,  1), },
	{ DSIM_DPHY_TIMING( 110,  0,  3,  7,  1,  0,  0,  4,  0,  1), },
	{ DSIM_DPHY_TIMING( 100,  0,  3,  7,  1,  0,  0,  3,  0,  1), },
	{ DSIM_DPHY_TIMING(  90,  0,  2,  7,  1,  0,  0,  3,  0,  1), },
	{ DSIM_DPHY_TIMING(  80,  0,  2,  6,  1,  0,  0,  3,  0,  1), },
};

#endif
