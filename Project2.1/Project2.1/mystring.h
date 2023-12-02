#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/**
 * @brief : Подсчитывает кол-во символов в строке
 * @param line_ : Куда считываем
 * @param f_ : Откуда считываем
 * @return : Кол-во символов
*/
unsigned int fgetline(char* line_, FILE* f_);

/**
 * @brief : Подсчитываем кол-во символов в строке
 * @param Str_ : Откуда считаем
 * @return : Кол-во символов
*/
unsigned int my_strlen(const char* Str_);

/**
 * @brief : Копирование строки
 * @param StrDest_ : Куда копируем
 * @param StrSrc_ : Откуда коируем
 * @return : Скопированная строка
*/
char* my_strcpy(char* StrDest_, const char* StrSrc_);

/**
 * @brief : Подставляет строку к концу другой
 * @param StrDest_ : Куда подставляем
 * @param StrSrc_ : Что подстовляем
 * @return : Итоговая строка
*/
char* my_strcat(char* StrDest_, const char* StrSrc_);

/**
 * @brief : Сравнивает строки
 * @param Str1_ : Строка, которую сравниваем
 * @param Str2_ : Строка, с которой сравниваем
 * @return : 
*/
int my_strcmp(const char* Str1_, const char* Str2_);

/**
 * @brief : Возвращает указатель на первое вхождение SubStr_
 * @param Str_ : 
 * @param StrSearch_ : 
 * @return : 
*/
char* my_strstr(const char* Str_, const char* StrSearch_);
