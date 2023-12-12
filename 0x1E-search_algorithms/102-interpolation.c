#include "search_algos.h"

/**
 * interpolation_search - search a value in sorted array using I search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t k, l, m;

	if (array == NULL)
		return (-1);

	for (l = 0, m = size - 1; m >= l;)
	{
		k = l + (((double)(m - l) / (array[m] - array[l])) * (value - array[l]));
		if (k < size)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", k);
			break;
		}

		if (array[k] == value)
			return (k);
		if (array[k] > value)
			m = k - 1;
		else
			m = k + 1;
	}

	return (-1);
}
