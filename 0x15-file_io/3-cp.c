#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argv: an array of args
 * @argc: a number of args
 *
 * Return: (0) on success
 */

int main(int argc, char *argv[])
{
	char buffer[1024];
	int file_from, file_to, close_status;
	ssize_t read_bytes, write_bytes;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	do {
		read_bytes = read(file_from, buffer, 1024);
		if (read_bytes == -1)
		{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
		}

		write_bytes = write(file_to, buffer, read_bytes);
		if (write_bytes == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	} while (read_bytes == 1024);

	close_status = close(file_from);
	if (close_status == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	close_status = close(file_to);
	if (close_status == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}
