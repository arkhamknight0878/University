#include "Matrix.h"
#include "SquareMatrix.h"
#include "Menu.h"
#include "MatrixException.h"

#include <iostream>

using namespace std;

int main()
{
	SquareMatrix matrix_a;
	SquareMatrix matrix_b;

	ifstream file("Matrix.txt");

	file >> matrix_a;
	cout << matrix_a;


	/*SquareMatrix result;
	double determ = 0;

	int option = 0;


	while (option != 9)
	{
		system("cls");

		cout << "What Do You Want To Do?" << endl;

		ArithmeticOperationsMenu();
		option = OptionChoosing(8);

		if (option == 8)
			break;

		if (option != 5 && option != 6 && option != 7)
		{
			cin >> matrix_a >> matrix_b;
			cout << endl << "Created Matrices:" << endl << matrix_a << endl << matrix_b << endl;
		}
		else
		{
			cin >> matrix_a;
			cout << endl << "Created Matrix:" << endl << matrix_a << endl;
		}

		try
		{
			switch (option)
			{
			case 1:
				result = matrix_a + matrix_b;

				cout << endl << "Result:" << endl << result << endl;
				break;
			case 2:
				result = matrix_a - matrix_b;

				cout << endl << "Result:" << endl << result << endl;
				break;
			case 3:
				result = matrix_a * matrix_b;

				cout << endl << "Result:" << endl << result << endl;
				break;
			case 4:
				determ = matrix_a.Determinant();

				cout << endl << "Determinant:" << determ << endl;
				break;
			case 5:
				result = matrix_a.Reverse();

				cout << endl << "Reversed Matrix:" << endl << result << endl;
				break;
			case 6:
				result = matrix_a.Transpon();

				cout << endl << "Reversed Matrix:" << endl << result << endl;
				break;
			case 7:
				cout << endl << "Matrix A ";

				(matrix_a == matrix_b) ? cout << "Equal" : cout << "Mot Equal";

				cout << " To Matrix B" << endl;
			}
		}
		catch (MatrixException& exep)
		{
			exep.PrintErr();
		}

		if (option != 8)
			system("pause");
	}*/

	return 0;
}