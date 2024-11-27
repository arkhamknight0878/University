#include "Polynomial.h"

Polynomial::Polynomial()
{
	coefficients = nullptr;

	name = new char[20];
	strcpy(name, "a_nx^n + ... + a_0");
}

void Polynomial::Calculate()
{
	size_t max_power = 0;

	cout << endl << "Enter Max Power Of Polynomial" << endl << "> ";
	cin >> max_power;

	while (!cin.good() && max_power < 0)
	{
		cout << "!!! Incorrect Input !!! Please, Try Again" << endl << "> ";
		cin >> max_power;
	}

	coefficients = new double[max_power + 1];

	cout << endl << "Enter Coefficients" << endl << "> ";

	for (size_t i = 0; i < max_power + 1; ++i)
	{
		cin >> coefficients[i];

		while (!cin.good())
		{
			cout << "!!! Incorrect Input !!! Please, Try Again" << endl << "> ";
			cin >> coefficients[i];
		}
	}

	cout << endl << "Enter Argument" << endl << "> ";
	cin >> argument;
	while (!cin.good())
	{
		cout << "!!! Incorrect Input !!! Please, Try Again" << endl << "> ";
		cin >> argument;
	}

	double result = coefficients[0];

	for (size_t i = 1; i < max_power + 1; ++i)
	{
		result *= argument;
		result += coefficients[i];
	}

	cout << endl << "y = " << result << endl << endl;
}