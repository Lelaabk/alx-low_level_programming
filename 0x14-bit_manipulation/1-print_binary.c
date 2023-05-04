#include "main.h"
/**
 * print_binary - prints binary equivalent of decimal number
 * @n: number to print in bin
 */
void print_binary(unsigned long int n)
{
	unsigned long int curr;
	int x, c;

	for (x = 63; x >= 0; i--)
	{
		curr = n >> x;
		if (curr & 1)
		{
			_putchar('1');
			c++;
		}
		else if (c)
			_putchar('0');
	}
	if (!c)
		_putchar(c);
}
