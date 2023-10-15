#include <unistd.h>

/**
* _puts - prints a string.
* @str : int
*/

void _puts(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
