#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void qt_log_file_create(void);
void qt_log_file_write(uint8_t* dat , uint16_t len);
const char* qt_log_get_rtc_time_str(void);

#ifdef __cplusplus
}
#endif
