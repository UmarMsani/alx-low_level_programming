#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts new node at given position
 * in dlistint_t linked list.
 * @h: Double pointer to the head of the linked list.
 * @idx: Index where the new node should be added (starting from 0).
 * @n: Value to be added to the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int count = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (count < idx - 1)
	{
		if (temp == NULL)
			return (NULL);

		temp = temp->next;
		count++;
	}

	if (temp == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;

	if (temp->next != NULL)
		temp->next->prev = new_node;

	temp->next = new_node;

	return (new_node);
}
