#pragma once

#include "Matrix.h"

#include <math.h>
#include <vector>

class SquareMatrix : public Matrix
{
private:
	SquareMatrix* Minor(size_t del_row_, size_t del_column_);
public:
	SquareMatrix(int size_ = 2) : Matrix(size_, size_) { ; }

	SquareMatrix(const SquareMatrix& other_);

	int GetSize() { return rows; }

	SquareMatrix& operator= (const SquareMatrix& other_);

	double* operator[] (int index_) { return matrix[index_]; }

	SquareMatrix operator+(const SquareMatrix& other_) const;

	SquareMatrix& operator+=(const SquareMatrix& other_);

	SquareMatrix operator-(const SquareMatrix& other_) const;

	SquareMatrix& operator-=(const SquareMatrix& other_);

	SquareMatrix operator*(const SquareMatrix& other_) const;

	SquareMatrix& operator*=(const SquareMatrix& other_);

	SquareMatrix operator*(int value_) const;

	SquareMatrix operator*=(int value_);

	SquareMatrix operator/(int value_) const;

	SquareMatrix& operator/=(int value_);

	SquareMatrix Pow(int power_);

	double Determinant();

	SquareMatrix Transpon();

	SquareMatrix Reverse();

	double MatrixTace();

	friend istream& operator>>(istream& in_, SquareMatrix& matrix_);

	friend ifstream& operator>>(ifstream& in_, SquareMatrix& matrix_);

	friend ostream& operator<<(ostream& out_, const SquareMatrix& matrix_);
};

SquareMatrix SmoothMatrix(SquareMatrix& matrix_);

vector<double> TraceToVector(const SquareMatrix matrix_, int max_power_);