#include <stdio.h>
#include <string.h>
#include "holberton.h"

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int value;
	unsigned int str_length;
	unsigned int number;

	str_length = strlen(b);
	number = 0;

	for (i = str_length; i >= 0; i--){
		if(b[i] == 0) continue;
		if(b[i] != 48 && b[i] != 49) return (0);

		value = b[i] - '0';
		number += value * power(2, (str_length - i - 1));
	}

	return (number);
}
