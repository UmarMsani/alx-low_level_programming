#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer to the head node of the linked list
 * @idx: index of the list where the new node should be added (starts at 0)
 * @n: data to be stored in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/* initialize a counter for the nodes */
	unsigned int i = 0;
	/* declare pointers for the new node and a temporary node */
	listint_t *new_node, *temp;

	/* if head is NULL, the list is empty */
	if (head == NULL)
		return (NULL);

	/* allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	/* if malloc fails, return NULL */
	if (new_node == NULL)
		return (NULL);

	/* set the data value of the new node */
	new_node->n = n;

	/* if the new node should be inserted at the beginning of the list */
	if (idx == 0)
	{
		/* set the next pointer of the new node to the current head */
		new_node->next = *head;
		/* set the head to point to the new node */
		*head = new_node;
		/* return the address of the new node */
		return (new_node);
	}

	/* start at the head node */
	temp = *head;

	/* loop until the end of the list or the position before the index */
	while (temp != NULL && i < idx - 1)
	{
		/* move to the next node */
		temp = temp->next;
		/* increment the node counter */
		i++;
	}

	/* if the index is out of range or the next node is NULL */
	if (temp == NULL || temp->next == NULL)
	{
		/* free the allocated memory for the new node */
		free(new_node);
		return (NULL);
	}

	/* set the next pointer of the new node to the node after the current node */
	new_node->next = temp->next;
	/* set the next pointer of the current node to the new node */
	temp->next = new_node;
	/* return the address of the new node */
	return (new_node);
}
