#include "main.h"

/**
  * get_endianness - function
  * Return: return int
  */

int get_endianness(void)
{
	unsigned int num = 1;
	char *ptr = (char *)&num;

	return (*ptr == 1);
}
