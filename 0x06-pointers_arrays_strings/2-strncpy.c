#include "main.h"

/**
 * *_strncpy - copies a part of the string pointed to by src
 * @dest: pointer to string destination parameter
 * @src: pointer to string origin parameter
 * @n: number of chars to be copied.
 * Return: pointer to a char dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;

	while (j < n && *(src + j) != '\0')
	{
		*(dest + j) = *(src + j);
		j++;
	}
	while (j < n)
	{
		*(dest + j) = '\0';
		j++;
	}

	return (dest);
}
