#include "functions.h"

#include <stdio.h>

int main()
{
	size_t size = 0;
	int** matrix = Matrix_Create_F("matrix.txt", &size);
	if (matrix == NULL)
		return -1;

	printf("Created Matrix:\n");
	Matrix_Print(matrix, size);

	bool is_magic = Is_Magic_Square(matrix, size);
	(is_magic == true) ? printf("Matrix Is Magic Square") : printf("Matrix Is Not Magic Square");

	return 0;
}