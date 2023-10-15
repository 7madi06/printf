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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);

					count += print_char(c);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					count += p_print();
					break;
				default:
					count += print_char('%') + print_char(*format);
					break;
			}
		} else
			count += print_char(*format);

		format++;
	}
	va_end(args);
	return (count);
}
