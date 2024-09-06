#pragma once

#include <stdbool.h>

/**
 * @brief : Prints Matrics
 * @param matrix_ : Matrix
 * @param size_ : Matrix Size
 */
void Matrix_Print(int** matrix_, size_t size_);

/**
 * @brief : Creates Matrix And Chenges Size Value Using Data In The File
 * @param file_name_ : Name Of The File
 * @param size_ : Matrix Size; Can Be Anything
 * @return : Pointer On Matrix
 */
int** Matrix_Create_F(const char* file_name_, size_t* size_);

/**
 * @brief : Checks If Matrix Is Magic Square
 * @param matrix_ : Matrix
 * @param size_ : Matrix Size
 * @return : true If Matrix Is Magic Square, false Otherwise
 */
bool Is_Magic_Square(int** matrix_, int size_);