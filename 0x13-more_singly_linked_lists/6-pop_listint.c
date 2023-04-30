#include "lists.h"

/**
 * pop_listint - removes the head node of the list
 * @head: ptr to the 1th elem in the linked list
 *
 * Return: 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}
