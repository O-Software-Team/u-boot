/*
 * Copyright (C) 2010-2011 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Boundary Devices bt
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "mx6_common.h"

#define CONFIG_MACH_TYPE	3781

#define CONFIG_IMX_HDMI
#define CONFIG_SYS_FSL_USDHC_NUM	1
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2

#include "boundary.h"
#define CONFIG_EXTRA_ENV_SETTINGS BD_BOUNDARY_ENV_SETTINGS \
	"disable_giga=1\0" \

#endif	       /* __CONFIG_H */
