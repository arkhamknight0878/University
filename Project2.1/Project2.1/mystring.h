#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/**
 * @brief : ������������ ���-�� �������� � ������
 * @param line_ : ���� ���������
 * @param f_ : ������ ���������
 * @return : ���-�� ��������
*/
unsigned int fgetline(char* line_, FILE* f_);

/**
 * @brief : ������������ ���-�� �������� � ������
 * @param Str_ : ������ �������
 * @return : ���-�� ��������
*/
unsigned int my_strlen(const char* Str_);

/**
 * @brief : ����������� ������
 * @param StrDest_ : ���� ��������
 * @param StrSrc_ : ������ �������
 * @return : ������������� ������
*/
char* my_strcpy(char* StrDest_, const char* StrSrc_);

/**
 * @brief : ����������� ������ � ����� ������
 * @param StrDest_ : ���� �����������
 * @param StrSrc_ : ��� �����������
 * @return : �������� ������
*/
char* my_strcat(char* StrDest_, const char* StrSrc_);

/**
 * @brief : ���������� ������
 * @param Str1_ : ������, ������� ����������
 * @param Str2_ : ������, � ������� ����������
 * @return : 
*/
int my_strcmp(const char* Str1_, const char* Str2_);

/**
 * @brief : ���������� ��������� �� ������ ��������� SubStr_
 * @param Str_ : 
 * @param StrSearch_ : 
 * @return : 
*/
char* my_strstr(const char* Str_, const char* StrSearch_);
