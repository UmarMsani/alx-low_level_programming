#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int append_text_to_file(const char *filenames, char *text_contents);
int _putchar(char c);
int append_text_to_file(const char *filenames, char *text_contents);
ssize_t read_textfile(const char *filenames, size_t letter);
int create_file(const char *filenames, char *text_contents);

#endif
