#include "main.h"

/**
 * create_file - creates a file and writes a string to it
 * @filename: name of file to create
 * @text_content:  string to write to the file (can be 0)
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int file, bytes_written;
	/* rw------- permissions */
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytes_written = write(file, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}
