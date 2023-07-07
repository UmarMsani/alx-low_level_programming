#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long int v;

	v = 1024;
	clear_bit(&v, 10);
	printf("%lu\n", v);
	v = 0;
	clear_bit(&v, 10);
	printf("%lu\n", v);
	v = 98;
	clear_bit(&v, 1);
	printf("%lu\n", v);
	return (0);
}
