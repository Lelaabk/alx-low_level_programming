#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
/**
 * check_elf - checks if file is ELF file
 * @e_ident: pointer to array containing elf magic numbers
 *
 * Description: if file is not an ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO,  "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * display_magic - display magic numbers of elf header
 * @e_ident: pointer to array containing ELF magic numbers
 *
 * Description: magic numbers are separated by spaces
 */

void display_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_class - displays class of elf header
 * @e_ident: pointer to array containig elf class
 */
void display_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * display_data - displays data of elf header
 * @e_ident: pointer to array containing elf data
 */
void display_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}

}
/**
 * display_version - displays version of elf header
 * @e_ident: pointer to array containing elf version
 */
void display_version(unsigned char *e_ident)
{
	printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * main - displays info contained in elf header at start of elf file
 * @argc: number of arguments supplied to program
 * @argv: array of pointers to arguments
 *
 * Return: 0 in success
 *
 * Description: if file isn't elf file or
 * function fails - exit code 98
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *header;
	int f, r;

	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(f);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(f, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(f);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident);
	display_data(header->e_ident);
	display_version(header->e_ident);

	free(header);
	close_elf(f);
	return (0);

}
