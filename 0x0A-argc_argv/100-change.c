#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the min num of coins to make change for an amount of money
 * @argc: stores num of cmd-line arg
 * @argv: is array of char arg
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int coins;
	int cents;

	if (argc != 2)	/*check if num of cmd-line args is exactly 2*/
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]); /*convert strg to integer*/

	if (cents < 0)	/*check If num passed as the arg is negative*/
	{
		printf("0\n");
		return (0);
	}

	coins = 0;

	coins = coins + cents / 25;
	cents %= 25;
	coins = coins + cents / 10;
	cents %= 10;
	coins = coins + cents / 5;
	cents %= 5;
	coins = coins + cents / 2;
	cents %= 2;

	coins = coins + cents;

	printf("%d\n", coins);
	return (0);
}
