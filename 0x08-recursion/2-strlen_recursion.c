#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: string to be measured
 *
 * Return: lenth of a string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')	/*base case*/
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));/*recursive call with the next char*/
}
