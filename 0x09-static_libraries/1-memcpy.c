#include "main.h"

/**
 * _memcpy - function
 * @dest : where to copy to
 * @src : where to copy from
 * @n : the number of times we will fill the memory
 * Return: memory.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
