/**
 * @file dlog.h
 * @author guylev38
 * @brief A logging module for C projects.
 * @date 07/03/2026
 */

#ifndef __DLOG_H__
#define __DLOG_H__

/*** Includes ***/

#include <sys/types.h>
#include <stdarg.h>

/*** Enums ***/

typedef enum log_level_e
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,

    LOG_LEVEL_COUNT
} log_level_t;

/*** Consts ***/

extern const char *LEVEL_STRINGS[LOG_LEVEL_COUNT];
extern const char *DEFAULT_FMT;

/*** Defines ***/

#define MAX_LOG_LENGTH (500)
#define DEFAULT_FMT "[%s] [%s] (%s:%d) %s():"

/*** Structs ***/

/*** Macros ***/

#define DLOG_DEBUG(fmt, ...) DLOG_dispatch_log_entry(DEBUG, __FILE__, __LINE__, __func__, fmt, __VA_ARGS__)
#define DLOG_INFO(fmt, ...) DLOG_dispatch_log_entry(INFO, __FILE__, __LINE__, __func__, fmt, __VA_ARGS__)
#define DLOG_WARNING(fmt, ...) DLOG_dispatch_log_entry(WARNING, __FILE__, __LINE__, __func__, fmt, __VA_ARGS__)
#define DLOG_ERROR(fmt, ...) DLOG_dispatch_log_entry(ERROR, __FILE__, __LINE__, __func__, fmt, __VA_ARGS__)

/*** Functions ***/

void DLOG_format_prefix(log_level_t level, char *file, int line, const char *func, char *prefix);
void DLOG_dispatch_log(log_level_t level, char *file, int line, const char *func, char *fmt, va_list args);
void DLOG_dispatch_log_entry(log_level_t level, char *file, int line, const char *func, char *fmt, ...);

#endif