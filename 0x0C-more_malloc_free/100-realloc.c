#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *oldp;
	unsigned int i;

	if (new_size == old_size)
		return (p);

	if (new_size == 0 && p)
	{
		free(p);
		return (NULL);
	}

	if (!p)
		return (malloc(new_size));
	p1 = malloc(new_size);
	if (!p1)
		return (NULL);
	oldp = p;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			p[i] = oldp[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p1[i] = oldp[i];
	}
	free(p);
	return (p1);
}
