#include "main.h"

/**
 * get_endianness - checks that if machine is lil or big endian
 *
 * Return: 1 for little and 0 for big
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *ch = (char *) &x;

	return (*ch);
}
