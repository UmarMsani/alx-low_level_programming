#include "main.h"
/**
 * create_file - creates a file and writes a string to it
 * @text_contents: String to write to the file (can be 0)
 * @filenames: Name of the file to create
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filenames, char *text_contents)
{
	int files, bytes_written;
	/* rw------- permissions */
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filenames == NULL)
		return (-1);

	files = open(filenames, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (files == -1)
		return (-1);

	if (text_contents != NULL)
	{
		bytes_written = write(files, text_contents, strlen(text_contents));
		if (bytes_written == -1)
		{
			close(files);
			return (-1);
		}
	}

	close(files);
	return (1);
}
