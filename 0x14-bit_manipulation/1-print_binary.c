#include "main.h"
/**
 * * print_binary - convert nad prints a binary to decimal.
 * * @n: number to be converted and prints in binary
 * *
 * * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int loop, check = 0;
	unsigned long int temp;

	for (loop = 63; loop >= 0; loop--)
	{
		temp = n >> loop;
		if (temp & 1)
		{
			_putchar('1');
			check++;
		}
		else if (check)
			_putchar('0');
	}
	if (!check)
		_putchar('0');
}
