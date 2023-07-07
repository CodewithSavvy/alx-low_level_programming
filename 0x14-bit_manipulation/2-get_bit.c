#include "main.h"

/**
 * *get_bit - function that returns the value of a bit.
 * *@n: value of the bit to be return
 * *@index: the index, starting from 0 of the bit you want to get
 * *Return: the value of the bit at index.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 63)
		return (-1);

	value = (n >> index) & 1;

	return (value);
}
