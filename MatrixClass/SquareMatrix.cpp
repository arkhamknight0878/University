#include "SquareMatrix.h"
#include <math.h>

SquareMatrix* SquareMatrix::Minor(size_t del_row_, size_t del_column_)
{
	size_t minor_row = 0;
	SquareMatrix* minor = new SquareMatrix(rows - 1);

	for (size_t i = 0; i < rows; ++i)
	{
		if (i == del_row_) continue;

		size_t newCol = 0;

		if (i != del_row_)
		{
			for (size_t j = 0, minor_columns = 0; j < rows; ++j)
			{
				if (j != del_column_) 
					minor->matrix[minor_row][minor_columns++] = matrix[i][j];
			}
			++minor_row;
		}
	}

	return minor;
}

SquareMatrix::SquareMatrix(const SquareMatrix& other_)
{
	if (!other_.matrix)
	{
		matrix = nullptr;
		return;
	}

	rows = columns = other_.rows;

	Memmory(rows, columns);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < rows; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& other_)
{
	if (this == &other_)
		return *this;

	for (size_t i = 0; i < rows; ++i)
		delete matrix[i];

	delete[] matrix;

	Memmory(other_.rows, other_.rows);
	rows = columns = other_.rows;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < rows; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}

	return *this;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw 2;

	SquareMatrix result(rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
	}

	return result;
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw 2;

	SquareMatrix result(rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
	}

	return result;
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other_) const
{
	if (rows != other_.columns || columns != other_.rows)
		throw 2;

	SquareMatrix result(rows);

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

SquareMatrix SquareMatrix::operator*(int data_) const
{
	SquareMatrix result(rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] * data_;
	}

	return result;
}

SquareMatrix SquareMatrix::operator/(SquareMatrix& other_) const
{
	return (*this * other_.Reverse());
}

SquareMatrix SquareMatrix::operator/(int data_) const
{
	SquareMatrix result(rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] / data_;
	}

	return result;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 2;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] += other_.matrix[i][j];
	}

	return *this;
}

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		throw 2;

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] -= other_.matrix[i][j];
	}

	return *this;
}

SquareMatrix& SquareMatrix::operator/=(SquareMatrix& other_)
{
	return (*this *= other_.Reverse());
}

SquareMatrix& SquareMatrix::operator/=(int data_)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] /= data_;
	}

	return *this;
}

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& other_)
{
	if (rows != other_.columns || columns != other_.rows)
		throw 2;

	SquareMatrix temp = *this;
	columns = other_.columns;

	for (size_t i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	Memmory(rows, columns);

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

SquareMatrix& SquareMatrix::operator*=(int data_)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			matrix[i][j] = matrix[i][j] * data_;
	}

	return *this;
}

bool SquareMatrix::operator==(const SquareMatrix& other_)
{
	if (rows != other_.rows || columns != other_.columns)
		return false;

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

bool SquareMatrix::operator!=(const SquareMatrix& other_)
{
	return !(&other_ == this);
}

double SquareMatrix::Determinant()
{
	double determinant = 0;

	if (rows == 1)
		return matrix[0][0];
	else if (rows == 2)
		return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
	else
	{
		double sign = 1;
		for (size_t i = 0; i < rows; ++i)
		{
			SquareMatrix* minor = Minor(0, i);

			determinant += pow(-1, i) * matrix[0][i] * minor->Determinant();
			sign *= -1;
		}
	}

	return determinant;
}

SquareMatrix SquareMatrix::Transpon()
{
	SquareMatrix result(rows);

	for (size_t i = 0; i < result.rows; ++i)
	{
		for (size_t j = 0; j < result.columns; ++j)
			result.matrix[i][j] = matrix[j][i];
	}

	return result;
}

SquareMatrix SquareMatrix::Reverse()
{
	double determinant = Determinant();
	SquareMatrix result(rows);
	SquareMatrix transpon = Transpon();

	if (determinant)
	{
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < rows; ++j)
			{
				SquareMatrix* minor = transpon.Minor(i, j);
				result.matrix[i][j] = pow(-1, i + j) * minor->Determinant() / determinant;
			}
		}
	}

	return result;
}

istream& operator>>(istream& in_, SquareMatrix& matrix_)
{
	for (size_t i = 0; i < matrix_.rows; ++i)
		delete[] matrix_.matrix[i];

	delete[] matrix_.matrix;

	matrix_.rows = matrix_.columns = 0;

	cout << endl << "Enter Matrix Size:" << endl << "> ";
	in_ >> matrix_.rows;

	while (matrix_.rows < 0)
	{
		cout << endl << "Rows Amount Must Be Higher Then 0. Try Again" << endl << "> ";
		in_ >> matrix_.rows;
	}

	if (!in_.good())
		exit(1);

	matrix_.columns = matrix_.rows;

	matrix_.Memmory(matrix_.rows, matrix_.columns);

	cout << endl << "Enter Matrix:" << endl << "> ";

	for (size_t i = 0; i < matrix_.rows; ++i)
	{
		for (size_t j = 0; j < matrix_.columns; ++j)
		{
			in_ >> matrix_.matrix[i][j];

			if (in_.peek() == ' ' || in_.peek() == '\n')
				in_.ignore();

			if (!in_.good())
				exit(1);
		}
	}

	return in_;
}

ostream& operator<<(ostream& out_, const SquareMatrix& matrix_)
{
	if (matrix_.rows == 1)
	{
		out_ << "(";

		for (int i = 0; i < matrix_.columns - 1; ++i)
			out_ << matrix_.matrix[0][i] << " ";

		out_ << matrix_.matrix[0][matrix_.columns - 1];

		out_ << ")";

		return out_;
	}
	else if (matrix_.rows == 2)
	{
		out_ << "/";

		for (int i = 0; i < matrix_.rows; ++i)
		{
			for (int j = 0; j < matrix_.columns - 1; ++j)
				out_ << matrix_.matrix[i][j] << " ";

			out_ << matrix_.matrix[i][matrix_.columns - 1];

			if (i == 0)
				out_ << "\\" << endl << "\\";
			else
			{
				out_ << "/";
				return out_;
			}
		}
	}
	else
	{
		for (int i = 0; i < matrix_.rows; ++i)
		{
			if (!i)
				out_ << "/";
			else if (i == matrix_.rows - 1)
				out_ << "\\";
			else
				out_ << "|";

			for (int j = 0; j < matrix_.columns - 1; ++j)
				out_ << matrix_.matrix[i][j] << " ";

			out_ << matrix_.matrix[i][matrix_.columns - 1];

			if (!i)
				out_ << "\\" << endl;
			else if (i == matrix_.rows - 1)
			{
				out_ << "/";
				return out_;
			}
			else
				out_ << "|" << endl;
		}
	}
}