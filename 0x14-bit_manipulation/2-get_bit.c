#include "main.h"

/**
 * get_bit - returns value of bit at index in dec number
 * @n: to search
 * @index: index of bit
 *
 * Return: value of bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bitV;

	if (index > 63)
		return (-1);
	bitV = (n >> index) & 1;

	return (bitV);
}
