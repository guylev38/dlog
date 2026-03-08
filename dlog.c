/**
 * @file dlog.c
 * @author guylev38
 * @brief A logging module for C projects.
 * @date 07/03/2026
 */

/*** Headers ***/

#include <stdio.h>
#include <time.h>
#include "dlog.h"

/*** Consts ***/

const char *LEVEL_STRINGS[LOG_LEVEL_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};

/*** Functions ***/

void DLOG_format_prefix(log_level_t level, char *file, int line, const char *func, char *prefix)
{
    char time_buf[20];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(time_buf, sizeof(time_buf), "%d/%m/%Y %H:%M:%S", t);

    sprintf(prefix, DEFAULT_FMT, time_buf, LEVEL_STRINGS[level], file, line, func);
}

void DLOG_dispatch_log(log_level_t level, char *file, int line, const char *func, char *fmt, va_list args)
{
    char buffer[MAX_LOG_LENGTH];
    char prefix[MAX_LOG_LENGTH];

    DLOG_format_prefix(level, file, line, func, prefix);

    vsnprintf(buffer, sizeof(buffer), fmt, args);

    fprintf(stdout, "%s %s", prefix, buffer);
}

void DLOG_dispatch_log_entry(log_level_t level, char *file, int line, const char *func, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    DLOG_dispatch_log(level, file, line, func, fmt, args);
    va_end(args);
}