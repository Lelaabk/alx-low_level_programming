#include "main.h"

/**
 * print_binary - prints binary of decimal number
 * @n: number to show in binary
 */
void print_binary(unsigned long int n)
{
	int x, i;
	unsigned long int curr;

	for (x = 63; x >= 0; x--)
	{
		curr = n >> x;
		if (curr & 1)
		{
			_putchar('1');
			i++;
		}
		else if (i)
			_putchar('0');
	}
	if (!i)
		_putchar('0');
}
