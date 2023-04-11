#include "main.h"

/**
 * * create_file - Creates a file.
 * * @filename: A pointer to the name of the file to create.
 * * @text_content: A pointer to a string to write to the file.
 * *
 * * Return: If the function fails
 */

int create_file(const char *filename, char *text_content)
{
	int fptr, k, length = 0;

	/**checking if the arguement place for filename is not empty*/
	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	/*opening the file to be worked with*/
	fptr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(fptr, text_content, length);
	if (fptr == -1 || k == -1)
		return (-1);
	close(fptr);
	return (1);
}

