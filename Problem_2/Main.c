#include<stdio.h>
#include"Eyler.h"

int main()
{
	unsigned int number = 0;
	printf("Number = ");
	scanf_s("%du", &number);
	printf("%llu", Problem_2(number));
	return 0;
}