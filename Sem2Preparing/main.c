#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file_pointer;
	fopen_s(&file_pointer, "file.txt", "r");
	if (!file_pointer)
		return -1;

	size_t size = 0;
	size_t index = 0;

	fscanf_s(file_pointer, "%Iu", &size);
	fclose(file_pointer);
	
	printf("Please, Enter Element Index\n> ");
	scanf_s("%Iu", &index);
	while (index > size)
	{
		printf("It's Impossible, Mate...\nSo Quit Fucking Around, Get Your Shit Together And Try Again\n> ");
		scanf_s("%Iu", &index);
	}

	int** matrix = Matrix_Create_File("file.txt");

	First_Task(matrix, size, index);

	printf("\n");
	Matrix_Print(matrix, size);

	return 0;
}