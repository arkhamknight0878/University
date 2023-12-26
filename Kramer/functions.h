/**
 * @brief : Заполняет матрицу пользовательскими значениями
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
*/
void matr_custom(double** matrix_, unsigned size_);

/**
 * @brief : Выводит матрицу
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
*/
void matr_print(double** matrix_, unsigned size_);

/**
 * @brief : Присваивает свободным членам системы пользовательские значения
 * @param matrix_ : Массив под свободные члены
 * @param size_ : Размер массива
*/
void matr_term_custom(double* matrix_, unsigned size_);

/**
 * @brief : Выводит свободные члены системы
 * @param matrix_ : Массив под свободные члены
 * @param size_ : Размер массива
*/
void matr_term_print(double* matrix_, unsigned size_);

/**
 * @brief : Берёт минор матрицы
 * @param matrix_ : Массив под матрицу
 * @param minor_matrix_ : Массив под минор матрицы
 * @param size_ : Размер массива
 * @param row_del : Удаляемая строка
 * @param col_del : Удаляемый столбец
*/
void matr_minor(double** matrix_, double** minor_matrix_, unsigned size_, unsigned row_del, unsigned col_del);

/**
 * @brief : Считает определитель матрицы
 * @param matrix_ : Массив под матрицу
 * @param size_ : Размер массива
 * @return : Определитель матрицы
*/
double matr_determ(double** matrix_, unsigned size_);

/**
 * @brief : Заменяет один столбец матрицы на свободные члены системы
 * @param matrix : Массив под матрицу
 * @param matrix_term : Массив под свободныые члены
 * @param size_ : Размеры массивов
 * @param replace_col_ : Номер заменяемого столбца
*/
void term_replacement(double** matrix, double* matrix_term, unsigned size_, unsigned replace_col_);

/**
 * @brief : Копирует матрицу
 * @param matrix_ : Массив под матрицу
 * @param matrix_cpy_ : Массив под скопированную матрицу
 * @param size_ : Размер массивов
*/
void matr_cpy(double** matrix_, double** matrix_cpy_, unsigned size_);

/**
 * @brief : Ищет общее решение системы и выводит на экран
 * @param A_matrix_determ : Определитель матрицы системы
 * @param matrix_ : Массив под матрицу системы
 * @param matrix_term : Массив под свободные члены системы
 * @param size_ : Размер массивов
*/
void matr_kramer(double A_matrix_determ, double** matrix_, double* matrix_term, unsigned size_);