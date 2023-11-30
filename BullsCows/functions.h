#include <stdbool.h>

/**
 * @brief : Проверяет number_ на условия задачи
 * @param number_ : Проверяеме число
 * @return : true если не удовлетворяет условиям, false иначе
*/
bool Is_Idiot(const unsigned int number_);

/**
 * @brief : Подсчитывает число быков
 * @param startnumber_ : Начальное число
 * @param guessnuber_ : Угадываемое число
 * @return : Число быков
*/
unsigned int Bulls(unsigned int startnumber_, unsigned int guessnumber_);

/**
 * @brief : Подсчитывает число коров
 * @param startnumber_ : Начальное число
 * @param guessnuber_ : Угдываемое число
 * @return : Число коров
*/
unsigned int Cows(unsigned int startnumber_, unsigned int guessnumber_);
