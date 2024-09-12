#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Matrix_Print(int** matrix_, size_t size_)
{
	if (!matrix_)
		return;

	for (size_t i = 0; i < size_; ++i)
	{
		for (size_t j = 0; j < size_; ++j)
			cout << matrix_[i][j] << " ";

		cout << endl;
	}

	cout << endl;
}

int Matrix_Create_F(const char* file_name_, int**& matrix_, size_t& size_)
{
	if (!file_name_)
		return -1;

	FILE* fp;
	fopen_s(&fp, file_name_, "r");
	if (!fp)
		return -2;

	fscanf_s(fp, "%Iu", &size_);

	matrix_ = new int* [size_];
	if (!matrix_)
	{
		fclose(fp);
		return -3;
	}

	for (size_t i = 0; i < size_; ++i)
	{
		matrix_[i] = new int[size_];
		if (!matrix_[i])
		{
			for (size_t j = 0; j < i; ++j)
				free(matrix_[j]);

			fclose(fp);
			free(matrix_);
			return -3;
		}
	}

	for (size_t i = 0; i < size_; i++)
	{
		for (size_t j = 0; j < size_; j++)
			fscanf_s(fp, "%d", &matrix_[i][j]);
	}

	fclose(fp);
	return 0;
}

bool Is_Magic_Square(int** matrix_, size_t size_)
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
