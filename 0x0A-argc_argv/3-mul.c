#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int j;
	int result;

	if(argc != 3) {
		printf("Error\n");
		return (0);
	}

	result = 1;
	for (j = 1; j < argc; ++j)
		result *= atoi(argv[j]);

	printf("%d\n", result);

	return (0);
}