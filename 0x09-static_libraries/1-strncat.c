#include "main.h"

/**
 * _strncat - concatenates two strings.
 * @dest: string to be modified parameter
 * @src: string to be copied to the end of dest parameter
 * @n: numbers of chars to be copied from src to dest.
 * Return: pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; *(dest  + i) != '\0'; i++)
	{
	}
	for (j = 0; *(src + j) != '\0'; j++)
	{
		if (j < n)
		{
			*(dest + i) = *(src + j);
			i++;
		}
	}
	*(dest + i) = '\0';
	return (dest);
}
