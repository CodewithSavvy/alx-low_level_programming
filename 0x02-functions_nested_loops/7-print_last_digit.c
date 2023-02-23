#include "main.h"

/**
 * print_last_digit - printing the last digit of a number
 *@num: the the number to be printed its last value
 *Return: the vlue of the last digit
 */

int print_last_digit(int num)
{
	int last;

	last = num % 10;
	if (last < 0)
	{
		last = last * -1;
	}

	_putchar(last + '0');
	return (last);
}
