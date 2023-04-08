#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * atoi - converts string to an integer
 * @argc: stores num of cmd-line arg
 * @argv: is array of char pointer
 * Return: 1 if Error, 0 (success)
 */

int main(int argc, char *argv[])
{
	int i, count;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i += 2)
		{
			if (argv[i + 1])
				count = atoi(argv[i]) * atoi(argv[i + 1]);
			else
				count = atoi(argv[i]);
		}
		printf("%d\n", count);
	}
	return (0);
}
