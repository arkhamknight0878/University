#include<stdio.h>
#include<stdlib.h>

/**
 * @brief : ��������� ������(�������) ���������� �������
 * @param matrix_ : �������
 * @param size_ : ������ �������
*/
void rand_matrix(int** matrix_, unsigned size_);

/**
 * @brief : ������� ������� �� �����
 * @param matrix_ : �������
 * @param size_ : ������ �������
*/
void matrix_print(int** matrix_, unsigned size_);

/**
 * @brief : ���� ����� �������
 * @param matrix_ : �������
 * @param minor_ : ��������� ��������� ������ ��� ����� �������
 * @param size_ : ������ �������
 * @param row_number : �������, ������� �������
 * @param column_number : ������, ������� �������
*/
void matrix_minor(int** matrix_, int** minor_, unsigned size_, unsigned row_number, unsigned column_number);

/**
 * @brief : ���� ������������ �������
 * @param matrix : �������
 * @param size_ : ������ �������
 * @return : ������������ �������
*/
double matrix_determ(int** matrix, int size_);

/**
 * @brief : �������������� �������
 * @param matrix : �������� �������
 * @param transpon_matrix_ : ����������������� �������
 * @param size_ : ������ �������
*/
void transpon(int** matrix, int** transpon_matrix_, int size_);
