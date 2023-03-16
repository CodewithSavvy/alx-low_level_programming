#include <stdlib.h>
#include <stdio.h>

/**
 * checkString - check for integer.
 * @Str: character count
 * Return: 0 if integer 1 otherwise
 */
int checkString(char *Str)
{
	char *ptr = Str;

	while (*ptr)
	{
		if (!(*ptr >= 0x30 && *ptr <= 0x39))
		{
			return (0);
		}
		ptr++;
	}
	return (1);
}

/**
 * main - print sum of +ve integers
 * @argc: arg count
 * @argv: array of pointers to arg values
 * Return: 0, or 1 if Error
 */

int main(int argc, char *argv[])
{
	argc = argc;

	if (argc <= 1)
		printf("0\n");
	else
	{
		int i;
		int sum = 0;

		for (i = 1; i < argc; i++)
		{
			if (checkString(argv[i]))
				sum += atoi(argv[i]);
			else
			{
				printf("Error\n");
				return (1);
			}
		}

		printf("%d\n", sum);
	}

	return (0);
}
