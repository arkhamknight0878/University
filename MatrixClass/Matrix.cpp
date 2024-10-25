#include "Matrix.h"

double** Matrix::Memmory(size_t rows_, size_t columns_)
{
	double** matrix = new double* [rows_];
	if (!matrix)
		throw nullptr;

	for (size_t i = 0; i < rows_; ++i)
	{
		matrix[i] = new double[columns_];
		if (!matrix[i])
		{
			for (size_t j = 0; j < i; ++j)
				delete[] matrix[j];

			delete[] matrix;
			throw nullptr;
		}
	}

	return matrix;
}

Matrix::Matrix(size_t rows_, size_t columns_)
{
	if (rows_ <= 0 || columns_ <= 0)
		throw 1;

	rows = rows_;
	columns = columns_;

	matrix = Memmory(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& other_)
{
	rows = other_.rows;
	columns = other_.columns;

	matrix = Memmory(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void Matrix::MatrixPrint()
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			printf("%5.2lf ", matrix[i][j]);

		printf("\n");
	}

	printf("\n");
}

void Matrix::SetRandMatrix()
{
	srand((unsigned)time(NULL));

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] = rand() % 10;
	}
}

Matrix Matrix::operator+(const Matrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	Matrix result(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	Matrix result(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& other_) const
{
	if (rows != other_.columns || columns != other_.rows)
		throw 4;

	Matrix result(rows, other_.columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < other_.columns; ++j)
		{
			double interim_result = 0;

			for (size_t k = 0; k < columns; ++k)
				interim_result += matrix[i][k] * other_.matrix[k][j];

			result.matrix[i][j] = interim_result;
		}
	}

	return result;
}

Matrix Matrix::operator*(int data_) const
{
	Matrix result(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] * data_;
	}

	return result;
}

Matrix Matrix::operator/(int data_) const
{
	Matrix result(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] / data_;
	}

	return result;
}

Matrix& Matrix::operator+=(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] += other_.matrix[i][j];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] -= other_.matrix[i][j];
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other_)
{
	if (rows != other_.columns || columns != other_.rows)
		throw 4;

	Matrix temp = *this;
	columns = other_.columns;

	for (size_t i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	matrix = Memmory(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < other_.columns; ++j)
		{
			double interim_result = 0;

			for (size_t k = 0; k < temp.columns; ++k)
				interim_result += temp.matrix[i][k] * other_.matrix[k][j];

			matrix[i][j] = interim_result;
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(int data_)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] = matrix[i][j] * data_;
	}

	return *this;
}

bool Matrix::operator==(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (matrix[i][j] != other_.matrix[i][j])
				return false;
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 3;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (matrix[i][j] != other_.matrix[i][j])
				return true;
		}
	}

	return false;
}
