#include "main.h"
/**
 * * set_bit - sets a bit at a provided index to 1
 * * @n: pointer to value to change
 * * @index: index provide for the bit to be set to 1
 * *
 * * Return: 1 for pass, -1 for fail
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	/*return fial if index provide is greater than 63*/
	if (index > 63)
		return (-1);

	/*dereferencing the value at provided index to 1*/
	*n = ((1UL << index) | *n);
	return (1);
}
