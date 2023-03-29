#include "main.h"
/**
 * reverse_array - reverse array
 * @ar:array
 * @n:integer
 * Return:void
 */
void reverse_array(int *ar, int n)
{
int i, c;

for (i = 0; (i < (n - 1) / 2); i++)
	{
	c = ar[i];
	ar[i] = ar[n - 1 - i];
	ar[n - 1 - i] = c;
	}
}
