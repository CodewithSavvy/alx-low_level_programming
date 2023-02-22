#include "main.h"

/**
 * print_sign -  function that prints the sign of a number
 * @n: the number to be printed
 * Return: 1 else if -1 else 0
 */

int print_sign(int n)
{
	int n = 0;

	if (n > 0)
	{
		putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		putchar('0');
		return (0);
	}
	else
	{
		putchar('-');
		return (-1);
	}
}
