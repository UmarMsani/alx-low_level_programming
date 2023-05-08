#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @letters: num of letters to read and print
 * @filename: file name to read
 *
 * Return: actual num of letters it could read & print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t firts_len, second_len;
	char *buffer;
	int fille;

	if (filename == NULL)
		return (0);
	/* open file with read only mode */
	fille = open(filename, O_RDONLY);
	/* check if the opened */
	if (fille == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		close(fille);
		return (0);
	}
	firts_len = read(fille, buffer, letters);
	close(fille);
	if (firts_len == -1)
	{
		free(buffer);
		return (0);
	}
	second_len = write(STDOUT_FILENO, buffer, firts_len);
	free(buffer);
	if (firts_len != second_len)
		return (0);
	/* Return actual number of bytes read & printed to STDOUT*/
	return (second_len);
}
