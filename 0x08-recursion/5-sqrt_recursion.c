#include "main.h"
/**
 * isTrue - checks for the square root
 * @x:int
 * @y:int
 *
 * Return: int
 */
int isTrue(int x, int y)
{
	if (x * x == y)
		return (x);
	if (x * x > y)
		return (-1);
	return (isTrue(x + 1, y));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (isTrue(1, n));
}
