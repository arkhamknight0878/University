#include <stdio.h>
#include "euler.h"

int main()
{
	unsigned long long Number = 0;
	printf("Number is ");
	scanf_s("%llu", &Number);
	printf("Biggest Divisor of Number = %llu", Max_Divisor(Number));

	return 0;
}