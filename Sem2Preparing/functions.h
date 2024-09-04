#pragma once

#include <stdlib.h>

void Matrix_Print(int** matrix_, size_t size_);

int** Matrix_Create_File(const char* file_name_);

void Swap(int* element1_, int* element2_);

void Selection_Sort(int* arr_, size_t size_);

void First_Task(int** matrix, size_t size_, size_t index_);