#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int v;

	v = flip_bits(1024, 1);
	printf("%u\n", v);
	v = flip_bits(402, 98);
	printf("%u\n", v);
	v = flip_bits(1024, 3);
	printf("%u\n", v);
	v = flip_bits(1024, 1025);
	printf("%u\n", v);
	return (0);
}
