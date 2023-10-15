#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints chars
 * @character: integer
 *
 * Return: integer
 */

int print_char (int character)
{
	_putchar(character);
	return (1);
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
