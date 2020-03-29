#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int j;
	int result;
	int temporal;

	if(argc == 1) {
		printf("0\n");
		return (0);
	}

	result = 0;
	for (j = 1; j < argc; ++j) {
		temporal = atoi(argv[j]);
		if(temporal != 0) {
			result += temporal;
		} else {
			printf("Error\n");
			return (0);
		}
	}

	printf("%d\n", result);

	return (0);
}