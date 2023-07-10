#include "main.h"

/**
 * * create_file - Creates a file.
 * * @filename: A pointer to the name of the file to be created.
 * * @text_content: A pointer to a NULL terminated
 * * string to write to the file
 * *
 * * Return: If the function fails - -1.
 * *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int ost;
	int width;
	int lenth;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenth = 0; text_content[lenth];)
			lenth++;
	}

	ost = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	width = write(ost, text_content, lenth);

	if (ost == -1 || width == -1)
		return (-1);

	close(ost);

	return (1);
}
