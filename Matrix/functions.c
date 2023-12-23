#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void matr_rand(int** matrix_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			matrix_[i][j] = rand() % 10;
		}
	}
}

void matr_print(int** matrix_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
			printf("%4d ", matrix_[i][j]);
		printf("\n");
	}
}

void matr_minor(int** matrix_, int** minor_, int size_, int del_row, int del_col)
{
	int minor_row = 0;

	for (int i = 0; i < size_; i++)
	{
		if (i != del_row)
		{
			for (int j = 0, minor_col = 0; j < size_; j++)
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

int matr_determ(int** matrix_, int size_)
{
	int determinant = 0;

	if (size_ == 1)
		determinant = matrix_[0][0];
	if (size_ == 2)
		determinant = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
	if (size_ > 2)
	{
		int k = 1;
		for (int i = 0; i < size_; i++)
		{
			int minor_size = size_ - 1;
			int** minor = calloc(minor_size, sizeof(int));
			for (int k = 0; k < minor_size; k++)
				minor[k] = calloc(minor_size, sizeof(int));

			matr_minor(matrix_, minor, size_, 0, i);
			determinant += k * matrix_[0][i] * matr_determ(minor, minor_size);
			k *= -1;
		}
	}

	return determinant;
}

void matr_reverse(int** matrix_, int** reverse_, int size_)
{
	int determinant = matr_determ(matrix_, size_);
	if (determinant != 0)
	{
		for (int i = 0; i < size_; i++)
		{
			for(int j = 0; j < size_; j++)
			{
				int minor_size = size_ - 1;
				int** minor = calloc(minor_size, sizeof(int));
				for (int i = 0; i < minor_size; i++)
					minor[i] = calloc(minor_size, sizeof(int));

				matr_minor(matrix_, minor, size_, i, j);
				reverse_[i][j] = pow(-1, i + j + 2) * matr_determ(minor, minor_size) / determinant;
			}
		}
	}
}

void matr_transpon(int** matrix_, int** transpon_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
			transpon_[j][i] = matrix_[i][j];
	}
}