#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer 1st node where value is located or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	size_t size = 0;

	if (!list)
		return (NULL);

	while (current)
	{
		size++;
		current = current->next;
	}

	current = list;

	while (current->next && current->n < value)
	{
		if (!current->express || current->express->n > value)
		{
			printf("Value checked at index [%d] = [%d]\n", current->n, current->n);
			current = current->next;
		} else
		{
			printf("Value checked at index [%d] = [%d]\n",
					current->express->n, current->express->n);
			current = current->express;
		}
	}

	printf("Value found between indexes [%d] and [%d]\n", current->n, current->n);

	while (current && current->n < value)
	{
		printf("Value checked at index [%d] = [%d]\n", current->n, current->n);
		current = current->next;
	}

	if (current && current->n == value)
		return (current);

	return (NULL);
}
