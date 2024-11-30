#include "Cube.h"

Cube::Cube()
{
	name = new char[4];
	strcpy(name, "x^3");
}

void Cube::Calculate()
{
	cout << endl << "Enter x:" << endl;
	cout << "x = "; cin >> argument;

	cout << endl << "y = x^3 = " << argument * argument * argument << endl;
}