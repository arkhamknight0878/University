#include "SquareMatrix.h"
#include <math.h>

SquareMatrix* SquareMatrix::Minor(size_t del_row_, size_t del_column_)
{
	size_t minor_row = 0;
	SquareMatrix* minor = new SquareMatrix(rows - 1);

	for (int i = 0; i < rows; ++i)
	{
		if (i == del_row_) continue;

		//size_t newCol = 0;

		if (i != del_row_)
		{
			for (int j = 0, minor_columns = 0; j < rows; ++j)
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

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& other_)
{
	if (this == &other_)
		return *this;

	Clear();

	Memmory(other_.rows, other_.rows);
	rows = columns = other_.rows;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
			matrix[i][j] = other_.matrix[i][j];
	}

	return *this;
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffSize();

	SquareMatrix result(rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] + other_.matrix[i][j];
	}

	return result;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& other_)
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

SquareMatrix SquareMatrix::operator-(const SquareMatrix& other_) const
{
	if (rows != other_.rows || columns != other_.columns)
		throw DiffSize();

	SquareMatrix result(rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] - other_.matrix[i][j];
	}

	return result;
}

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& other_)
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

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other_) const
{
	if (rows != other_.columns || columns != other_.rows)
		throw DiffRowsColumns();

	SquareMatrix result(rows);

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

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& other_)
{
	if (rows != other_.columns || columns != other_.rows)
		throw DiffRowsColumns();

	SquareMatrix temp = *this;
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

SquareMatrix SquareMatrix::operator*(int value_) const
{
	SquareMatrix result(rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result.matrix[i][j] = matrix[i][j] * value_;
	}

	return result;
}

SquareMatrix SquareMatrix::operator*=(int value_)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] *= value_;
	}

	return *this;
}

SquareMatrix SquareMatrix::operator/(int value_) const
{
	SquareMatrix result(rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			result[i][j] /= value_;
	}

	return *this;
}

SquareMatrix& SquareMatrix::operator/=(int value_)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			matrix[i][j] /= value_;
	}

	return *this;
}

SquareMatrix SquareMatrix::Pow(int power_)
{
	SquareMatrix result = *this;

	for (int i = 2; i <= power_; ++i)
		result += *this;

	return result;
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
		for (int i = 0; i < rows; ++i)
		{
			SquareMatrix* minor = Minor(0, i);

			determinant += matrix[0][i] * minor->Determinant();
			sign *= -1;
		}
	}

	return determinant;
}

SquareMatrix SquareMatrix::Transpon()
{
	SquareMatrix result(rows);

	for (int i = 0; i < result.rows; ++i)
	{
		for (int j = 0; j < result.columns; ++j)
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
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				SquareMatrix* minor = transpon.Minor(i, j);
				result.matrix[i][j] = pow(-1, i + j) * minor->Determinant() / determinant;
			}
		}
	}

	return result;
}

double SquareMatrix::MatrixTace()
{
	double result = 0;

	for (int i = 0; i < rows; ++i)
		result += matrix[i][i];

	return result;
}

istream& operator>>(istream& in_, SquareMatrix& matrix_)
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

ifstream& operator>>(ifstream& in_, SquareMatrix& matrix_)
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

ostream& operator<<(ostream& out_, const SquareMatrix& matrix_)
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

SquareMatrix SmoothMatrix(SquareMatrix& matrix_)
{
	int amount = 0;
	int sum = 0;
	int matrix_size = matrix_.GetSize();

	SquareMatrix new_matrix(matrix_size);

	for (int i = 0; i < matrix_size; ++i)
	{
		amount = sum = 0;

		for (int j = 0; j < matrix_size; ++j)
		{
			for (int p = i - 1; p < i + 1; ++p)
			{
				if (p < 0) continue;

				for (int n = j - 1; n < j + 1; ++n)
				{
					if (n < 0) continue;

					if (p == i && n == j) continue;

					sum += matrix_[p][n];
					++amount;
				}
			}

			new_matrix[i][j] = sum / amount;
		}
	}

	return new_matrix;
}

vector<double> TraceToVector(const SquareMatrix matrix_, int max_power_)
{
	vector<double> result;
	SquareMatrix matrix = matrix_;

	for (int i = 2; i <= max_power_; ++i)
	{
		result.push_back(matrix.MatrixTace());

		matrix *= matrix_;
	}

	return result;
}
