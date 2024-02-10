#include"date.h"
#include<stdio.h>
#include<stdbool.h>

/**
 * @brief Считает разницу во времени между двумя датами
 * @param date_1 Поздняя дата
 * @param date_2 Ранняя дата
 * @param res_ Итоговая структура
 * @return 
*/
Date time_difference(Date* date_1, Date* date_2, Date* res_);

/**
 * @brief Определяет високосный это год или нет
 * @param year_ Год, который проверяем
 * @return true, если год високосный, false иначе
*/
bool is_leap_year(Date* date_);