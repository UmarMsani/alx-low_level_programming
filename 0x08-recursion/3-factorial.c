#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: is a given number
 *
 * Return: factorial n
 */

int factorial(int n)
{
	if (n < 0)	/*error case*/
	{
		return (-1);
	}
	if (n == 0)	/*base case*/
	{
		return (1);
	}
	return (n * factorial(n - 1));	/*recursive call with n-1*/
}
