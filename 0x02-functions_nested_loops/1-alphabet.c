#include "main.h"

/**
 *  prints_alphabet - prints the alphabet, in lowercase
 */

void print_alphabet(void)
{
	char alpha;

	for (alpha = 'a'; alpha <= 'z'; alpha++)
		_putchar(alpha);
	_putchar('\n');
}
