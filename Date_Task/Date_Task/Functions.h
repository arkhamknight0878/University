#include<stdbool.h>
#include<stdio.h>
#include"Date.h"

/**
 * @brief ������ ���� � ����������������� ����������
 * @param date_ ��������� ����
*/
void date_create(Date* date_);

/**
 * @brief ������� ���� �� �����
 * @param date_ ��������� ����
*/
void date_output(Date* date_);

/**
 * @brief ������������ ���-�� ���������� ���� � ��������� ����� ����� ������
 * @param earlier_date_ ������ ����
 * @param later_date_ ������� ����
 * @return ���-�� ���������� ���� � ����������
*/
unsigned date_leap_days(Date* earlier_date_, Date* later_date_);

/**
 * @brief ������� ������ ����� ����� ������
 * @param earlier_date_ ������ ����
 * @param later_date_ ������� ����
 * @param res_ ������� ����� ������
*/
void date_difference(Date* earlier_date_, Date* later_date_, Date* res_);

/**
 * @brief ��������� ���������� ��� ��� ���
 * @param date_ ����������� ����
 * @return true, ���� ��� � ���� ����������; false �����
*/
bool is_leap(Date* date_);