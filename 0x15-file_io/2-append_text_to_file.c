#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of file to append to
 * @text_content: text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file, num_written, length;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Check if text_content is NULL */
	if (text_content == NULL)
		return (1);

	/* Open the file in append mode, create it if it doesn't exist */
	file = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0600);
	if (file == -1)
		return (-1);

	/* Get the length of the text_content string */
	length = 0;
	while (text_content[length] != '\0')
		length++;

	/* Write the text_content string to the end of the file */
	num_written = write(file, text_content, length);
	if (num_written == -1 || num_written != length)
		return (-1);

	/* Close the file and return success */
	close(file);
	return (1);
}
