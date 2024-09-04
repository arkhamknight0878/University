#include "functions.h"

#include <stdio.h>
#include <time.h>

void Matrix_Print(int** matrix_, size_t size_)
{
	if (!matrix_)
		return;

	for (size_t i = 0; i < size_; ++i)
	{
		for (size_t j = 0; j < size_; ++j)
			printf("%d ", matrix_[i][j]);

		printf("\n");
	}
}

int** Matrix_Create_File(const char* file_name_)
{
	FILE* file_pointer;
	fopen_s(&file_pointer, file_name_, "r");
	if (!file_pointer)
	{
		printf("!!! Unable to Open File !!!\n");
		return NULL;
	}

	size_t size = 0;

	fscanf_s(file_pointer, "%Iu", &size);

	int** matrix = (int*)calloc(size, sizeof(int));
	if (!matrix)
		return NULL;

	for (size_t i = 0; i < size; ++i)
	{
		matrix[i] = (int*)calloc(size, sizeof(int));
		if (!(matrix[i]))
		{
			for (size_t j = 0; j < i; ++j)
			{
				free(matrix[j]);
			}

			free(matrix);
			return NULL;
		}

		for (size_t j = 0; j < size; ++j)
			fscanf_s(file_pointer, "%d", &matrix[i][j]);
	}

	fclose(file_pointer);

	printf("Created matrix:\n");
	Matrix_Print(matrix, size);

	return matrix;
}

void Swap(int* element1_, int* element2_)
{
	int temp = *element1_;
	*element1_ = *element2_;
	*element2_ = temp;
}

void Selection_Sort(int* arr_, size_t size_)
{
	if (!arr_)
		return;

	size_t min_el_ptr = 0;

	for (size_t i = 0; i < size_; ++i)
	{
		min_el_ptr = i;

		for (size_t j = i + 1; j < size_; ++j)
		{
			if (arr_[min_el_ptr] > arr_[j])
				min_el_ptr = j;
		}

		if (min_el_ptr != i)
			Swap(&arr_[min_el_ptr], &arr_[i]);
	}
}

void First_Task(int** matrix, size_t size_, size_t index_)
{
	if (!matrix || size_ == 0 || index_ == 0)
		return;

	if (matrix[index_ - 1][index_ - 1] % 2 != 0)
		Selection_Sort(matrix[index_ - 1], size_);
}
