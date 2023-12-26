#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

int main()
{
	unsigned size = 0;
	unsigned minor_size = 0;
	double determinant = 0;

	printf("Enter Matrix Sizez\nMatrix size = ");
	scanf_s("%u\n", &size);
	minor_size = size - 1;

	/*�������� ������ ��� �������*/
	double** matrix = calloc(size, sizeof(double));
	for (unsigned i = 0; i < size; i++)
		matrix[i] = calloc(size, sizeof(double));

	/*�������� ������ ��� ��������� �����*/
	double* constant_term = calloc(size, sizeof(double));

	/*��������� ������� � ��������� �����*/
	matr_custom(matrix, size);
	matr_term_custom(constant_term, size);

	/*������� �� ����� ������� � ��������� �����*/
	printf("\nMatrix A:\n\n");
	matr_print(matrix, size);
	printf("\nConstant Terms:\n\n");
	matr_term_print(constant_term, size);

	/*������� ������������ �������� �������*/
	determinant = matr_determ(matrix, size);

	printf("\nAnswers:\n");
	matr_kramer(determinant, matrix, constant_term, size);

	return 0;
}