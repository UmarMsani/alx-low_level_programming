#include "main.h"

/**
 * wildcmp - Compare strings
 * @s1: pointer to string params
 * @s2: pointer to string params
 * Return: 0
 */

int wildcmp(char *s1, char *s2)
{
	/* If s2 is empty, s1 must also be empty*/
	if (*s2 == '\0')
	{
		return (*s1 == '\0');
	}

	/*If the current character in s2 is a wildcard,*/
	/*try matching s1 with s2 with and without the wildcard*/
	if (*s2 == '*')
	{
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2 + 1))
			{
				return (1);
			}
			s1++;
		}

		return (wildcmp(s1, s2 + 1));
	}

	/*If the current characters in s1 and s2 match,*/
	/*continue matching the remaining characters*/
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	/*If the current characters in s1 and s2 don't match,*/
	/*the strings are not identical*/
	return (0);
}
