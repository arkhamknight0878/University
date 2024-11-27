#include "Line.h"

Line::Line()
{
	a = 0;
	b = 0;

	name = new char[7];
	strcpy(name, "ax + b");
}

Line::Line(double a_, double b_, double argument_) : Function(argument_)
{
	a = a_;
	b = b_;

	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << endl << "Enter a and b" << endl << "> ";
	cin >> a >> b;

	cout << endl << "Enter x" << endl << "> ";
	cin >> argument;

	cout << endl << "y = " << (a * argument + b) << endl << endl;
}