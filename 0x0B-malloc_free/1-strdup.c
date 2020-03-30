#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

char *_strdup(char *str)
{
	unsigned int size;
	static char *new_str;
	unsigned int i;

	if(str == NULL) return (NULL);

	size = 0;
	while (str[size])
		size++;

	printf("Size %lu\n", ((sizeof(char) * size) + 1));

	new_str = (char *)malloc((sizeof(char) * size) + 1);

	if(new_str == NULL) return (NULL);

	for (i = 0; i < size; ++i) {
		new_str[i] = str[i];
	}

	return (new_str);
}
