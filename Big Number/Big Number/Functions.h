#include"BigNumber.h"
#include<stdio.h>

/**
 * @brief Считает длину строки
 * @param str_ Строка
 * @return Длина строки
*/
unsigned MyStr_len(char* str_);

/**
 * @brief Создаёт пользовательское большое число
 * @param big_number_ Большое число
 * @param res_ Структура, в которую записывается информация о числе
 * @return Указатель на структуру, содержащую большое число
*/
BG* BG_create(char* big_number_, BG* res_);

/**
 * @brief Выводит большо число на экран
 * @param big_number_ Структура, содержащая информацию о числе
*/
void BG_out(BG* big_number_);

void BG_delete(BG* big_number_);

BG* BG_sum(BG* bg_first_, BG* bg_second_);

BG*  BG_diff(BG* bg_bigger_, BG* bg_smaller_);

BG* BG_devide(BG* bg_bigger_, BG* bg_smaller_);

BG* BG_mult(BG* bg_first_, BG* bg_second_);