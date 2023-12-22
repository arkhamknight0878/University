#include "final.h"
#include "functions.h"
#include <math.h>

void matrix_reverse(int** matrix_, int** reverse_, unsigned size_)
{
	long long deteminant = 0;
	deteminant = matrix_determ(matrix_, size_);

	if (deteminant != 0)
	{
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				/*Выделяем память для миноров матрицы*/
				int** minor = calloc(size_ - 1, sizeof(int));
				for (int k = 0; k < size_ - 1; k++)
				{
					minor[k] = calloc(size_ - 1, sizeof(int));
				}

				matrix_minor(matrix_, minor, size_, i, j);
				reverse_[i][j] = pow(-1, i + j + 2) * matrix_determ(minor, size_) / deteminant;

				free(minor);
			}
		}
	}
	else
	{
		printf("Определитель равен нулю\nПоэтому обратной матрицы нет");
	}
}
