#include<stdio.h>
#include <stdlib.h>
#include"functions.h"

int main()
{
	unsigned size = 0;
	printf("Enter Matrix Size\nMatrix Size = ");
	scanf_s("%u", &size);
	
	/*Выделяем память под матрицу*/
	double** matrix = calloc(size, sizeof(double));
	for (unsigned i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(double));

	/*Выделяем память под обратную матрицу*/
	double** reverse = calloc(size, sizeof(double));
	for (unsigned i = 0; i < size; i++)
		reverse[i] = calloc(size, sizeof(double));

	/*Выделяем память под транспонирование матрицы*/
	double** transpon = calloc(size, sizeof(double));
	for (unsigned i = 0; i < size; i++)
		transpon[i] = calloc(size, sizeof(double));

	printf("\nMatrix A:\n\n");
	matr_rand(matrix, size);
	matr_print(matrix, size);
	printf("\n");

	matr_reverse(matrix, reverse, size);
	printf("Almost Reversed Matrix:\n\n");
	matr_print(reverse, size);
	printf("\n");

	printf("Reversed A Matrix:\n\n");
	matr_transpon(reverse, transpon, size);
	matr_print(transpon, size);

	return 0;
}