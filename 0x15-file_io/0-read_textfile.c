#include "main.h"
/**
 * read_textfile - Reads text file and prints it to POSIX standard output
 * @filenames: File name to read
 * @letter: Number of letters to read and print
 * Return: Actual number of letters it could read & print
 */
ssize_t read_textfile(const char *filenames, size_t letter)
{
	ssize_t firts_len, second_len;
	char *buffer;
	int filles;

	if (filenames == NULL)
		return (0);
	/* open file with read only mode */
	filles = open(filenames, O_RDONLY);
	/* check if the opened */
	if (filles == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letter);

	if (buffer == NULL)
	{
		close(filles);
		return (0);
	}
	firts_len = read(filles, buffer, letter);
	close(filles);
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
