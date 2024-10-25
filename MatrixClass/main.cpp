#include "Matrix.h"

#include <iostream>

int main()
{
	Matrix matrix_a(2, 3);
	Matrix matrix_b(3, 2);

	matrix_a.SetRandMatrix();
	matrix_a.MatrixPrint();

	matrix_b.SetRandMatrix();
	matrix_b.MatrixPrint();

	//Matrix mult = matrix_a * matrix_b;
	//mult.MatrixPrint();

	matrix_a *= matrix_b;
	matrix_a.MatrixPrint();

	return 0;
}