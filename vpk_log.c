
#include "vpk_log.h"

#ifdef IPHONE
static FILE* log_file = NULL;
#elif defined(ANDROID) && defined(ANDROID_NDK)
#include "ftk_jni.h"
#endif

typedef enum{
	eLevelInfor=0,
	eLevelVer,
	eLevelDbg,
	eLevelWar,
	eLevelErr,
}eLogLev;

char *levstr[]={
		"[INF]",
		"[VER]",
		"[DBG]",
		"[WAR]",
		"[ERR]",
};
	

static FtkLogLevel default_log_level = FTK_LOG_I;
FtkLogLevel ftk_default_log_level()
{
	return default_log_level;
}

int ftk_log(eLogLev lev, const char* format, va_list ap)
{
	char buffer[1024] = {0};
	ftk_vsnprintf(buffer, sizeof(buffer), format, ap);

	printf("%s", levstr[lev]);
	printf("%s", buffer);

#ifdef IPHONE
	if(log_file == NULL)
	{
		char* filename = "log_file.txt";
		log_file = fopen(filename, "a+");
		if(log_file == NULL)
		{
			return RET_OK;
		}
	}
	fprintf(log_file, buffer);
	fflush(log_file);
#elif defined(ANDROID) && defined(ANDROID_NDK)
	Android_Log(buffer);
#endif

	return RET_OK;
}

int ftk_logv(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(ftk_default_log_level() <= FTK_LOG_V)
	{
		ftk_log(eLevelVer, format, ap);
	}
	va_end(ap);
	
	return RET_OK;
}

int ftk_logd(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(ftk_default_log_level() <= FTK_LOG_D)
	{
		ftk_log(eLevelDbg, format, ap);
	}
	va_end(ap);

	return RET_OK;
}

int ftk_logi(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(ftk_default_log_level() <= FTK_LOG_I)
	{
		ftk_log(eLevelInfor, format, ap);
	}
	va_end(ap);
	
	return RET_OK;
}

int ftk_logw(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(ftk_default_log_level() <= FTK_LOG_W)
	{
		ftk_log(eLevelWar, format, ap);
	}
	va_end(ap);
	
	return RET_OK;
}

int ftk_loge(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if(ftk_default_log_level() <= FTK_LOG_E)
	{
		ftk_log(eLevelErr, format, ap);
	}
	va_end(ap);
	
	return RET_OK;
}


