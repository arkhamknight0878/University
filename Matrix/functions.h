
void matr_rand(int** matrix_, int size_);

void matr_print(int** matrix_, int size_);

void matr_minor(int** matrix_, int** minor_, int size_, int del_row, int del_col);

double matr_determ(int** matrix_, int size_);

void matr_reverse(int** matrix_, double** reverse_, int size_);

void matr_transpon(int** matrix_, int** transpon_, int size_);

/*Вделяем память под миноры матрицы*/
//int** minor = calloc(minor_size, sizeof(int));
//for (int i = 0; i < minor_size; i++)
//	minor[i] = calloc(minor_size, sizeof(int));

/*Тест миноров*/
/*printf("\n");
matr_minor(matrix, minor, size, 0, 0);
matr_print(minor, minor_size);*/

/*Тест поиска определителя*/
/*printf("\n");
determinant = matr_determ(matrix, size);
printf("det = %d", determinant);*/