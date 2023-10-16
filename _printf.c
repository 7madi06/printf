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

int _printf(char *format, ...)
{
	unsigned int i = 0, count = 0, *p_i = &i;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case '\0':
				va_end(args);
				return (-1);
			case '%':
				count += p_print();
				i++;
				break;
			case 'c':
				count += print_char(va_arg(args, int));
				i++;
				break;
			default:
				count += handle_specifiers(args, format[i + 1], p_i);
			}
		} else
			_putchar(format[i]);
			count++;
	}
	va_end(args);
	return ((int) count);
}
/**
 * handle_specifiers - handles the rest of the specifiers
 * @args: the args list
 * @ch: the specifier
 * @p_i: pointer to i
 * Return: int
 */
int handle_specifiers(va_list args, char ch, unsigned int *p_i)
{
	unsigned int *p_i_count = p_i;
	int count = 0, tempNum;
	char *c;

	switch (ch)
	{
		case 's':
			c = va_arg(args, char *);
			if (c == NULL)
				count += print_string("(null)");
			else
				count += print_string(c);
			*p_i_count = *p_i_count + 1;
			break;
		case 'd':
		case 'i':
			tempNum = va_arg(args, int);
			id_print(tempNum);
			count += int_len(tempNum);
			*p_i_count = *p_i_count + 1;
			break;
		default:
			count += print_char('%') + print_char(ch);
			*p_i_count = *p_i_count + 1;
	}
	return (count);
}
