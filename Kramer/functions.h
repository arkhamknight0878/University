void matr_custom(double** matrix_, unsigned size_);

void matr_print(double** matrix_, unsigned size_);

void matr_term_custom(double* matrix_, unsigned size_);

void matr_term_print(double* matrix_, unsigned size_);

void matr_minor(double** matrix_, double** minor_matrix_, unsigned size_, unsigned row_del, unsigned col_del);

double matr_determ(double** matrix_, unsigned size_);

void term_replacement(double** matrix, double* matrix_term, unsigned size_, unsigned replace_col_);

void matr_cpy(double** matrix_, double** matrix_cpy_, unsigned size_);

void matr_kramer(double A_matrix_determ, double** matrix_, double* matrix_term, unsigned size_);

/*printf("\nMinor(1,1) of A Matrix is:\n\n");
matr_minor(matrix, matrix_minor, size, 0, 0);
matr_print(matrix_minor, minor_size);*/

/*___TEST_of_MINOR___ */
//double** matrix_minor = calloc(minor_size, sizeof(double));
//for (unsigned i = 0; i < minor_size; i++)
//	matrix_minor[i] = calloc(minor_size, sizeof(double));

/*___TEST_of_Replacement___*/
//term_replacement(matrix, constant_term, size, 0);
//matr_print(matrix, size);