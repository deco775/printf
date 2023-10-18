#include "main.h"

int _printf(const char *format, ...) {
    int charC = 0;
    va_list argL;

    if (format == NULL)
        return (-1);

    va_start(argL, format);

    while (*format) {
        if (*format != '%') {
           _putchar(*format);
            charC++;
        } else {
            format++;
            if (*format == '\0')
            {
                break;
            }else if (*format == 's') {
                char *string = va_arg(argL, char*);
                int strLen = 0;

                while (string[strLen] != '\0') {
                    _putchar(string[strLen]);
                    strLen++;
                    charC++;
                }
            }
            if (*format == '%') {
                _putchar('%');
                charC++;
            } else if (*format == 'c') {
                char character = va_arg(argL, int);
                _putchar(character);
                charC++;
            } 
        }
        format++;
    }

    va_end(argL);

    return (charC);
}
