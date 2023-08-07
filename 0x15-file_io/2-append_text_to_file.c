#include "main.h"

/**
 *  *append_text_to_file - function that appends text at the end of a file
 *  *@filename: pointer to the file
 *  *@text_content: a NULL terminated string to write to the file
 *  *Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ost, width, lenth = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenth = 0; text_content[lenth];)
			lenth++;
	}

	ost = open(filename, O_WRONLY | O_APPEND);
	width = write(ost, text_content, lenth);

	if (ost == -1 || width == -1)
		return (-1);

	close(ost);

	return (1);
}
