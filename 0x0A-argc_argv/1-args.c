#define UNUSED(x) (void)(x)
#include <stdio.h>

int main(int argc, char **argv)
{
	UNUSED(argv);
	printf("%d\n", (argc - 1));
	return (0);
}