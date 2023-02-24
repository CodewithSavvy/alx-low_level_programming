#include "main.h"

/**
 * _isupper - checks if c is  an upper case letter
 * @c: character to be checked for
 * Return: 1 otherwise 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

