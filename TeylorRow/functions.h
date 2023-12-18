#include<math.h>

/**
 * @brief : ��������� �����
 * @param number_ : �����, ��������� �������� �������
 * @return : ��������� �����
*/
unsigned long long factorial(unsigned long long number_);

/**
 * @brief : ���������� ���������������� ������� � ��� ������� � ������ �������� �������� eps
 * @param exp_ : ����������
 * @param x_ : �������� X
 * @return : ����� ��-�� ������������� ���� �������
*/
double exp_to_teylor(const double exp_, double x_);