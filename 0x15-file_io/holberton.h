#ifndef HOLBIE_VAR
#define HOLBIE_VAR

#define MAX_FILE_LENGTH	1024

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int get_buffer_size(char *buffer);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
