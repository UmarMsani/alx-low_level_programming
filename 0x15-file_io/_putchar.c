#include <unistd.h>

/**
 * _putchar - writes the char c to stdout
 * @c: Character to print
 *
 * Return: 1 On success.
 * On error, return -1, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
