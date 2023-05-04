#include "main.h"

/**
 * flip_bits - counts number of bits that need to be flipped
 * @n: the first number
 * @m: the second number
 *
 * This function takes two unsigned long integers as input & return no. of bits
 * need to be flipped in order to convert one number into the other.
 *
 * Return: the number of bits that need to be flipped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* XOR the two numbers to find the bits that are different */
	unsigned long int xor_result = n ^ m;
	/* Initialize a counter for the number of different bits */
	unsigned int count = 0;

	/*Count no. of set bits in XOR result by shifting it right */
	while (xor_result != 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}
	/* Return the count of different bits */
	return (count);
}
