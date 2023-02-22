#include "main.h"

/**
 * _islower - checking for the alphabet c
 * @c: alphabet to be checked for
 * Return: 1 otherwise 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);

}
