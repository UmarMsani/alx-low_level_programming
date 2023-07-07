#include "main.h"
/**
 * clear_bit - Sets the value of bit to 0 at a Given index
 * @v: Pointer to the unsigned long int whose bit is to be cleared
 * @index: index of the bit to be cleared
 * Return: 1 if it worked, or -1 if error.
 */
int clear_bit(unsigned long int *v, unsigned int index)
{
	/* Declare the mask variable before any other statements */
	unsigned long int vask;

	/* Check if index is within valid range for the unsigned long int type */
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	/* Create a mask with a 1 in the bit position to be cleared */
	vask = 1UL << index;

	/*Invert mask to have 0 in bit position to be cleared and 1 in other bits*/
	vask = ~vask;

	/* Clear the bit at the specified index by ANDing with the inverted mask */
	*v &= vask;

	/* Return success */
	return (1);
}
