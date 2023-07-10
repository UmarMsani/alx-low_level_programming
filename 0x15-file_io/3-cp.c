#include "main.h"

/**
 * main - Copies contents of one file to another
 * @argc: Number of Arguments passed to the program
 * @argv: Array of Strings containing program args
 *
 * Return: 0 on success, or an error code
 */

int main(int argc, char *argv[])
{
	char buf[1024];
	int fil_from, fil_to;
	ssize_t nread;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s fil_from fil_to\n", argv[0]);
		return (97);
	}
	fil_from = open(argv[1], O_RDONLY);
	if (fil_from == -1 || access(argv[1], R_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}
	fil_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fil_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}
	while ((nread = read(fil_from, buf, 1024)) > 0)
	{
		if (write(fil_to, buf, nread) != nread)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			return (99);
		}
	}
	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}
	if (close(fil_from) == -1 || close(fil_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: %d\n", fil_from < fil_to ? fil_from : fil_to);
		return (100);
	}
	return (0);
}
