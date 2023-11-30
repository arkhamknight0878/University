#include <stdio.h>
#include "euler.h"

int main()
{
	unsigned long long Range = 0;
	printf("Range is ");
	scanf_s("%llu", &Range);
	printf("Min Number Multiple of Range digits is %llu", MinMult(Range));

	return 0;
}