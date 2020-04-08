#include "holberton.h"

int create_file(const char *filename, char *text_content){
	int file_descriptor;
	int bytes_written;
	int bytes_to_write;

	if(filename == NULL) return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (file_descriptor < 0) {
		/* Raised failure on purpose, to check if the file already existed */
		if (errno == EEXIST) {
			/* the file already existed, then open it without changing the permissions */
			file_descriptor = open(filename, O_WRONLY | O_TRUNC);
		}
	}

	if(text_content == NULL){
		bytes_written = write(file_descriptor, '', 1);
	} else {
		bytes_to_write = get_buffer_size(text_content);
		bytes_written = write(file_descriptor, text_content, bytes_to_write);
	}

	close(file_descriptor);

	if(bytes_written < 0) return (-1);

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