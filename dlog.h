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
#include "dlog_s.h"

/*** Enums ***/

typedef enum logging_levels_e
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
    FATAL,

    LOGGING_LEVELS_LEN
} logging_levels_e;

/*** Consts ***/

const __u_char *level_strings[] = {"DEBUG", "INFO", "ERROR", "FATAL"};

/*** Structs ***/

typedef struct logger_s
{
    u_int32_t level;
    __u_char *date_fmt;
} logger_t;

/*** Macros ***/

#define log(...) DLOG_dispatch_log(__FILE__, __LINE__, __VA_ARGS__)

/*** Functions ***/

dlog_status_e DLOG_dispatch_log(__u_char *file, u_int32_t line, __u_char *msg, logger_t *logger);

#endif