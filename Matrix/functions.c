#include "functions.h"


void rand_matrix(int** matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			matrix_[i][j] = rand() % 10 + 1;
	}
}

void matrix_print(int** matrix, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			printf("%4d ", matrix[i][j]);
		printf("\n");
	}
	
}

void matrix_minor(int** matrix_, int** minor_, unsigned size_, unsigned row_minor_, unsigned column_minor_)
{
	unsigned row_final = 0;
	unsigned column_final = 0;

	for (unsigned i = 0; i < size_; i++)
	{
		if (i != row_minor_)
		{
			for (unsigned j = 0; j < size_; j++)
			{
				if (j != column_minor_)
				{
					minor_[row_final][column_final] = matrix_[i][j];
					column_final++;
				}
			}
			row_final++;
		}
	}
}

double matrix_determ(int** matrix_, int size_)
{
	double determinant = 0;

	if (size_ == 1)
		determinant = matrix_[0][0];

	if (size_ == 2)
	{
		determinant = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
	}

	if (size_ > 2)
	{
		int k = 1;
		for (int j = 0; j < size_; j++)
		{
			/*Выделяем память под миноры матрицы*/
			int** minor = calloc(size_ - 1, sizeof(int));
			for (int k = 0; k < size_ - 1; k++)
			{
				minor[k] = calloc(size_ - 1, sizeof(int));
			}

			matrix_minor(matrix_, minor, size_, 0, j);
			determinant += k * matrix_[0][j] * matrix_determ(matrix_, size_);
			k *= -1;

			free(minor);
		}

	}

	return determinant;
}

void transpon(int** matrix_, int** transpon_matrix_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int b = 0; b < size_; b++)
		{
			transpon_matrix_[b][i] = matrix_[i][b];
		}
	}
}