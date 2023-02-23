#include "main.h"

/**
 * print_last_digit - printing the last digit of a number
 *@num: the the number to be printed its last value
 *Return: the vlue of the last digit
 */

int print_last_digit(int num)
{
	int num = 98;
	int last;

	last = number % 10;

	putchar(last);
	return (last);
}
