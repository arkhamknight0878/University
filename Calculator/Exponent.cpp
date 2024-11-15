#include "Exponent.h"

double Exponent::Factorial(size_t argument_)
{
	if (!argument_)
		return 0.0;

	double result = 1.0;

	for (size_t i = 0; i <= argument_; ++i)
		result *= i;

	return result;
}

Exponent::Exponent(double eps_ = 0, double argument_ = 0) : Function(argument_)
{
	name = new char[4];
	strcpy(name, "e^x");

	eps = eps_;
}

void Exponent::Calculate()
{
	cout << "Enter Epsilone" << endl << "> ";
	cin >> eps;

	cout << "Enter x" << endl << "> ";
	cin >> argument;

	double result = 1;
	double component = 0;
	size_t amount = 1;

	do
	{
		component = pow(argument, amount) / Factorial(amount);
		result += component;
	} while (abs(component) > eps);

	cout << "y = " << result;
}
