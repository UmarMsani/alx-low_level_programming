#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @d: String Containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *d)
{
	unsigned int num = 0;
	int len = strlen(d);
	int j;

	/*loop  will iterate over each character in the string d*/
	for (j = 0; j < len; j++)
	{
		/* it checks if the current character is '0'*/
		if (d[j] == '0')
		{
			/* shift left by 1 */
			num = num << 1;
		} else if (d[j] == '1')
		{
			/*shift left by 1 and set the least significant bit to 1*/
			num = (num << 1) | 1;
		} else
		{
			/* invalid character found */
			return (0);
		}
	}

	return (num);
}
