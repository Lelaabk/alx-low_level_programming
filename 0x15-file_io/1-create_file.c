#include "main.h"

/**
 * create_file - Create a file
 * @filename: pointer name of file to create
 * @text_content: pointer to string to write to file
 *
 * Return: if function fails -1 otherwise 1
 */

int create_file(const char *filename, char *text_content)
{
	int f, w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(f,  text_content, len);
	if (f == -1 || w == -1)
		return (-1);
	close(f);
	return (1);
}
