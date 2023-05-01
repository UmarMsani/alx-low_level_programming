#include "lists.h"

/**
 * main - function that prints a listint_t linked list.
 * If the function fails, exit the program with status 98
 * Returns: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_ptr = head, *fast_ptr = head;
	size_t count = 0;

	while (fast_ptr != NULL && fast_ptr->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		count++;
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr)
		{
			printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
			count++;
			printf("-> [%p] %d\n", (void *)slow_ptr->next, slow_ptr->next->n);
			count++;
			slow_ptr = slow_ptr->next;
			while (head != slow_ptr)
			{
				printf("[%p] %d\n", (void *)head, head->n);
				count++;
				head = head->next;
				slow_ptr = slow_ptr->next;
			}
			return (count);
		}
	}

	while (slow_ptr != NULL)
	{
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		count++;
		slow_ptr = slow_ptr->next;
	}

	return (count);
}
