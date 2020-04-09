#include "holberton.h"

int main(int argc, char **argv)
{
	int file_descriptor_from;
	int file_descriptor_to;
	int file_from_bytes_read;
	int file_to_bytes_written;
	char buffer[1024];

	if (argc != 3){
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_descriptor_from = open(argv[1], O_RDONLY);
	if (file_descriptor_from < 0){
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_descriptor_to =
			open(argv[2], O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (file_descriptor_to < 0) {
		/* Raised failure on purpose, to check if the file already existed */
		if (errno == EEXIST) {
			/* the file already existed, then open it without changing the permissions */
			file_descriptor_to = open(argv[2], O_WRONLY | O_TRUNC);

			if(file_descriptor_to < 0){
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
		}
	}

	file_from_bytes_read = 1;
	while(file_from_bytes_read > 0) {
		file_from_bytes_read = read(file_descriptor_from, buffer, 1024);
		if(file_from_bytes_read < 0){
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		file_to_bytes_written = write(file_descriptor_to, buffer, file_from_bytes_read);
		if (file_to_bytes_written < 0){
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if(close(file_descriptor_from) < 0){
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_from);
		exit(100);
	}

	if(close(file_descriptor_to) < 0){
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor_to);
		exit(100);
	}

	return (0);
}
