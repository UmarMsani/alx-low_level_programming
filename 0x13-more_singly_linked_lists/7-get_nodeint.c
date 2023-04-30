#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to retrieve (starting from 0)
 *
 * Return: pointer to the nth node, or NULL if it doesn't exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	/* Traverse the list until we reach the desired index */
	for (i = 0; i < index && current != NULL; i++)
	{
		current = current->next;
	}

	/* it means we reached the end of the list before reaching desired index */
	if (current == NULL)
	{
		return (NULL);
	}

	/* Otherwise, we have found the desired node, so we return it */
	return (current);
}
