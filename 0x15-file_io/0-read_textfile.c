#include <stdlib.h>
#include "main.h"
/**
 * read_textfile- Read text file print it to stdout
 * @filename: text file to be read
 * @letters: number of letters being read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fl, w, r;
	char *buff;

	fl = open(filename, O_RDONLY);
	if (fl == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	r = read(fl, buff, letters);
	w = write(STDOUT_FILENO, buff, r);
	free(buff);
	close(fl);
	return (w);
}
