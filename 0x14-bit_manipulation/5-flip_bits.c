#include "main.h"

/**
 * * flip_bits - counts the number of bits to be change
 * * to get from one number to another
 * * @n: first number to be
 * * @m: second number to be
 * *
 * * Return: number of bits to change if succeed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int loop, check = 0;
	unsigned long int temp, XOR = n ^ m;

	for (loop = 63; loop >= 0; loop--)
	{
		temp = XOR >> loop;
		if (temp & 1)
			check++;
	}
	return (check);
}
