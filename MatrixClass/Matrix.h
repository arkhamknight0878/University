#pragma once

#include "MatrixException.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Matrix
{
protected:
	int rows;
	int columns;
	double** matrix;

	void Memmory(int rows_, int columns_);

	void Clear();
public:

	Matrix(int rows_ = 2, int columns_ = 3);

	Matrix(const Matrix& other_);

	virtual ~Matrix();

	void SetElement(size_t row_, size_t column_, double data_) { matrix[row_][column_] = data_; }

	double GetElement(size_t row_, size_t column_) { return matrix[row_][column_]; }

	Matrix& operator= (const Matrix& other_);

	double* operator[] (int index_) { return matrix[index_]; }

	Matrix operator+ (const Matrix& other_) const;

	Matrix operator- (const Matrix& other_) const;

	Matrix operator* (const Matrix& other_) const;

	Matrix operator* (int data_) const;

	Matrix& operator+= (const Matrix& other_);

	Matrix& operator-= (const Matrix& other_);

	Matrix& operator/= (int data_);

	Matrix& operator*= (const Matrix& other_);

	Matrix& operator*= (const double data_);

	bool operator==(const Matrix& other_);

	bool operator!=(const Matrix& other_);

	Matrix Transpon();

	friend istream& operator>>(istream& in_, Matrix& matrix_);

	friend ifstream& operator>>(ifstream& in_, Matrix& matrix_);

	friend ostream& operator<<(ostream& out_, const Matrix& matrix_);
};