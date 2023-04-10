#include "main.h"
/**
 * * get_bit - returns the value decimal number
 * * @n: number to search
 * * @index: index of the bit of choise
 * *
 * * Return:  the value of the bit at index index
 * * or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_number;

	/*checking to return is an error ocured*/
	if (index > 63)
		return (-1);
	bit_number = (n >> index) & 1;

	return (bit_number);
}
