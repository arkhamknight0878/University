#pragma once

#include "Matrix.h"

#include <math.h>

class SquareMatrix : protected Matrix
{
private:
	SquareMatrix* Minor(size_t del_row_, size_t del_column_);
public:
	SquareMatrix(int size_ = 2) : Matrix(size_, size_) { ; }

	SquareMatrix(const SquareMatrix& other_);

	SquareMatrix& operator= (const SquareMatrix& other_);

	SquareMatrix operator+ (const SquareMatrix& other_) const;

	SquareMatrix operator- (const SquareMatrix& other_) const;

	SquareMatrix operator* (const SquareMatrix& other_) const;

	SquareMatrix operator* (int data_) const;

	SquareMatrix operator/ (SquareMatrix& other_) const;

	SquareMatrix operator/ (int data_) const;

	SquareMatrix& operator+= (const SquareMatrix& other_);

	SquareMatrix& operator-= (const SquareMatrix& other_);

	SquareMatrix& operator/= (SquareMatrix& other_);

	SquareMatrix& operator/= (int data_);

	SquareMatrix& operator*= (const SquareMatrix& other_);

	SquareMatrix& operator*= (int data_);

	bool operator==(const SquareMatrix& other_);

	bool operator!=(const SquareMatrix& other_);

	double Determinant();

	SquareMatrix Transpon();

	SquareMatrix Reverse();

	friend istream& operator>>(istream& in_, SquareMatrix& matrix_);

	friend ostream& operator<<(ostream& out_, const SquareMatrix& matrix_);
};