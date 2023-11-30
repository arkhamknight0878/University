#include <stdbool.h>

/**
 * @brief : ��������� number_ �� ������� ������
 * @param number_ : ���������� �����
 * @return : true ���� �� ������������� ��������, false �����
*/
bool Is_Idiot(const unsigned int number_);

/**
 * @brief : ������������ ����� �����
 * @param startnumber_ : ��������� �����
 * @param guessnuber_ : ����������� �����
 * @return : ����� �����
*/
unsigned int Bulls(unsigned int startnumber_, unsigned int guessnumber_);

/**
 * @brief : ������������ ����� �����
 * @param startnumber_ : ��������� �����
 * @param guessnuber_ : ���������� �����
 * @return : ����� �����
*/
unsigned int Cows(unsigned int startnumber_, unsigned int guessnumber_);
