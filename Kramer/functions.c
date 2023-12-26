#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void matr_custom(double** matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			scanf_s("%lf", &matrix_[i][j]);
	}
}

void matr_print(double** matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			printf("%7.2lf", matrix_[i][j]);
		printf("\n");
	}
}

void matr_term_custom(double* matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
		scanf_s("%lf", &matrix_[i]);
}

void matr_term_print(double* matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
		printf("%7.2lf ", matrix_[i]);
	printf("\n");
}

void matr_minor(double** matrix_, double** minor_matrix_, unsigned size_, unsigned row_del, unsigned col_del)
{
	unsigned minor_row = 0;
	for (unsigned i = 0; i < size_; i++)
	{
		if (i != row_del)
		{
			for (unsigned j = 0, minor_col = 0; j < size_; j++)
			{
				if (j != col_del)
				{
					minor_matrix_[minor_row][minor_col] = matrix_[i][j];
					minor_col++;
				}
			}
			minor_row++;
		}
	}
}

double matr_determ(double** matrix_, unsigned size_)
{
	double determinant = 0;

	if (size_ == 1)
		determinant = matrix_[0][0];
	if (size_ == 2)
		determinant = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
	if (size_ > 2)
	{
		double k = 1;
		for (unsigned i = 0; i < size_; i++)
		{
			unsigned minor_size = size_ - 1;

			double** matrix_minor = calloc(minor_size, sizeof(double));
			for (unsigned n = 0; n < minor_size; n++)
				matrix_minor[n] = calloc(minor_size, sizeof(double));

			matr_minor(matrix_, matrix_minor, size_, 0, i);
			determinant += k * matrix_[0][i] * matr_determ(matrix_minor, minor_size);
			k *= -1;
		}
	}

	return determinant;
}

void term_replacement(double** matrix_, double* matrix_term, unsigned size_, unsigned replace_col_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		matrix_[i][replace_col_] = matrix_term[i];
	}
}

void matr_cpy(double** matrix_, double** matrix_cpy_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			matrix_cpy_[i][j] = matrix_[i][j];
	}
}

void matr_kramer(double A_matrix_determ, double** matrix_, double* matrix_term, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		double answer = 0;

		double** new_matrix = calloc(size_, sizeof(double));
		for (unsigned i = 0; i < size_; i++)
			new_matrix[i] = calloc(size_, sizeof(double));

		matr_cpy(matrix_, new_matrix, size_);

		term_replacement(new_matrix, matrix_term, size_, i);
		answer = matr_determ(new_matrix, size_) / A_matrix_determ;
		printf("\nX_%u = %5.2lf\n", i, answer);
	}
}