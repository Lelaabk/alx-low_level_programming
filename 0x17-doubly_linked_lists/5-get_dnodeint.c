#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of dlistint_t
 * linked list
 * @head: pointer to head of list
 * @index: index of node to search for, starting from 0
 * Return: nth node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int size;

	size = 0;
	if (head == NULL)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		if (index == size)
			return (tmp);
		size++;
		tmp = tmp->next;
	}
	return (NULL);
}
