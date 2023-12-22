#include<stdio.h>
#include<stdlib.h>

void rand_matrix(int** matrix_, unsigned size_);

void matrix_print(int** matrix_, unsigned size_);

void matrix_minor(int** matrix_, int** munor_, unsigned size_, unsigned row_number, unsigned column_number);

double matrix_determ(int** matrix, int size_);

void transpon(int** matrix, int** transpon_matrix_, int size_);