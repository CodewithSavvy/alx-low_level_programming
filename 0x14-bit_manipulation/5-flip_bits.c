#include "main.h"

/**
 *  *flip_bits - function that returns the number of bits to flip
 *  *@n: the value
 *  *@m: the value flip
 *  *Return: number of bits fliped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int keep, push = 0;

	keep = n ^ m;

	while (keep)
	{
		push += (keep & 1);
		keep >>= 1;
	}

	return (push);
}
