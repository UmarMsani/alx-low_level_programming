#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * struct listint_s - Singly linked list
 *
 * @n: an Integer
 * @index: is anIndex of the node in the list
 * @next: pointer to the next node
 *
 * Description: is a singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
		int n;
		size_t index;
		struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - singly linked list with express lane
 *
 * @n: An integer
 * @index: index of the node in the list
 * @next: is a pointer to the next node
 * @express: Pointer to next node in the express lane
 *
 * Description: Singly linked list node structure with express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
				int n;
				size_t index;
				struct skiplist_s *next;
				struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H */
