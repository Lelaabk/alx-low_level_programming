#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_bff(char *file);
void close_file(int f);

/**
 * create_bff - Allocate 1024 bytes for buff
 * @file: name of file buff stores chars
 *
 * Return: pointer to new allocated buff
 */

char *create_bff(char *file)
{
	char *bff;

	bff = malloc(sizeof(char) * 1024);
	if (bff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (bff);
}

/**
 * close_file - closes file descriptors
 * @f: file descriptore to be closed
 */

void close_file(int f)
{
	int cl;

	cl = close(f);
	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f);
		exit(100);
	}
}

/**
 * main - copies the contents of file to another file
 * @argc: number of arguments supplied tp program
 * @argv: array of pointers to arguments
 *
 * Return: 0 on success
 *
 * Description: if argument count is incorrect - exit code 97
 * if file_from does not exist or cannot be read - exit code 98
 * if file_to cannot be created or written to - exit code 99
 * if file_to or file_from cannot be closed - exit code 100
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff = create_bff(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}
		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}
		r = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buff);
	close_file(from);
	close_file(to);
	return (0);
}
