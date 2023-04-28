#include "lists.h"

/**
 * list_len - gets the number of nodes
 * @h: pointer to the head (first node)
 * Return: number of nodes
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;

	const list_t *curr = h;

	if (h == NULL)
		return (0);

	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
