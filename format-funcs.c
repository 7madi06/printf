#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints character from the %c specifier
 * @args : args
 * @count: count
 *
 * Return: integer
 */

void print_char(va_list args, int *count)
{
	char c = (char)va_arg(args, int);

	*count += _putchar(c);
}

/**
* print_string - prints a string.
* @args : args
* @count : int
*/

void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	_puts(str);
	while (*str != '\0')
	{
		(*count)++;
		str++;
	}
}

/**
 * p_print - prints percent
 *
 * Return: integer
 */
int p_print(void)
{
	_putchar('%');
	return (1);
}
