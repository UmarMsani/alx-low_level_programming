#include "main.h"
/**
 * get_bit - Returns value of a bit at a given index
 * @v: Number to extract the bit from
 * @index: Index of the bit to extract, Starting from 0
 *
 * Return: Value of the bit at index, or -1 if an error occurred
 */
int get_bit(unsigned long int v, unsigned int index)
{
	unsigned long int vask;
	int bits;

	/* Check if index is out of bounds */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* Shift the number to the left by index bits */
	vask = 1UL << index;
	/* Use bitwise AND to get the value of the bit at the index */
	bits = (v & vask) != 0;

	return (bits);
}
