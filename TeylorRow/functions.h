#include<math.h>

/**
 * @brief : Факториал числа
 * @param number_ : Число, факториал которого считаем
 * @return : Факториал числа
*/
unsigned long long factorial(unsigned long long number_);

/**
 * @brief : Разложение экспоненциальной функции в ряд Тэйлора с учётом заданной точности eps
 * @param exp_ : Экспонента
 * @param x_ : Параметр X
 * @return : Сумма эл-ов получившегося ряда Тэйлора
*/
double exp_to_teylor(const double exp_, double x_);