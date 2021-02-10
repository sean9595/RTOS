/*
 * stdio.h
 *
 *  Created on: Jan 31, 2021
 * Arranged by: Kim Taehoon
 */
#ifndef LIB_STDIO_H_
#define LIB_STDIO_H_

#include "stdint.h"
#include "haluart.h"
#include "stdarg.h"

#define PRINTF_BUF_LEN  1024

static char printf_buf[PRINTF_BUF_LEN];   // 1KB
typedef enum utoa_t
{
    utoa_dec = 10,
    utoa_hex = 16,
} utoa_t;

uint32_t putstr(const char* s); //Read only access to the pointer parameter
                                //In that case, put a 'const' in front of the pointer parameter.
uint32_t debug_printf(const char* format, ...);
uint32_t vsprintf(char* buf, const char* format, va_list arg);
uint32_t utoa(char* buf, uint32_t val, utoa_t base);

#endif /* LIB_STDIO_H_ */