#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 *
 * @n: The number to extract the bit from.
 * @index: The index of the bit to extract, starting from 0.
 *
 * Returns: the value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;
	int bit;

	/* Check if index is out of bounds */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* Shift the number to the left by index bits */
	mask = 1UL << index;
	/* Use bitwise AND to get the value of the bit at the index */
	bit = (n & mask) != 0;

	return (bit);
}
