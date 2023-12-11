#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the array
 * @left: Left index of the array to search
 * @right: Right index of the array to search
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int binary_search(int *array, int left, int right, int value)
{
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - Search a value in sorted array using Expo. search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int i;
	int left = i / 2;
	int right = (i < size) ? i : size - 1;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	i = 1;

	while (i < size && array[i] <= value)
		i *= 2;

	return (binary_search(array, left, right, value));
}
