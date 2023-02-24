#include "main.h"
/**
 * print_most_numbers - printing digits exluding 2 and 4
 *
 * Return: Always 0
 */

void print_most_numbers(void)
{
	char c;

	for (c = 0; c <= 9; c++)
	{
		if (!(c == 2 || c == 4))
			putchar(c);
	}
	putchar('\n');
	return (0);
}
