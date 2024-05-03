/* Copyright (C) 2022-2024 Kevin Alavik and contributors.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "printf.h"
#include <stdio.h>

int _printf(const char *fmt, ...)
{
    __builtin_va_list argp;
    __builtin_va_start(argp, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            switch (*fmt)
            {
            case 'd':
                printf("%d", __builtin_va_arg(argp, int));
                break;
            case 'f':
                printf("%f", __builtin_va_arg(argp, double));
                break;
            case 'c':
                printf("%c", __builtin_va_arg(argp, int));
                break;
            case 's':
                printf("%s", __builtin_va_arg(argp, char *));
                break;
            default:
                putchar('%');
                putchar(*fmt);
                break;
            }
        }
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }

    __builtin_va_end(argp);

    printf("\n");
    return 0;
}

int _dprintf(const char *fmt, ...)
{
    return 0;
}

int main()
{
    _printf("This is a %s %d", "test", 123);
}