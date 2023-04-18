#include <stdio.h>

/**
 * main - program that prints the name of the file it was compiled from
 * Description: this program prints the name of the file it was comipiled from
 * Return: 0 (success)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
