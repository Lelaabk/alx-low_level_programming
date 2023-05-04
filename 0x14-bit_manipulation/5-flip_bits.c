#include "main.h"
/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another one
 * @n: the first number
 * @m: the second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, c = 0;
	unsigned long int curr, exl = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		curr = exl >> x;
		if (curr & 1)
			c++;
	}
	return (c);
}
