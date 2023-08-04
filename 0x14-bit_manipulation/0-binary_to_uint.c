#include "main.h"

/**
 * *binary_to_uint - function that manipulates a binary
 * number to an unsigned int
 * *@b: pointer to the string of 0 and i char.
 * *Return: the manipulated number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int total = 0;
	int u;

	if (!b)
		return (0);

	for (u = 0; b[u]; u++)
	{
		if (b[u] != '0' && b[u] != '1')
			return (0);

		total = (total << 1) | (b[u] - '0');

	}
	return (total);

}
