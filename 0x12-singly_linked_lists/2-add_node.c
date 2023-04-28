#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Add a new node to the beginning of a list_t list.
 * @head: A pointer to the pointer to the head node of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: If successful - a pointer to the new node.
 *         If failed - NULL.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
