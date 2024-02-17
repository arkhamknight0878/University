#include<stdbool.h>
#include<stdio.h>
#include"Date.h"

/**
 * @brief Создаёт дату с пользовательскими значениями
 * @param date_ Созданная дата
*/
void date_create(Date* date_);

/**
 * @brief Выводит дату на экран
 * @param date_ Выводимая дата
*/
void date_output(Date* date_);

/**
 * @brief Подсчитывает кол-во високосных дней в промжутке между двумя датами
 * @param earlier_date_ Ранняя дата
 * @param later_date_ Поздняя дата
 * @return Кол-во високосных дней в промежутке
*/
unsigned date_leap_days(Date* earlier_date_, Date* later_date_);

/**
 * @brief Считает разицу между двумя датами
 * @param earlier_date_ Ранняя дата
 * @param later_date_ Поздняя дата
 * @param res_ Разница между датами
*/
void date_difference(Date* earlier_date_, Date* later_date_, Date* res_);

/**
 * @brief Проверяет високосный год или нет
 * @param date_ Проверяемая дата
 * @return true, если год в дате високосный; false иначе
*/
bool is_leap(Date* date_);