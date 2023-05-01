#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to a pointer to the head node of the list
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	/* loop until the head pointer becomes NULL */
	while (*head != NULL)
	{
		/* save the next pointer of the current node */
		next = (*head)->next;
		/* reverse next pointer of current node to point to the previous node */
		(*head)->next = prev;
		/* move the prev pointer to the current node */
		prev = *head;
		/* move the head pointer to the next node */
		*head = next;
	}

	/* set head pointer to the new first node of reversed list */
	*head = prev;
	/* return a pointer to the first node of the reversed list */
	return (prev);
}
