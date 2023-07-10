#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 *
 * Return: 0 when filename is null or function fails
 * and w for number of bytes read and printed.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t f, r, w;
	char *bff;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	bff = malloc(sizeof(char) * letters);
	r = read(f, bff, letters);
	w = write(STDOUT_FILENO, bff, r);

	free(bff);
	close(f);
	return (w);
}
