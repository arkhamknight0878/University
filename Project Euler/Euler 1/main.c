#include "Function.h"

#include <stdio.h>

int main()
{
	unsigned long long upper_bound = 0;

	printf("Enter Upper Bound: ");
	scanf_s("%llu", &upper_bound);

	printf("Sum of all numbers, Multiples 3 or 5 is: %llu", Sum_of_Mult35(upper_bound));

	return 0;
}