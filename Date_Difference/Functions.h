#include<stdbool.h>
#include<stdio.h>
#include"Date.h"

/**
 * @brief : ��������� ���������� � ���� ����������������� ����������
 * @param date_ : ����
*/
void date_create(Date* date_);

/**
 * @brief : ������� ���� �� �����
 * @param date_ : ����
*/
void date_output(Date* date_);

/**
 * @brief : ������� ������� ����� ����� ������
 * @param past_date_ : ������ ����
 * @param last_date_ : ������� ����
 * @param res_ : �������� ���� ���
 * @return : ���������, ���������� ���������� � �������� � �����
*/
void date_difference(Date* past_date_, Date* last_date_, Date* res_);

/**
 * @brief : ��������� ���������� ��� ��� ���
 * @param date_ : ����
 * @return : true ���� ��� ����������; false �����
*/
bool is_leap(Date* date_);