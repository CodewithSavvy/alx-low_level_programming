#include "main.h"

/**
 * *get_endianness - function that checks the endianness
 * *Return: always 0
 */

int get_endianness(void)
{
	int push = 1;
	char *q = (char *)&push;

	if (*q == 1)
		return (1);

	return (0);
}
