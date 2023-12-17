/**
 * @brief : Копирует строку
 * @param StrDest_ : Строка назначения
 * @param StrSrc_ : Исходная строка
 * @return : Изменённая строка назначения
*/
char* my_strcpy(char* StrDest_, const char* StrSrc_);

/**
 * @brief : Подсчитывает количество символов в строке
 * @param StrSrc_ : Строка, в кторой считаем
 * @return : Количество символов
*/
unsigned int my_strlen(const char* StrSrc_);

/**
 * @brief : Дополняет сроку
 * @param StrDest_ : Строка назначения
 * @param StrSrc_ : Начальная срока
 * @return : Дополненная строка назначения
*/
char* my_strcat(char* StrDest_, const char* StrSrc_);

/**
 * @brief : Сравнивает две строки
 * @param Str1_ : Строка, которую сравниваем
 * @param Str2_ : Строка, с которой сравниваем
 * @return : 1 если Str1 > Str2, -1 если Str1 > Str2 , 0 если Str1  = Str2
*/
int my_strcmp(const char* Str1_, const char* Str2_);

/**
 * @brief : 
 * @param Str_ : Строка для поиска
 * @param StrSearch_ : Искомая строка
 * @return : 
*/
char* my_strstr(const char* Str_, const char* StrSearch_);
