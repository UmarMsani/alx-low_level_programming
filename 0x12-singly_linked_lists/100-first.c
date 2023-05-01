#include <stdio.h>

void printmessage(void)__attribute__((constructor));

/**
 * printmessage - prints a sentence before the main
 * function is executed.
 */

void printmessage(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
