#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *argstostr(int ac, char **av)
{
	unsigned int size, character_counter;
	int i, j;
	char *new_str;

	if(ac == 0 || av == NULL) return (NULL);

	size = 0;
	for (i = 0; i < ac; ++i) {
		character_counter = 0;
		while (av[i][character_counter]){
			character_counter++;
			size++;
		}
	}

	new_str = (char *)malloc(sizeof(char) * (size + ac + 1));

	if(new_str == NULL) return (NULL);

	j = 0;
	for (i = 0; i < ac; ++i) {
		for (character_counter = 0; av[i][character_counter] != '\0' ; ++j, ++character_counter)
			new_str[j] = av[i][character_counter];
		new_str[j] = '\n';
		j++;
	}

	return (new_str);
}