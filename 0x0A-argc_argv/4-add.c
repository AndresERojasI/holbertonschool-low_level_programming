#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base, int exponent);

int main(int argc, char **argv)
{
	int j, i;
	int result;
	int units;

	if(argc == 1) {
		printf("0\n");
		return (0);
	}

	result = 0;
	for (j = 1; j < argc; ++j) {
		units = 0;
		for (i = (strlen(argv[j]) -1); i >= 0 ; --i) {
			if(argv[j][i] >= 48 && argv[j][i] <= 57) {
				result += (argv[j][i] - 48) * power(10, units);
				++units;
			} else {
				printf("Error\n");
				return (0);
			}
		}
	}

	printf("%d\n", result);

	return (0);
}

int power(int base, int exponent)
{
	float temp;
	if(exponent < 0) return (0);
	if(exponent == 0) return (1);

	temp = power(base, exponent/2);

	if ((exponent % 2) == 0)
		return (temp * temp);
	else
		return (base * temp * temp);
}