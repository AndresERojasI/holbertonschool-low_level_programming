#include <stdio.h>
#include <stdlib.h>

int calc_cents(int *carry, int coin);

int main(int argc, char **argv)
{
	int cents;
	int cents_count;
	int carry;
	int *carry_pntr;

	if(argc != 2){
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	carry = cents;
	carry_pntr = &carry;

	if(cents < 1){
		printf("0\n");
		return (1);
	}

	cents_count = calc_cents(carry_pntr, 25);
	cents_count += calc_cents(carry_pntr, 10);
	cents_count += calc_cents(carry_pntr, 5);
	cents_count += calc_cents(carry_pntr, 2);
	cents_count += calc_cents(carry_pntr, 1);

	printf("%i\n", cents_count);

	return (0);
}

int calc_cents(int *carry, int coin)
{
	int temporal;
	if(*carry < coin) return 0;

	temporal = (int)(*carry/coin);
	*carry = *carry - (temporal * coin);

	return (temporal);
}
