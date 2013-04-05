#ifndef FTK_LOG_H
#define FTK_LOG_H

#include <stdarg.h>

#if defined(__GNUC__)
int ftk_logv(const char* format, ...) __attribute__((format (printf, 1, 2)));
int ftk_logd(const char* format, ...) __attribute__((format (printf, 1, 2)));
int ftk_logi(const char* format, ...) __attribute__((format (printf, 1, 2)));
int ftk_logw(const char* format, ...) __attribute__((format (printf, 1, 2)));
int ftk_loge(const char* format, ...) __attribute__((format (printf, 1, 2)));
#else
int ftk_logv(const char* format, ...);
int ftk_logd(const char* format, ...);
int ftk_logi(const char* format, ...);
int ftk_logw(const char* format, ...);
int ftk_loge(const char* format, ...);
#endif /* __GNUC__ */

typedef enum _FtkLogLevel
{
	FTK_LOG_V = 0,
	FTK_LOG_D = 1,
	FTK_LOG_I = 2,
	FTK_LOG_W = 3,
	FTK_LOG_E = 4
}FtkLogLevel;

#define ftk_vsnprintf vsnprintf
#define RET_OK 0
#endif/*FTK_LOG_H*/

