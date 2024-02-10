#include<stdio.h>
#include"function.h"

int main()
{
	unsigned long long range = 0;

	printf("Range = ");
	scanf_s("%llu", &range);
	printf("The difference between the sum of the squares and the square of the sum = %5.2lf", euler_six(range));

	return 0;
}