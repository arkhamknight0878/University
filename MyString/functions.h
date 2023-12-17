/**
 * @brief : �������� ������
 * @param StrDest_ : ������ ����������
 * @param StrSrc_ : �������� ������
 * @return : ��������� ������ ����������
*/
char* my_strcpy(char* StrDest_, const char* StrSrc_);

/**
 * @brief : ������������ ���������� �������� � ������
 * @param StrSrc_ : ������, � ������ �������
 * @return : ���������� ��������
*/
unsigned int my_strlen(const char* StrSrc_);

/**
 * @brief : ��������� �����
 * @param StrDest_ : ������ ����������
 * @param StrSrc_ : ��������� �����
 * @return : ����������� ������ ����������
*/
char* my_strcat(char* StrDest_, const char* StrSrc_);

/**
 * @brief : ���������� ��� ������
 * @param Str1_ : ������, ������� ����������
 * @param Str2_ : ������, � ������� ����������
 * @return : 1 ���� Str1 > Str2, -1 ���� Str1 > Str2 , 0 ���� Str1  = Str2
*/
int my_strcmp(const char* Str1_, const char* Str2_);

/**
 * @brief : 
 * @param Str_ : ������ ��� ������
 * @param StrSearch_ : ������� ������
 * @return : 
*/
char* my_strstr(const char* Str_, const char* StrSearch_);
