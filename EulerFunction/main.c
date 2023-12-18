#include<stdio.h>
#include"function.h"

int main()
{
	unsigned int res = 0;
	unsigned long long range;

	printf("Range = ");
	scanf_s("%llu", &range);

	res = euler_function(range);

	printf("Amount of Relatively Prime with Range number = %u", res);

	return 0;
}