#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 * @argc: stores num of cmd-line arg
 * @argv: is array of char poiters
 * Return: 0 if no arg passed, 1 if char arg passed
 */

int main(int argc, char *argv[])
{
	int i, count = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (isdigit(argv[i][0]))
			count += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", count);
	return (0);
}
