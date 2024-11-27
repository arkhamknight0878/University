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

Exponent::Exponent()
{
	eps = 0;

	name = new char[4];
	strcpy(name, "e^x");
}

Exponent::Exponent(double eps_, double argument_) : Function(argument_)
{
	eps = eps_;

	name = new char[4];
	strcpy(name, "e^x");
}

void Exponent::Calculate()
{
	cout << endl << "Enter Epsilone" << endl << "> ";
	cin >> eps;

	cout << endl << "Enter x" << endl << "> ";
	cin >> argument;

	double result = 1;
	double component = 0;
	size_t amount = 1;

	do
	{
		component = pow(argument, amount) / Factorial(amount);
		result += component;
	} while (abs(component) > eps);

	cout << endl << "y = " << result << endl << endl;
}