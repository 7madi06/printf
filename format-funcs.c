#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints chars
 * @character: integer
 *
 * Return: integer
 */
int print_char(int character)
{
	_putchar((char) character);
	return (1);
}

/**
 * print_string - prints strings
 * @str: string
 *
 * Return: integer
 */
int print_string(char *str)
{
	int i = 0;
	int count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
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

/**
 * id_print - prints %i and %d
 * @n: the integer to print
 *
 *
 * Return: integer
 */
void id_print(int n)
{
	unsigned int m;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}
	else
		m = n;
	if (m / 10)
	{
		id_print(m / 10);
	}
	_putchar(m % 10 + '0');
}

/**
 * int_len - counts num len of int
 * @n: the integer to print
 *
 *
 * Return: integer
 */
int int_len(int n)
{
	int count = 0;

	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}