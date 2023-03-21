#include <stdio.h>
/**
 * main - Prints the sum of even-valued Fibonacci sequence
 *        terms not exceeding 4000000.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long fibosum, fib1 = 0, fib2 = 1;
	float total_sum;

	while (1)
	{
		fibosum = fib1 + fib2;
		if (fibosum > 4000000)
			break;

		if ((fibosum % 2) == 0)
			total_sum += fibosum;

		fib1 = fib2;
		fib2 = fibosum;
	}
	printf("%.0f\n", total_sum);

	return (0);
}
