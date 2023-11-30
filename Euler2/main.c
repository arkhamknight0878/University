#include<stdio.h>
#include"euler.h"

int main()
{
	unsigned long long MaxFib = 0;
	printf("The range is ");
	scanf_s("%llu", &MaxFib);
	printf("Sum of even Fibonccy numbers = %llu", Sum_of_EvenFib(MaxFib));

	return 0;
}