#include "Line.h"

Line::Line(double a_ = 0, double b_ = 0, double argument_ = 0) : Function(argument_)
{
	a = a_;
	b = b_;

	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << "Enter a and b" << endl << "> ";
	cin >> a >> b;

	cout << "Enter x" << endl << "> ";
	cin >> argument;

	cout << "y = " << (a * argument + b);
}
