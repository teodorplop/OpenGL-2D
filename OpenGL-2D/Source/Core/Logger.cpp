#include "Logger.h"

#include <stdio.h>
#include <stdarg.h>

void Logger::Log(char* format, ...) {
    va_list arg_list;
    va_start(arg_list, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int val = va_arg(arg_list, int);
                printf("%d", val);
            }
            else if (*format == 's') {
                char* val = va_arg(arg_list, char*);
                printf("%s", val);
            }
            else if (*format == 'c') {
                char val = va_arg(arg_list, int);
                printf("%c", val);
            }
            else if (*format == 'f') {
                double val = va_arg(arg_list, double);
                printf("%f", val);
            }
            format++;
        }
        else {
            printf("%c", *format);
            format++;
        }
    }
    va_end(arg_list);

    fputc('\n', stdout);
}
