#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

int **alloc_grid(int width, int height)
{
	int i, j;
	int **new_array;

	if(width <= 0) return (NULL);
	if(height <= 0) return (NULL);

	new_array = (int **)malloc(height * sizeof(int *));
	for (i = 0; i < height; i++)
		new_array[i] = (int *)malloc(width * sizeof(int));

	for (i = 0; i <  height; i++)
		for (j = 0; j < width; j++)
			new_array[i][j] = 0;

	return (new_array);
}