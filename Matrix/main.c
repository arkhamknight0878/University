#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
#include"final.h"

int main()
{
	unsigned size = 0;
	double determ = 0;
	printf("Enter Matrix Size\nMatrix Size = ");
	scanf_s("%d", &size);

	/*Выделяем память под матрицу*/
	int** matrix = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = calloc(size, sizeof(int));
	}

	/*Выделяем память под транспонированную обратную матрицу*/
	int** transp_matrix = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		transp_matrix[i] = calloc(size, sizeof(int));
	}

	/*Выделяем память под обратную матрицу*/
	int** reverse_matrix = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		reverse_matrix[i] = calloc(size, sizeof(int));
	}

	/*Заполняем матрицу рандомными значениями*/
	rand_matrix(matrix, size);

	printf("Your matrix:\n\n");
	/*Печатаем матрицу*/
	matrix_print(matrix, size);

	matrix_reverse(matrix, reverse_matrix, size);

	transpon(reverse_matrix, transp_matrix, size);
	matrix_print(transp_matrix, size);


	free(matrix);
	free(reverse_matrix);
	free(transp_matrix);

	return 0;
}