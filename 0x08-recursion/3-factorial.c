#include "main.h"
/**
 * factorial - factorial of int
 * @n:int
 * Return:int
 */
int factorial(int n)
{
	int sum;

	if (n > 0)
		sum = n * factorial(n - 1);
	else if (n == 0)
		return (1);
	else if (n < 0)
	{
		return (-1);
	}
	return (sum);
}
