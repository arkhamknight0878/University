#include "Line.h"

Line::Line()
{
	a = 0;
	b = 0;

	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << "-----------------------------" << endl;
	cout << "Calculate Function y = ax + b" << endl;
	cout << endl << "Enter a and b:" << endl;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	cout << endl << "Enter x:" << endl;
	cout << "x = "; cin >> argument;

	cout << endl << "y = " << (a * argument + b) << endl;
	cout << "-----------------------------" << endl;
}