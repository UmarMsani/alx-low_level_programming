#include <stdio.h>

/**
 * main - program that prints its name
 * @argc: it stores number of cmd-line arg passed by user
 * @argv: is array of char listing all argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
