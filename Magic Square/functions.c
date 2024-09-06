#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

void Matrix_Print(int** matrix_, size_t size_)
{
	if (!matrix_)
		return;

	printf("\n");

	for (size_t i = 0; i < size_; ++i)
	{
		for (size_t j = 0; j < size_; ++j)
			printf("%d ", matrix_[i][j]);

		printf("\n");
	}

	printf("\n");
}

int** Matrix_Create_F(const char* file_name_, size_t* size_)
{
	if (!file_name_)
		return NULL;

	FILE* fp;
	fopen_s(&fp, file_name_, "r");
	if (!fp)
		return NULL;

	fscanf_s(fp, "%Iu", size_);

	int** matrix = (int*)calloc(*size_, sizeof(int));
	if (!matrix)
	{
		fclose(fp);
		return NULL;
	}

	for (size_t i = 0; i < *size_; ++i)
	{
		matrix[i] = (int*)calloc(*size_, sizeof(int));
		if (!matrix[i])
		{
			for (size_t j = 0; j < i; ++j)
				free(matrix[j]);

			fclose(fp);
			free(matrix);
			return NULL;
		}
	}

	for (size_t i = 0; i < *size_; i++)
	{
		for (size_t j = 0; j < *size_; j++)
			fscanf_s(fp, "%d", &matrix[i][j]);
	}

	fclose(fp);
	return matrix;
}

bool Is_Magic_Square(int** matrix_, int size_)
{
	if (!matrix_ || !size_)
		return false;

	int main_diag = 0;
	int other_sums = 0;

	// Sum of Main Diagonal Elements
	for (size_t i = 0; i < size_; ++i)
	{
		main_diag += matrix_[i][i];
	}

	// Sum of Main Diagonal Elements
	for (int i = size_ - 1; i >= 0; --i)
	{
		other_sums += matrix_[i][i];
	}

	if (other_sums != main_diag)
		return false;

	// Sum of Lines Elements
	for (size_t i = 0; i < size_; ++i)
	{
		other_sums = 0;

		for (size_t j = 0; j < size_; ++j)
			other_sums += matrix_[i][j];

		if (other_sums != main_diag)
			return false;
	}

	// Sum of Columns Elements
	for (size_t i = 0; i < size_; ++i)
	{
		other_sums = 0;

		for (size_t j = 0; j < size_; ++j)
			other_sums += matrix_[j][i];

		if (other_sums != main_diag)
			return false;
	}

	return true;
}
