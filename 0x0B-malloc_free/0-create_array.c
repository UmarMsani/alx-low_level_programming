#include "main.h"

/**
  * create_array - this function return
  * @size:param1
  * @c: param2
  * Return: return char
  */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *j;

	if (size == 0)
	{
		return (NULL);
	}

	j = malloc(sizeof(char) * size);

	if (j == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		j[i] = c;
	}

	return (j);
}
