#include<stdbool.h>
#include<stdio.h>
#include"Date.h"

/**
 * @brief : Заполняет информацию о дате пользовательскими значениями
 * @param date_ : Дата
*/
void date_create(Date* date_);

/**
 * @brief : Выводит дату на экран
 * @param date_ : Дата
*/
void date_output(Date* date_);

/**
 * @brief : Считает разницу между двумя датами
 * @param past_date_ : Ранняя дата
 * @param last_date_ : Поздняя дата
 * @param res_ : Разность двух дат
 * @return : Структура, содержащая информацию о разности в датах
*/
void date_difference(Date* past_date_, Date* last_date_, Date* res_);

/**
 * @brief : Проверяет високосный год или нет
 * @param date_ : дата
 * @return : true если год високосный; false иначе
*/
bool is_leap(Date* date_);