#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - print product of two numbers
 * @argc: arg count
 * @argv: array of pointers to arg values
 * Return: 0, or 1 if Error
 */

int main(int argc, char *argv[])
{
	argc = argc;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int product = 1;
		int i;

		for (i = 1; i < argc; i++)
			product *= atoi(argv[i]);
		printf("%d\n", product);
		return (0);
	}
}

