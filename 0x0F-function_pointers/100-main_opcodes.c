#include <stdlib.h>
#include <stdio.h>
/**
* print_opcodes - print the opcodes of this program
* @a: address of the main function
* @n: number of bytes to print
*
* Return: void
*/

void print_opcodes(char *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		printf("%.2hhx", a[x]);
		if (x < n - 1)
			printf(" ");
	}
	printf("\n");
}

/**
* main - prints the opcodes of its own main function
* @argc: number of arguments passed to the function
* @argv: array of pointers to arguments
*
* Return: always O
*/

int main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	i = atoi(argv[1]);
	if (i < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, i);
	return (0);
}
