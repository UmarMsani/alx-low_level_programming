#include "main.h"
/**
 * append_text_to_file - Appends text to the end of a file
 * @filenames: Name of the file to append to
 * @text_contents: Text to append to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filenames, char *text_contents)
{
	int filles, number_written, length;

	/* Check if filename is NULL */
	if (filenames == NULL)
		return (-1);

	/* Check if text_content is NULL */
	if (text_contents == NULL)
		return (1);

	/* Open the file in append mode, create it if it doesn't exist */
	filles = open(filenames, O_WRONLY | O_APPEND | O_CREAT, 0600);
	if (filles == -1)
		return (-1);

	/* Get the length of the text_content string */
	length = 0;
	while (text_contents[length] != '\0')
		length++;

	/* Write the text_content string to the end of the file */
	number_written = write(filles, text_contents, length);
	if (number_written == -1 || number_written != length)
		return (-1);

	/* Close the file and return success */
	close(filles);
	return (1);
}
