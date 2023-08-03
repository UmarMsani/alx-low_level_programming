#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 *
 * @n: pointer to the unsigned long int to modify
 * @index: the index (starting from 0) of the bit to set
 *
 * This function sets the bit at the given index in the unsigned long int
 * pointed to by @n to 1. The function returns 1 if it succeeds, or -1 if an
 * error occurred (e.g., if the index is out of range)
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	/* check if index is valid */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* set the bit at the given index to 1 */
	*n |= 1UL << index;

	return (1);
}
