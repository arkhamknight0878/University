#include"date.h"
#include<stdio.h>
#include<stdbool.h>

/**
 * @brief ������� ������� �� ������� ����� ����� ������
 * @param date_1 ������� ����
 * @param date_2 ������ ����
 * @param res_ �������� ���������
 * @return 
*/
Date time_difference(Date* date_1, Date* date_2, Date* res_);

/**
 * @brief ���������� ���������� ��� ��� ��� ���
 * @param year_ ���, ������� ���������
 * @return true, ���� ��� ����������, false �����
*/
bool is_leap_year(Date* date_);