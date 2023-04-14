#include "main.h"

/**
 *  *read_textfile - function that reads a text file and prints output
 *  *@filename: pointer to file name
 *  *@letters: the letters in the file to be read
 *  *Return: actual number of letters the file  reads and prints
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *get;
	ssize_t bring;
	int begin, pick;

	if (filename == NULL)
		return (0);

	get = malloc(sizeof(char) * letters);
	/*checking if get is pointing to nothing*/
	if (get == NULL)
		return (0);

	begin = open(filename, O_RDONLY);
	pick = read(begin, get, letters);
	bring = write(STDOUT_FILENO, get, pick);

	if (begin == -1 || pick == -1 || bring == -1 || bring != pick)
	{
		free(get);
		return (0);
	}

	free(get);
	close(begin);

	return (bring);
}
