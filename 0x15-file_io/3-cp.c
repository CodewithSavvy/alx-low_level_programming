#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *my_buffer(char *name);
void end_file(int ef);

/**
 * my_buffer - Gives 1024 bytes for a buffer.
 * @name: Name of the file storing char
 * Return: return buffer
 */
char *my_buffer(char *name)
{
	char *new;

	new = malloc(sizeof(char) * 1024);

	if (new == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: unable to write to %s\n", name);
		exit(99);
	}

	return (new);
}

/**
 * end_file - file descriptors close
 * @ef: descriptor to be closed
 */
void end_file(int ef)
{
	int pick;

	pick = close(ef);

	if (pick == -1)
	{
		dprintf(STDERR_FILENO, "Error: unable to close fd %d\n", ef);
		exit(100);
	}
}

/**
 * * main - Copies file content to another file.
 * * @argc: The number of arguments
 * * @argv: Array of pointers to the arguments
 * * Return: always 0
 */
int main(int argc, char *argv[])
{
	int begin, run, fwrite, v;
	char *argname;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	argname = my_buffer(argv[2]);
	begin = open(argv[1], O_RDONLY);
	fwrite = read(begin, argname, 1024);
	run = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (begin == -1 || fwrite == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to read from file %s\n", argv[1]);
			free(argname);
			exit(98);
		}

		v = write(run, argname, fwrite);
		if (run == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to  write to %s\n", argv[2]);
			free(argname);
			exit(99);
		}

		fwrite = read(begin, argname, 1024);
		run = open(argv[2], O_WRONLY | O_APPEND);

	} while (fwrite > 0);

	free(argname);
	end_file(begin);
	end_file(run);

	return (0);
}
