#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive and negative numbers
 * @argc: stores num of cmd-line arg
 * @argv: is array of char pointers
 * Return: 0 if no arg passed, 1 if invalid arg passed
 */

int main(int argc, char *argv[])
{
	int j, count = 0;

	if (argc == 1)
	{
		printf("%d\n", 0);
		return (0);
	}
	for (j = 1; j < argc; j++)
	{
		int num = 0;
		int i = 0;
		int sign = 1;

		if (argv[j][0] == '-')
		{
			sign = -1;
			i = 1;
		}

		for (; argv[j][i] != '\0'; i++)
		{
			if (!isdigit(argv[j][i]))
			{
				printf("Error\n");
				return (1);
			}

			num = num * 10 + (argv[j][i] - '0');
		}

		count += num * sign;
	}
	printf("%d\n", count);
	return (0);
}
