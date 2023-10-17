#include "main.h"

int _printf(const char *format, ...)
{
	va_list argList;
	char ch = va_arg(argList, int);
	char *strng = va_arg(argList, char*);
	int printChar = 0;

	if (format == NULL)
		return (-1);

	va_start(argList, format);

	while (*format)
	{
	switch (*format)
	{
	case '%':
		format++;
		switch (*format)
		{
		case '\0': 
			break;
		case '%':
			write(1, format, 1);
			printChar ++;
			break;
		case 'c':
			write(1, &ch, 1);
			printChar++;
			break;
			case 's':
			write(1, strng, strlen(strng));
			printChar += strlen(strng);
			break;
               	default:
			break;
		}
		break;
	default: 
		write(1, format, 1);
		printChar++;
		break;
	}
	format++;
	}
    
	va_end(argList);
    
	return (printChar);
}
