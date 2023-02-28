#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to an integer argument.
 * @b: pointer to to an integer argument.
 * Description: a function that swaps the values of two integers.
 */
void swap_int(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}
