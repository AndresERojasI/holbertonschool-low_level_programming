#include "holberton.h"

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