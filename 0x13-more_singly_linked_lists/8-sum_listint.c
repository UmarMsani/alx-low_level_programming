#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a linked list
 * @head: pointer to the head node of the linked list
 *
 * Return: sum of all the data (n) of the linked list, or 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	/* initialize sum to 0 */
	int sum = 0;

	/* loop through all nodes of the linked list */
	while (head != NULL)
	{
		/* add the data of the current node to sum */
		sum += head->n;

		/* move to the next node */
		head = head->next;
	}

	/* return the sum of all the data */
	return (sum);
}
