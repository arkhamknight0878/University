#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void matr_rand(double** matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
		{
			matrix_[i][j] = rand() % 8;
		}
	}
}

void matr_print(double** matrix_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
			printf("%5.2lf ", matrix_[i][j]);
		printf("\n");
	}
}

void matr_minor(double** matrix_, double** minor_, unsigned size_, unsigned del_row, unsigned del_col)
{
	int minor_row = 0;

	for (unsigned i = 0; i < size_; i++)
	{
		if (i != del_row)
		{
			for (unsigned j = 0, minor_col = 0; j < size_; j++)
			{
				if (j != del_col)
				{
					minor_[minor_row][minor_col] = matrix_[i][j];
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
			double minor_size = size_ - 1;
			double** minor = calloc(minor_size, sizeof(double));
			for (unsigned k = 0; k < minor_size; k++)
				minor[k] = calloc(minor_size, sizeof(double));

			matr_minor(matrix_, minor, size_, 0, i);
			determinant += k * matrix_[0][i] * matr_determ(minor, minor_size);
			k *= -1;
		}
	}

	return determinant;
}

void matr_reverse(double** matrix_, double** reverse_, unsigned size_)
{
	double determinant = 0;
	determinant = matr_determ(matrix_, size_);
	printf("Det of A = %5.2lf\n\n", determinant);
	if (determinant != 0)
	{
		for (unsigned i = 0; i < size_; i++)
		{
			for(unsigned j = 0; j < size_; j++)
			{
				double minor_size = size_ - 1;
				double** minor = calloc(minor_size, sizeof(double));
				for (unsigned i = 0; i < minor_size; i++)
					minor[i] = calloc(minor_size, sizeof(double));

				matr_minor(matrix_, minor, size_, i, j);
				reverse_[i][j] = pow(-1, i + j) * matr_determ(minor, minor_size) / determinant;
			}
		}
	}
}

void matr_transpon(double** matrix_, double** transpon_, unsigned size_)
{
	for (unsigned i = 0; i < size_; i++)
	{
		for (unsigned j = 0; j < size_; j++)
		{
			transpon_[j][i] = matrix_[i][j];
		}
	}
}