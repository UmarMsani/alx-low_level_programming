#include "main.h"

/**
  *  _isdigit -this function return 1 if c is number or 0 if it is not
  * Return: return 0
  * @c:par
  */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
