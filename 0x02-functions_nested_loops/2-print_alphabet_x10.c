#include "main.h"

/**
 * print_alphabet_x10 - function that prints 10 times the alphabet
 */

void print_alphabet_x10(void)
{
	char l;
	int count = 0;

	while (count++ <= 9)
	{
		for (l = 'a'; l <= 'z'; l++)
			_putchar(l);
		_putchar('\n');
	}
}
