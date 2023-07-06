#include "main.h"

/**
 * binary_to_uint - changes binary number to unsignet int
 * @b: a string have a binary number
 *
 * Return: the changed number
 */

unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int convertedN;

	if (!b)
		return (0);
	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		convertedN = convertedN * 2 + (b[x] - '0');
	}
	return (convertedN);
}
