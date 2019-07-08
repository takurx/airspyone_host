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