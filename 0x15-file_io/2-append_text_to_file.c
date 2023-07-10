#include "main.h"

/**
 * append_text_to_file - appends text at end of file
 * @filename: pointer name of file
 * @text_content: string to add to end of file
 *
 * Return: if file don't exist user write permission -1 otherwise 1
 * if function fails or filename is null -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f, w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	f = open(filename, O_WRONLY | O_APPEND);
	w = write(f, text_content, len);

	if (f == -1 || w == -1)
		return (-1);
	close(f);
	return (1);
}
