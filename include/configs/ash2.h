/*
 * Copyright (C) 2010-2011 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Boundary Devices Ash
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "mx6_common.h"

#define CONFIG_MACH_TYPE	3769

#define CONFIG_MXC_SPI_DISPLAY
#define CONFIG_VIDEO_SKIP_VERSION

#define CONFIG_IMX_HDMI
#define CONFIG_SYS_FSL_USDHC_NUM	1
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2
#define CONFIG_FEC_MXC_KSZ_PHYADDR	7

#include "boundary.h"
#define CONFIG_EXTRA_ENV_SETTINGS BD_BOUNDARY_ENV_SETTINGS \

#endif	       /* __CONFIG_H */
