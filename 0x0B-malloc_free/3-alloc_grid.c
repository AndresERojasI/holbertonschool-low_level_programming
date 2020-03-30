#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

int **alloc_grid(int width, int height)
{
	int i, j;
	int **new_array;

	if(width <= 0 || height <= 0) return (NULL);

	new_array = (int **)malloc(height * sizeof(int *));

	if(new_array == NULL) return (NULL);

	for (i = 0; i < height; i++) {
		new_array[i] = (int *) malloc(width * sizeof(int));
		if(new_array[i] == NULL) {
			for (i = 0; i < height; i++) {
				free(new_array[i]);
				return (NULL);
			}
		};
	}

	for (i = 0; i <  height; i++)
		for (j = 0; j < width; j++)
			new_array[i][j] = 0;

	return (new_array);
}