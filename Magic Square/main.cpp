#include "functions.h"

#include <iostream>

using namespace std;

int main()
{
	int function_out_code;
	bool is_magic_square;

	int** matrix = nullptr;
	size_t size = 0;

	function_out_code = Matrix_Create_F("matrix.txt", matrix, size);

	switch (function_out_code)
	{
	case -1:
		cout << "File Was Not Found" << endl;
		break;
	case -2:
		cout << "File Was Not Opened" << endl;
		break;
	case -3:
		cout << "Memmory Alocation Error" << endl;
		break;
	case 0:
		cout << "Matrix Size: " << size << " X " << size << endl;
		cout << "Generated Matrix: " << endl;

		Matrix_Print(matrix, size);

		is_magic_square = Is_Magic_Square(matrix, size);
		cout << "Matrix Is ";
		(is_magic_square == true) ? printf("Magic Square\n") : printf("Not Magic Square\n");
	}

	return 0;
}