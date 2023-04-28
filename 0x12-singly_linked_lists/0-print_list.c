#include "lists.h"

/**
 * print_list - print elements in a linked list
 * @h: pointer to head first node
 * Return: Number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;/* To count the number of nodes*/

	while (h != NULL)
	{
		if (h->str != NULL)
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		h = h->next;
		count++;
	}
	return (count);
}
