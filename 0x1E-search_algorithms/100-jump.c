#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array using Jump search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t left = 0;
	size_t right = 0;
	size_t i;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	while (right < size && array[right] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", right, array[right]);
		left = right;
		right += jump;
		if (right > size - 1)
			right = size;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	for (i = left; i < right; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}

