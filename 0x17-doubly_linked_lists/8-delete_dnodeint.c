#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node a at given index
 * in a dlistint_t linked list.
 * @head: Double pointer to the head of the linked list.
 * @index: Index of the node to be deleted (starting from 0).
 *
 * Return: 1 if deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1); /* List is empty*/

	dlistint_t *current = *head;
	unsigned int count = 0;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (count < index - 1)
	{
		if (current == NULL)
			return (-1); /* Index is out of bounds*/

		current = current->next;
		count++;
	}

	if (current == NULL || current->next == NULL)
		return (-1); /* Index is out of bounds*/

	dlistint_t *node_to_delete = current->next;

	current->next = node_to_delete->next;

	if (node_to_delete->next != NULL)
		node_to_delete->next->prev = current;

	free(node_to_delete);

	return (1);
}
