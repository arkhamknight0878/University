#include "functions.hpp"

float** create_randomized_matrix(int matrix_size_)
{
    srand(time(0));

    float** new_matrix = new float* [matrix_size_];
    for (int i = 0; i < matrix_size_; ++i)
    {
        new_matrix[i] = new float[matrix_size_];

        for (int j = 0; j < matrix_size_; ++j)
            new_matrix[i][j] = rand();
    }

    return new_matrix;
}

void display_matrix(float** matrix_, int matrix_size_)
{
    for (int i = 0; i < matrix_size_; ++i)
    {
        for (int j = 0; j < matrix_size_; ++j)
            std::cout << matrix_[i][j] << ' ';

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

float** mult_matrixes(float** matrix_a_, float** matrix_b_, int matrix_size_)
{
    float** new_matrix = new float* [matrix_size_];
    for (int i = 0; i < matrix_size_; ++i)
        new_matrix[i] = new float[matrix_size_];

    for (int i = 0; i < matrix_size_; ++i)
    {
        for (int j = 0; j < matrix_size_; ++j)
        {
            float cell_ij = matrix_a_[i][j];

            for (int k = 0; k < matrix_size_; ++k)
                new_matrix[i][k] += cell_ij * matrix_b_[j][k];
        }
    }

    return new_matrix;
}

void matrix_worker(int start_row_, int end_row_, int matrix_size_, float** matrix_a_row_, float** matrix_b_row_, float** matrix_c_row_)
{
    for (int i = start_row_; i < end_row_; ++i)
    {
        for (int j = 0; j < matrix_size_; ++j)
        {
            float cell_ij = matrix_a_row_[i][j];

            for (int k = 0; k < matrix_size_; ++k)
                matrix_c_row_[i][k] += cell_ij * matrix_b_row_[j][k];
        }
    }
}

void multy_threading(int matrix_size_, float** matrix_a_row_, float** matrix_b_row_, float** matrix_c_row_)
{
    int threads_number = std::thread::hardware_concurrency();
    if (!threads_number)
        threads_number = 2;

    std::vector<std::thread> threads;
    int rows_per_thread = matrix_size_ / threads_number;

    for (int i = 0; i < threads_number; ++i)
    {
        int start_col = i * rows_per_thread;
        int end_col = (i == threads_number - 1) ? matrix_size_ : (i + 1) * rows_per_thread;

        threads.emplace_back(matrix_worker, start_col, end_col, matrix_size_, matrix_a_row_, matrix_b_row_, matrix_c_row_);
    }

    for (auto& it : threads)
        it.join();
}