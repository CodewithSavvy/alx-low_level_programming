#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *make_buffer(char *name);
void shut_file(int front);

/**
 *  * make_buffer - Allocates 1024 bytes for a buffer.
 *  * @name: the file buffer is storing chars for.
 *  *
 *  * Return: pointer to the newly-allocated buffer.
 */
char *make_buffer(char *name)
{
	char *buffer_1;

	buffer_1 = malloc(sizeof(char) * 1024);

	if (buffer_1 == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't WRITE to %s\n", name);
		exit(99);
	}

	return (buffer_1);
}

/**
 * * shut_file - Closes file descriptors.
 * * @front: The file descriptor to be closed.
 */
void shut_file(int front)
{
	int shut;

	shut_file = close(front);

	if (shut_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't CLOSE front %d\n", front);
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
	int atend, apend, rd, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = make_buffer(argv[2]);
	atend = open(argv[1], O_RDONLY);
	rd = read(atend, buffer, 1024);
	apend = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (atend == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(apend, buffer, rd);
		if (atend == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rd = read(atend, buffer, 1024);
		atend = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buffer);
	shut_file(atend);
	shut_file(atend);

	return (0);
}

