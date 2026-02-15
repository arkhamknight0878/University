#include <iostream>
#include <thread>
#include <chrono>
#include <random>

float** create_randomized_matrix(int matrix_size_);

void display_matrix(float** matrix_, int matrix_size_);

float** mult_matrixes(float** matrix_a_, float** matrix_b_, int matrix_size_);

void matrix_worker(int start_row_, int end_row_, int matrix_size_, float** matrix_a_row_, float** matrix_b_row_, float** matrix_c_row_);

void multy_threading(int matrix_size_, float** matrix_a_row_, float** matrix_b_row_, float** matrix_c_row_);