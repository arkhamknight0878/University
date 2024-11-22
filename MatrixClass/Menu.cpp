#include "Menu.h"

void ArithmeticOperationsMenu()
{
	cout << "1. A + B" << endl;
	cout << "2. A - B" << endl;
	cout << "3. A * B" << endl;
	cout << "4. A / B" << endl;
	cout << "5. Determinant" << endl;
	cout << "6. Reverse Matrix" << endl;
	cout << "7. Tranpon Matrix" << endl;
	cout << "8. A == B" << endl;
	cout << "9. FIN" << endl;
}

int OptionChoosing(size_t options_amount_)
{
	cout << "> ";

	int option = 0;
	cin >> option;

	while (option <= 0 || option > options_amount_)
	{
		cout << "!!! Incorrect Input !!! Please, Try Again" << endl;
		cout << "> ";
		cin >> option;
	}

	return option;
}