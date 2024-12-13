#include "Matrix.h"

void Matrix::Memmory(int rows_, int columns_)
{
	matrix = new double* [rows_];

	for (int i = 0; i < rows_; ++i)
		matrix[i] = new double[columns_];
}

void Matrix::Clear()
{
	if (!matrix)
		return;

	rows = columns = 0;

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];

	delete[] matrix;
	matrix = nullptr;
}

Matrix::Matrix(int rows_, int columns_)
{
	if (rows_ <= 0 || columns_ <= 0)
		throw 1;

	rows = rows_;
	columns = columns_;

	Memmory(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& other_)
{
	rows = other_.rows;
	columns = other_.columns;

	Memmory(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

Matrix& Matrix::operator=(const Matrix& other_)
{
	if (this == &other_)
		return *this;

	Clear();

	Memmory(other_.rows, other_.columns);
	rows = other_.rows;
	columns = other_.columns;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffSize();

	Matrix result(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffSize();

	Matrix result(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& other_) const
{
	if (rows != other_.columns || columns != other_.rows)
		throw DiffRowsColumns();

	Matrix result(rows, other_.columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < other_.columns; ++j)
		{
			double interim_result = 0;

			for (int k = 0; k < columns; ++k)
				interim_result += matrix[i][k] * other_.matrix[k][j];

			result.matrix[i][j] = interim_result;
		}
	}

	return result;
}

Matrix Matrix::operator*(int data_) const
{
	Matrix result(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] * data_;
	}

	return result;
}

Matrix& Matrix::operator+=(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffRowsColumns();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] += other_.matrix[i][j];
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffSize();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] -= other_.matrix[i][j];
	}

	return *this;
}

Matrix& Matrix::operator/=(int data_)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] /= data_;
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other_)
{
	if (rows != other_.columns || columns != other_.rows)
		throw DiffRowsColumns();

	Matrix temp = *this;
	columns = other_.columns;

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	Memmory(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < other_.columns; ++j)
		{
			double interim_result = 0;

			for (int k = 0; k < temp.columns; ++k)
				interim_result += temp.matrix[i][k] * other_.matrix[k][j];

			matrix[i][j] = interim_result;
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const double data_)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] *= data_;
	}

	return *this;
}

bool Matrix::operator==(const Matrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		return false;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (matrix[i][j] != other_.matrix[i][j])
				return false;
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other_) { return !(&other_ == this); }

Matrix Matrix::Transpon()
{
	Matrix result(columns, rows);

	for (int i = 0; i < result.rows; ++i)
	{
		for (int j = 0; j < result.columns; ++j)
			result.matrix[i][j] = matrix[j][i];
	}

	return result;
}

istream& operator>>(istream& in_, Matrix& matrix_)
{
	if (matrix_.matrix)
		matrix_.Clear();

	cout << "Enter Rows & Columns:" << endl;
	cout << "Rows: "; in_ >> matrix_.rows;
	if (!in_.good() || (matrix_.rows < 0))
	{
		in_.setstate(ios::failbit);
		throw IncorrectInput();
	}
	cout << "Colums: "; in_ >> matrix_.columns;
	if (!in_.good() || (matrix_.columns < 0))
	{
		in_.setstate(ios::failbit);
		throw IncorrectInput();
	}

	matrix_.Memmory(matrix_.rows, matrix_.columns);

	cout << "Enter Elements:" << endl;
	for (int i = 0; i < matrix_.rows; ++i)
	{
		for (int j = 0; j < matrix_.columns; ++j)
		{
			in_ >> matrix_.matrix[i][j];

			if (!in_.good())
			{
				in_.setstate(ios::failbit);
				throw IncorrectInput();
			}

			if ((in_.peek() == ' ') || (in_.peek() == '\n'))
				in_.ignore();
		}
	}

	return in_;
}

ifstream& operator>>(ifstream& in_, Matrix& matrix_)
{
	if (!in_.is_open())
		return in_;

	if (matrix_.matrix)
		matrix_.Clear();

	in_ >> matrix_.rows;
	if (matrix_.rows < 0)
	{
		in_.setstate(ios::failbit);
		throw IncorrectInput();
	}
	in_ >> matrix_.columns;
	if (matrix_.columns < 0)
	{
		in_.setstate(ios::failbit);
		throw IncorrectInput();
	}

	matrix_.Memmory(matrix_.rows, matrix_.columns);

	for (int i = 0; i < matrix_.rows; ++i)
	{
		for (int j = 0; j < matrix_.columns; ++j)
		{
			if (!(in_ >> matrix_.matrix[i][j]))
			{
				in_.setstate(ios::failbit);
				throw IncorrectInput();
			}
		}
	}

	return in_;
}

ostream& operator<<(ostream& out_, const Matrix& matrix_)
{
	if (!matrix_.matrix)
		return out_;

	for (int i = 0; i < matrix_.rows; ++i)
	{
		for (int j = 0; j < matrix_.columns; ++j)
			out_ << matrix_.matrix[i][j] << ' ';

		out_ << endl;
	}

	return out_;
}