#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int result;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s filenames text\n", av[0]);
		exit(1);
	}
	result = create_file(av[1], av[2]);
	printf("-> %i)\n", result);
	return (0);
}
