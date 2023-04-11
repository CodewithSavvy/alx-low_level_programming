#include "main.h"
/**
 * * append_text_to_file - Appends text at the end of a file.
 * * @filename: A pointer to the name of the file.
 * * @text_content: The string to add to the end of the file.
 * *
 * * Return: If the function fails or filename is NULL - -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int loop, k, lenght = 0;

	/**checking if there is no empty filename*/
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (lenght = 0; text_content[lenght];)
			lenght++;
	}
	loop = open(filename, O_WRONLY | O_APPEND);
	k = write(loop, text_content, lenght);
	/**checking if loop == signed in */

	if (loop == -1 || k == -1)
		return (-1);
	close(loop);
	return (1);
}
