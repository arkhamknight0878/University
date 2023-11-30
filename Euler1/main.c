#include<stdio.h>
#include"euler.h"

int main()
{
	unsigned long long Range = 0;
	printf("Range = ");
	scanf_s("%llu", &Range);

	printf("Sum of digits multiple of 3 or 5 = %llu", Sum_of_Mult(Range));

	return 0;
}