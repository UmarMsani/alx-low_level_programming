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
	dlistint_t *current = *head;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1); /* List is empty*/

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (count < index)
	{
		if (current == NULL)
			return (-1); /* Index is out of bounds*/

		current = current->next;
		count++;
	}

	if (current == NULL)
		return (-1); /* Index is out of bounds*/

	if (current->prev != NULL)
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);

	return (1);
}
