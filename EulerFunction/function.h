#include<stdbool.h>
#include<math.h>

/**
 * @brief : ��������� ��� ����� �� �������� ��������
 * @param number_ : �����, ������� ���������
 * @param range_ : �����, � ������ ���������
 * @return : true, ���� ��� ����� ������� ������, false �����
*/
bool is_relatively_prime(unsigned long long number_, unsigned long long range_);

/**
 * @brief : ������������ ���-�� ������� ������� ����� �� 1 �� ��������� �����
 * @param range_ : ������������ ����� � ����������
 * @return : ���-�� ������� ������� ����� �� 1 �� ��������� �����
*/
unsigned int euler_function(unsigned long long range_);
