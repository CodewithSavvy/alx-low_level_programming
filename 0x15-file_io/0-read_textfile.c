#include "main.h"
#include <stdlib>

/**
 * * read_textfile- Read text file print to STDOUT.
 * * @filename: text file being read
 * * @letters: number of letters to be read
 * * Return: w- actual number of bytes read and printed
 * * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fptr, k, i;

	/***opening the file ***/
	fptr = open(filename, O_RDONLY);

	/**checking if fptr is signed number*/
	if (fptr == -1)
		return (0);

	/*Asigning space for malloc*/
	buffer = malloc(sizeof(char) * letters);
	i = read(fptr, buffer, letters);
	k = write(STDOUT_FILENO, buffer, i);
	free(buffer);
	close(fptr);
	return (k);
}
