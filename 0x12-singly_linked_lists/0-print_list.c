#include <stdio.h>
#include "lists.h"
/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t str = 0;

	while (h)
	{
		if (!h->s)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->s);
		h = h->next;
		str++;
	}
	return (str);
}
