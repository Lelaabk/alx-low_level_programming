#include "main.h"
/**
 * flip_bits - counts number of bits to change
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, i = 0;
	unsigned long int curr, exl = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		curr = exl >> x;
		if (curr & 1)
			i++;
	}
	return (i);
}
