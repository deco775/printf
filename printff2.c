#include "main.h"
/**
 * _printf - duplicate the printf funtion
 * format == c - handles the %c format
 * format == s - handles the %s format
 * format == % - handles the double %
 *
 * Return: the number of charecters printed
 */

int _printf(const char *format, ...) {
    int charC = 0;
    va_list argL;
    char *stng = va_arg(argL, char*);
    int strLen = 0;

    if (format == NULL)
        return (-1);

    va_start(argL, format);

    while (*format)
    {
        if (*format != '%')
       	{
           _putchar(*format);
            charC++;
        }
       	else
       	{
            format++;
            if (*format == '\0')
            {
                break;
            }
	    else if (*format == 's')
	    {

                while (stng[strLen] != '\0')
	       	{
                    _putchar(stng[strLen]);
                    strLen++;
                    charC++;
                }
            }
            if (*format == '%')
	    {
                _putchar('%');
                charC++;
            }
	    else if (*format == 'c')
	    {
                char cha = va_arg(argL, int);
                _putchar(cha);
                charC++;
            } 
        }
        format++;
    }

    va_end(argL);

    return (charC);
}
