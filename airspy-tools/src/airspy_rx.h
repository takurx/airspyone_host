/*
 * rtl-sdr, turns your Realtek RTL2832 based DVB dongle into a SDR receiver
 * Copyright (C) 2012-2013 by Steve Markgraf <steve@steve-m.de>
 * Copyright (C) 2012 by Dimitri Stolnikov <horiz0n@gmx.net>
 * Copyright (C) 2019, Yoshihiro Nakagawa <yoshihiro.nakagawa@warpspace.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __AIRSPY_RX_H
#define __AIRSPY_RX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../libairspy/src/airspy.h"

typedef struct rtlsdr_dev rtlsdr_dev_t;

typedef void(*rtlsdr_read_async_cb_t)(unsigned char *buf, uint32_t len, void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* __AIRSPY_RX_H */