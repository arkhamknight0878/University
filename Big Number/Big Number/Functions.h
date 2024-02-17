#include"BigNumber.h"
#include<stdio.h>

/**
 * @brief ������� ����� ������
 * @param str_ ������
 * @return ����� ������
*/
unsigned MyStr_len(char* str_);

/**
 * @brief ������ ���������������� ������� �����
 * @param big_number_ ������� �����
 * @param res_ ���������, � ������� ������������ ���������� � �����
 * @return ��������� �� ���������, ���������� ������� �����
*/
BG* BG_create(char* big_number_, BG* res_);

/**
 * @brief ������� ������ ����� �� �����
 * @param big_number_ ���������, ���������� ���������� � �����
*/
void BG_out(BG* big_number_);

void BG_delete(BG* big_number_);

BG* BG_sum(BG* bg_first_, BG* bg_second_);

BG*  BG_diff(BG* bg_bigger_, BG* bg_smaller_);

BG* BG_devide(BG* bg_bigger_, BG* bg_smaller_);

BG* BG_mult(BG* bg_first_, BG* bg_second_);