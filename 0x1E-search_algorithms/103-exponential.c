#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array using Bnry search
 * @array: Pointer to the first element of the array
 * @left: Left index of the array
 * @right: Right index of the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t j;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (j = left; j < right; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[j]);

		j = left + (right - left) / 2;
		if (array[j] == value)
			return (j);
		if (array[j] > value)
			right = j - 1;
		else
			left = j + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for value in a sorted array
 * using Exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t k = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (k = 1; k < size && array[k] <= value; k = k * 2)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
	}

	right = k < size ? k : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", k / 2, right);
	return (_binary_search(array, k / 2, right, value));
}
