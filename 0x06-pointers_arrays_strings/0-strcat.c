#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: string parameter
 * @src: string parameter
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i;

	for (i = 0; *(dest + i) != '\0'; i++)
	{

	}
	for (; *src != '\0'; src++)
	{
		*(dest + i) = *src;
		i++;
	}

	*(dest + i) = *src;

	return (dest);
}
