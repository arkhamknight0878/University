#include "Exponent.h"

double Exponent::Factorial(size_t argument_)
{
	if (!argument_)
		return 1.0;

	double result = 1.0;

	for (size_t i = argument_; i != 1; --i)
		result *= i;

	return result;
}

void Exponent::SetCoeff()
{
	cout << endl << "Enter Epsilone" << endl;
	cout << "eps = "; cin >> eps;
}

double Exponent::GetValue()
{
	double result = 1;
	double component = 0;
	size_t amount = 1;

	do
	{
		component = pow(argument, amount) / Factorial(amount);
		result += component;
	} while (abs(component) > eps);

	return result;
}