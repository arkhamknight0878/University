#include<stdio.h>
#include"Eyler.h"

int main()
{
	long long number_ = 0;
	printf("Number = ");
	scanf_s("%llu", &number_);
	printf("Max Prime = %llu", Problem_3(number_));
}