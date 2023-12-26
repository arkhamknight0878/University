/**
 * @brief : ��������� ������� ���������� �����������
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
*/
void matr_rand(double** matrix_, unsigned size_);

/**
 * @brief : ������� ������� �� �����
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
*/
void matr_print(double** matrix_, unsigned size_);

/**
 * @brief : ���� ����� �������
 * @param matrix_ : ������ ��� �������
 * @param minor_ : ������ ��� ����� �������
 * @param size_ : ������ ������ ��� �������
 * @param del_row : ��������� ���
 * @param del_col : �������� �������
*/
void matr_minor(double** matrix_, double** minor_, unsigned size_, unsigned del_row, unsigned del_col);

/**
 * @brief : ���� ������������ �������
 * @param matrix_ : ������ ��� �������
 * @param size_ : ������ �������
 * @return : ������������ �������
*/
double matr_determ(double** matrix_, unsigned size_);

/**
 * @brief : ���� ������� ������� �� ��������
 * @param matrix_ : ������ ��� �������� �������
 * @param reverse_ : ������ ��� ������� �������
 * @param size_ : ������ ��������
*/
void matr_reverse(double** matrix_, double** reverse_, unsigned size_);

/**
 * @brief : ������������� �������
 * @param matrix_ : ������ ��� �������
 * @param transpon_ : ������ ��� ����������������� �������
 * @param size_ : ������ ��������
*/
void matr_transpon(double** matrix_, double** transpon_, unsigned size_);