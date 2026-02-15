#include "functions.hpp"

int main()
{
    int matrix_size = 1000;

    float** matrix_a = create_randomized_matrix(matrix_size);
    float** matrix_b = create_randomized_matrix(matrix_size);

    auto start = std::chrono::steady_clock::now();

    float** mult_result = mult_matrixes(matrix_a, matrix_b, matrix_size);

    auto finish = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

    std::cout << "Basic multiplication completed for:\n" << elapsed_ns << std::endl;

    auto start_th = std::chrono::steady_clock::now();

    multy_threading(matrix_size, matrix_a, matrix_b, mult_result);

    auto finish_th = std::chrono::steady_clock::now();
    auto elapsed_ns_th = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_th - start_th);

    std::cout << "Multythreaded multiplication complited for:\n" << elapsed_ns_th << std::endl;

    for (int i = 0; i < matrix_size; ++i)
    {
        delete[] matrix_a[i];
        delete[] matrix_b[i];
        delete[] mult_result[i];
    }

    delete[] matrix_a;
    delete[] matrix_b;
    delete[] mult_result;

    return 0;
}