#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @str: pointer to array of chars parameter
 * Return: pointer to str
 */
char *rot13(char *str)
{
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	char *strcopy = str;

	while (*str != '\0')
	{
		for (i = 0; i < 52; i++)
			if (*str == input[i])
			{
				*str = output[i];
				break;
			}
		str++;
	}
	return (strcopy);
}
