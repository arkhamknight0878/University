#include<string.h>

/**
 * @brief : Считает количество символов в строке
 * @param StrSrc_ : Строка, символы которой считаем
 * @return : Количество символов в сторке
*/
unsigned int my_strlen(const char* StrSrc_);

/**
 * @brief : Отзеркаливает строку и заносит её в новую
 * @param StrReult_ : Изменяемая строка
 * @param Str_ : Исходная строка
 * @return : Новая строка с зеркальным отображением исходной
*/
char* str_mirror(char* StrReult_, const char* Str_);