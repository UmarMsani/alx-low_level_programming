#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int len = strlen(b);
	int i;

	/*loop  will iterate over each character in the string b*/
	for (i = 0; i < len; i++)
	{
		/* it checks if the current character is '0'*/
		if (b[i] == '0')
		{
			/* shift left by 1 */
			num = num << 1;
		} else if (b[i] == '1')
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
