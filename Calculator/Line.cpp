#include "Line.h"

Line::Line()
{
	a = b = 0;
	name = new char[7];
	strcpy(name, "ax + b");
}

void Line::Calculate()
{
	cout << "Enter a and b" << endl << "> ";
	cin >> a >> b;

	cout << "Enter x" << endl << "> ";
	cin >> argument;

	cout << "y = " << (a * argument + b) << endl;
}
