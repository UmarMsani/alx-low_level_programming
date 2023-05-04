#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary format
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	/* create a bit mask with only the most significant bit set */
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	/* flag to indicate whether we have found the first set bit */
	int found_first_one = 0;

	/* iterate over each bit in the input number */
	while (mask)
	{
		/* if the current bit is set, print '1' */
		if (n & mask)
		{
			found_first_one = 1;
			_putchar('1');
		}
		/*if current bit is not set & we have found first set bit,print '0'*/
		else if (found_first_one || mask == 1)
		{
			_putchar('0');
		}
		/* shift the bit mask one position to the right */
		mask >>= 1;
	}
}
