#include "search_algos.h"

/**
 * print_array - Prints an array between given indices
 * @array: Pointer to the first element of the array
 * @left: Left index of the array
 * @right: Right index of the array
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; ++i)
	{
		if (i != left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Searches for a value in a
 * sorted array using Binary search recursively
 * @array: Pointer to the first element of the array
 * @left: Left index of the array
 * @right: Right index of the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left <= right)
	{
		print_array(array, left, right);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
		{
			if (mid == left || array[mid - 1] != value)
				return (mid);
			else
				return (advanced_binary_recursive(array, left, mid, value));
		}

		if (array[mid] < value)
			return (advanced_binary_recursive(array, mid + 1, right, value));
		else
			return (advanced_binary_recursive(array, left, mid - 1, value));
	}
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array using
 * Advanced Binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
