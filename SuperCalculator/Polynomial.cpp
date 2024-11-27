#include "Polynomial.h"

void Polynomial::SetCoeff()
{
	size_t max_power = 0;

	cout << endl << "Enter Max Power Of Polynomial" << endl;
	cout << "Max Power: "; cin >> max_power;

	coefficients = new double[max_power + 1];

	cout << endl << "Enter Coefficients" << endl;
	cout << "Coefficients: ";

	for (size_t i = 0; i < max_power + 1; ++i)
	{
		cin >> coefficients[i];

		while (!cin.good())
		{
			cout << "!!! Incorrect Input !!! Please, Try Again" << endl << "> ";
			cin >> coefficients[i];
		}
	}
}

double Polynomial::GetValue()
{
	double result = coefficients[0];
	size_t coef_amount = sizeof(*coefficients) / sizeof(double);

	for (size_t i = 1; i < coef_amount; ++i)
	{
		result *= argument;
		result += coefficients[i];
	}

	return result;
}