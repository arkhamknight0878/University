#include<stdio.h>
#include <stdlib.h>
#include"functions.h"

int main()
{
	int size = 0;
	printf("Enter Matrix Size\nMatrix Size = ");
	scanf_s("%d", &size);
	
	/*�������� ������ ��� �������*/
	double** matrix = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(double));

	/*�������� ������ ��� �������� �������*/
	double** reverse = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++)
		reverse[i] = calloc(size, sizeof(double));

	/*�������� ������ ��� ���������������� �������*/
	double** transpon = calloc(size, sizeof(double));
	for (int i = 0; i < size; i++)
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