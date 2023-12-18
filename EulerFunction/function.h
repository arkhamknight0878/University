#include<stdbool.h>
#include<math.h>

/**
 * @brief : ѕровер€ет два числа на взаимную простоту
 * @param number_ : „исло, которое провер€ем
 * @param range_ : „исло, с колтым провер€ем
 * @return : true, если два числа взаимно просты, false иначе
*/
bool is_relatively_prime(unsigned long long number_, unsigned long long range_);

/**
 * @brief : ѕодсчитывает кол-во взаимно простых чисел от 1 до заданного числа
 * @param range_ : ћаксимальное число в промежутке
 * @return :  ол-во взаимно простых чисел от 1 до заданного числа
*/
unsigned int euler_function(unsigned long long range_);
