#include<stdio.h>
#include<stdlib.h>

/**
 * @brief : Заполняет массив(матрицу) рандомными числами
 * @param matrix_ : Матрица
 * @param size_ : Размер матрицы
*/
void rand_matrix(int** matrix_, unsigned size_);

/**
 * @brief : Выводит матрицу на экран
 * @param matrix_ : Матрица
 * @param size_ : Размер матрицы
*/
void matrix_print(int** matrix_, unsigned size_);

/**
 * @brief : Ищет минор матрицы
 * @param matrix_ : Матрица
 * @param minor_ : Отдельный двумерный массив под минор матрицы
 * @param size_ : Размер матрицы
 * @param row_number : Столбец, который убираем
 * @param column_number : Строка, которую убираем
*/
void matrix_minor(int** matrix_, int** minor_, unsigned size_, unsigned row_number, unsigned column_number);

/**
 * @brief : Ищет определитель матрицы
 * @param matrix : Матрица
 * @param size_ : Размер матрицы
 * @return : Определитель матрицы
*/
double matrix_determ(int** matrix, int size_);

/**
 * @brief : Транспонириует матрицу
 * @param matrix : Исходная матрица
 * @param transpon_matrix_ : Транспонированная матрица
 * @param size_ : Размер матрицы
*/
void transpon(int** matrix, int** transpon_matrix_, int size_);
