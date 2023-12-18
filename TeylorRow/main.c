#include<stdio.h>
#include"functions.h"

int main()
{
	double exp_to_teylor_res = 0;
	double exp = 0;
	double x_arg = 0;

	printf("Enter Eps and X argument\nEps = ");
	scanf_s("%lf", &exp);
	printf("\nX = ");
	scanf_s("%lf", &x_arg);

	exp_to_teylor_res = exp_to_teylor(exp, x_arg);

	printf("Decomposition of the Exponents into the Taylor row = %lf", exp_to_teylor_res);

	return 0;
}