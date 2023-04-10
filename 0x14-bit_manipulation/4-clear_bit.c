#include "main.h"
/**
 * * clear_bit - sets a bit at a provided index 0
 * * @n: pointer to value to be change
 * * @index: index of the bit to  be clear
 * *
 * * Return: 1 for pass, -1 for fail
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/*return fial if index provide is greater than 63*/

	if (index > 63)
		return (-1);
	/*seting the provided index to 0*/
	*n = (~(1UL << index) & *n);
	return (1);
}
