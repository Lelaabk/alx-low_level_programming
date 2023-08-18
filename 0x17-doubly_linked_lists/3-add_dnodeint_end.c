#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end
 * of dlistint_t list
 *
 * @head: head of list
 * @n: balue of element
 * Return: address of new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new;
	}
	else
		*head = new;
	new->prev = h;
	return (new);
}
