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
	set_bit(&v, 5);
	printf("%lu\n", v);
	v = 0;
	set_bit(&v, 10);
	printf("%lu\n", v);
	v = 98;
	set_bit(&v, 0);
	printf("%lu\n", v);
	return (0);
}
