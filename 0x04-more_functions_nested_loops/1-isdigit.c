#include "main.h"

/**
 * _isupper - checks if c is  a number through 0 to 9
 * @c: character to be checked for
 * Return: 1 otherwise 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
