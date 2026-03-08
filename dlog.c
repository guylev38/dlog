/**
 * @file dlog.c
 * @author guylev38
 * @brief A logging module for C projects.
 * @date 07/03/2026
 */

/*** Headers ***/

#include <sys/types.h>
#include <stdio.h>
#include "dlog.h"

/*** Functions ***/

dlog_status_e DLOG_dispatch_log(__u_char *file, u_int32_t line, __u_char *msg, logger_t *logger)
{
    dlog_status_e ret_code = DLOG_STATUS_UNINITIALIZED;

l_cleanup:
    ret_code = DLOG_STATUS_SUCCESS;
    return ret_code;
}