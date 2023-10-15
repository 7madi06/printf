#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function for formatted output,
 * write output to stdout, the standard output stream,
 * printing text with specified format and variables.
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */


int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '\0':
					va_end(args);
					return (-1);
				case 'c':
					c = (char)va_arg(args, int);

					count += _putchar(c);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%') + _putchar(*format);
					break;
			}
		} else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
