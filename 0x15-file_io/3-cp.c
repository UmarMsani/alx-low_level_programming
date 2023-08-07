#include "main.h"
/**
 * main - copies contents of one file to another
 * @argv: array of strings containing program args
 * @argc: number of arguments passed to the program
 * Return: 0 on success, or an error code
 */
int main(int argc, char *argv[])
{
	char buf[1024];
	int fd_from, fd_to;
	ssize_t nread;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1 || access(argv[1], R_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}
	while ((nread = read(fd_from, buf, 1024)) > 0)
	{
		if (write(fd_to, buf, nread) != nread)
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
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: %d\n", fd_from < fd_to ? fd_from : fd_to);
		return (100);
	}
	return (0);
}
