#include <stdio.h>
#include "main.h"

/**
 * main - prints each passed argument on a new line
 * @argc: arg count
 * @argv: array of pointers to arg values
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;

	argc = argc;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
