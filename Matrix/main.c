#include<stdio.h>
#include <stdlib.h>
#include"functions.h"

int main()
{
	int size = 0;
	printf("Enter Matrix Size\nMatrix Size = ");
	scanf_s("%d", &size);
	
	/*Выделяем память под матрицу*/
	int** matrix = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(int));

	/*Выделяем память под обратную матрицу*/
	int** reverse = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		reverse[i] = calloc(size, sizeof(int));

	/*Выделяем память под транспонирование матрицы*/
	int** transpon = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		transpon[i] = calloc(size, sizeof(int));

	printf("Matrix A:\n\n");
	matr_rand(matrix, size);
	matr_print(matrix, size);
	printf("\n\n");

	printf("Almost Reverse Matrix:\n\n");
	matr_reverse(matrix, reverse, size);
	matr_print(reverse, size);
	printf("\n\n");

	printf("Reverse of Matrix A:\n\n");
	matr_transpon(reverse, transpon, size);
	matr_print(transpon, size);

	return 0;
}