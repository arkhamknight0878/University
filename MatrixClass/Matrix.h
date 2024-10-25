#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Matrix
{
protected:
	size_t rows;
	size_t columns;
	double** matrix;

	double** Memmory(size_t rows_, size_t columns_);
public:
	Matrix(size_t rows_ = 2, size_t columns_ = 3);

	Matrix(const Matrix& other_);

	~Matrix();

	void MatrixPrint();

	void SetRandMatrix();

	void SetElement(size_t row_, size_t column_, double data_) { matrix[row_][column_] = data_; }

	double GetElement(size_t row_, size_t column_) { return matrix[row_][column_]; }

	Matrix operator+ (const Matrix& other_) const;

	Matrix operator- (const Matrix& other_) const;

	Matrix operator* (const Matrix& other_) const;

	Matrix operator* (int data_) const;

	// TODO: Matrix operator/ (const Matrix& other_) const;

	Matrix operator/ (int data_) const;

	Matrix& operator+= (const Matrix& other_);

	Matrix& operator-= (const Matrix& other_);

	// TODO: Matrix& operator/ (const Matrix& other_);

	// TODO: Matrix& operator/ (int data_);

	Matrix& operator*= (const Matrix& other_);

	Matrix& operator*= (int data_);

	bool operator==(const Matrix& other_);

	bool operator!=(const Matrix& other_);
};

