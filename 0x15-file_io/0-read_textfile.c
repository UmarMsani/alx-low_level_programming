#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @letters: num of letters to read and print
 * @filename: file name to read
 *
 * Return: actual num of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t read_bytes;

	if (filename == NULL)
	{
		return (0);
	}
	file = fopen(filename, "r");

	if (file == NULL)
	{
		return (0);
	}
	buffer = (char *) malloc(letters + 1);

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	read_bytes = fread(buffer, sizeof(char), letters, file);

	if (ferror(file) != 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);
	return read_bytes;
}
