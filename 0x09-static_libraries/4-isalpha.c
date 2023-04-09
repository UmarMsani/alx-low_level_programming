#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: the character letter in the ASCII code
 * Return: (1) if if c is a letter, lowercase or uppercase otherwise 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
