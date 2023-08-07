#include "main.h"

/**
 *  *read_textfile - function that reads a text file
 *  and prints it to the POSIX standard output.
 *  *@filename: pointer to file to be reead from
 *  *@letters: the letters in the file to be read
 *  *Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *mixed;
	ssize_t backDown;
	int back, down;

	if (filename == NULL)
		return (0);

	mixed = malloc(sizeof(char) * letters);
	if (mixed == NULL)
		return (0);

	back = open(filename, O_RDONLY);
	down = read(back, mixed, letters);
	backDown = write(STDOUT_FILENO, mixed, down);

	if (back == -1 || down == -1 || backDown == -1 || backDown != down)
	{
		free(mixed);
		return (0);
	}

	free(mixed);
	close(back);

	return (backDown);
}
