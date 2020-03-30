#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

char *str_concat(char *s1, char *s2)
{
	unsigned int size_1;
	unsigned int size_2;
	static char *new_str;
	unsigned int i;

	if(s1 == NULL) s1 = "";
	if(s2 == NULL) s2 = "";

	size_1 = 0;
	while (s1[size_1])
		size_1++;

	size_2 = 0;
	while (s2[size_2])
		size_2++;

	new_str = (char *)malloc((sizeof(char) * (size_1 + size_2)) + 1);

	if(new_str == NULL) return (NULL);

	for (i = 0; i < size_1; ++i) {
		new_str[i] = s1[i];
	}

	for (i = 0; i < size_2; ++i) {
		new_str[i + size_1] = s2[i];
	}

	return (new_str);
}
