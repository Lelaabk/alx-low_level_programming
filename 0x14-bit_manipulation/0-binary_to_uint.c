#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * binary_to_uint - changes binary number to unsignet int
 * @b: a string have a binary number
 *
 * Return: the changed number
 */

unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int convertedN = 0;

	if (b == NULL)
		return (0);
	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		convertedN = 2 * convertedN + (b[x] - '0');
	}
	return (convertedN);
}
