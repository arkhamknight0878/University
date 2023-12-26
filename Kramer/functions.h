/**
 * @brief : ��������� ������� ����������������� ����������
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
*/
void matr_custom(double** matrix_, unsigned size_);

/**
 * @brief : ������� �������
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
*/
void matr_print(double** matrix_, unsigned size_);

/**
 * @brief : ����������� ��������� ������ ������� ���������������� ��������
 * @param matrix_ : ������ ��� ��������� �����
 * @param size_ : ������ �������
*/
void matr_term_custom(double* matrix_, unsigned size_);

/**
 * @brief : ������� ��������� ����� �������
 * @param matrix_ : ������ ��� ��������� �����
 * @param size_ : ������ �������
*/
void matr_term_print(double* matrix_, unsigned size_);

/**
 * @brief : ���� ����� �������
 * @param matrix_ : ������ ��� �������
 * @param minor_matrix_ : ������ ��� ����� �������
 * @param size_ : ������ �������
 * @param row_del : ��������� ������
 * @param col_del : ��������� �������
*/
void matr_minor(double** matrix_, double** minor_matrix_, unsigned size_, unsigned row_del, unsigned col_del);

/**
 * @brief : ������� ������������ �������
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
 * @return : ������������ �������
*/
double matr_determ(double** matrix_, unsigned size_);

/**
 * @brief : �������� ���� ������� ������� �� ��������� ����� �������
 * @param matrix : ������ ��� �������
 * @param matrix_term : ������ ��� ���������� �����
 * @param size_ : ������� ��������
 * @param replace_col_ : ����� ����������� �������
*/
void term_replacement(double** matrix, double* matrix_term, unsigned size_, unsigned replace_col_);

/**
 * @brief : �������� �������
 * @param matrix_ : ������ ��� �������
 * @param matrix_cpy_ : ������ ��� ������������� �������
 * @param size_ : ������ ��������
*/
void matr_cpy(double** matrix_, double** matrix_cpy_, unsigned size_);

/**
 * @brief : ���� ����� ������� ������� � ������� �� �����
 * @param A_matrix_determ : ������������ ������� �������
 * @param matrix_ : ������ ��� ������� �������
 * @param matrix_term : ������ ��� ��������� ����� �������
 * @param size_ : ������ ��������
*/
void matr_kramer(double A_matrix_determ, double** matrix_, double* matrix_term, unsigned size_);