/**
 * Copyright (c) 2020 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

enum { LOGC_TRACE, LOGC_DEBUG, LOGC_INFO, LOGC_WARN, LOGC_ERROR, LOGC_FATAL };
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define LOG_VERSION "0.1.0"

typedef struct {
        va_list ap;
        const char *fmt;
        const char *file;
        struct tm *time;
        void *udata;
        int line;
        int level;
} log_Event;

typedef void (*log_LogFn)(log_Event *ev);
typedef void (*log_LockFn)(bool lock, void *udata);

void log_trace(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
void log_debug(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
void log_info(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
void log_warn(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
void log_error(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));
void log_fatal(const char *file, int line, const char *fmt, ...) __attribute__((format(printf, 3, 4)));

#define L(...) log_info(__FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#ifdef DEBUG
#define Ld(...) log_debug(__FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#else
#define Ld(...)
#endif
#define Lw(...) log_warn(__FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Le(...) log_error(__FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)
#define Lf(...) log_fatal(__FILE_NAME__, __LINE__ __VA_OPT__(, ) __VA_ARGS__)

const char *log_level_string(int level);
void log_set_lock(log_LockFn fn, void *udata);
void log_set_level(int level);
void log_set_quiet(bool enable);
int log_add_callback(log_LogFn fn, void *udata, int level);
int log_add_fp(FILE *fp, int level);

void log_log(int level, const char *file, int line, const char **fmt, va_list args);

#endif
