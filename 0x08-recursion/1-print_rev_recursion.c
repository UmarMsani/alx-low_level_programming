#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed.
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0')	/*base case*/
	{
		return;
	}
	_print_rev_recursion(s + 1);  /* recursive call with the next character*/
	_putchar(*s);  /* print the current character after the recursive call*/
}
