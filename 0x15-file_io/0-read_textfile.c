#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	int written_bytes;
	ssize_t read_chars;
	char *buffer;

	if(filename == NULL || letters == 0) return (0);

	file_descriptor = open(filename, O_RDONLY);

	if(file_descriptor < 0) return (0);

	buffer = (char *)malloc(sizeof(char) * letters);

	read_chars = read(file_descriptor, buffer, letters);

	if(read_chars < 0) return (0);

	written_bytes = write(STDOUT_FILENO, buffer, read_chars);

	if(written_bytes < 0) return (0);

	free(buffer);

	return (read_chars);
}
