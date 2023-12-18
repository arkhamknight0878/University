#include "functions.h"

unsigned long long factorial(unsigned long long number_)
{
	if (number_ == 0)
		return 0;

	unsigned long long factor_res = 1;

	for (unsigned long long i = 1; i <= number_; i++)
	{
		factor_res *= i;
	}
	return factor_res;
}

double exp_to_teylor(const double exp_, double x_)
{
	double res = 1;
	double component = 0;
	int amount = 1;

	do
	{
		component = pow(x_, amount) / factorial(amount);
		res += component;
		amount++;

	} while (abs(component) > exp_);

	return res;
}