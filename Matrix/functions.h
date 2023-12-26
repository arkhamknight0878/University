/**
 * @brief : Заполняет матрицу рандомными зниачениями
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
*/
void matr_rand(double** matrix_, unsigned size_);

/**
 * @brief : Выводит матрицу на экран
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
*/
void matr_print(double** matrix_, unsigned size_);

/**
 * @brief : Берёт минор матрицы
 * @param matrix_ : Массив под матрицу
 * @param minor_ : Массив под минор матрицы
 * @param size_ : Размер массва под матрицу
 * @param del_row : Убираемый ряд
 * @param del_col : Убтраемы столбец
*/
void matr_minor(double** matrix_, double** minor_, unsigned size_, unsigned del_row, unsigned del_col);

/**
 * @brief : Ищет определитель матрицы
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
 * @return : Определитель матрицы
*/
double matr_determ(double** matrix_, unsigned size_);

/**
 * @brief : Ищет союзную матрицу по исходной
 * @param matrix_ : Массив под исходную матрицу
 * @param reverse_ : Массив под союзную матрицу
 * @param size_ : Размер массивов
*/
void matr_reverse(double** matrix_, double** reverse_, unsigned size_);

/**
 * @brief : Транспонирует матрицу
 * @param matrix_ : Массив под матрицу
 * @param transpon_ : Массив под транспонированную матрицу
 * @param size_ : Размер массивов
*/
void matr_transpon(double** matrix_, double** transpon_, unsigned size_);