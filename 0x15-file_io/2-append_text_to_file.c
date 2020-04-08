#include "holberton.h"

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	int bytes_to_write;

	if(filename == NULL) return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor < 0) return (-1);

	bytes_to_write = get_buffer_size(text_content);
	bytes_written = write(file_descriptor, text_content, bytes_to_write);

	if (bytes_written < 0) return (-1);

	close(file_descriptor);

	return (1);
}

int get_buffer_size(char *buffer)
{
	int counter;
	counter = 0;

	while(buffer[counter] != '\0')
		counter++;

	return counter;
}