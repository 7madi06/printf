#include <unistd.h>

/**
* _puts - prints a string.
* @str : int
*/

void _puts(char *str)
{
	char nl = '\n';

	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, &nl, 1);
}
