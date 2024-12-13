#include "Menu.h"

void ArithmeticOperationsMenu()
{
	cout << "1. A + B" << endl;
	cout << "2. A - B" << endl;
	cout << "3. A * B" << endl;
	cout << "4. Determinant" << endl;
	cout << "5. Reverse Matrix" << endl;
	cout << "6. Tranpon Matrix" << endl;
	cout << "7. A == B" << endl;
	cout << "8. FIN" << endl;
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

// Дано натуральное число n, выбросить из записи этого числа цифры 3 и 7, остальные оставить  в том же порядке
// Пример: 3, 171, 507, 377 -> 11, 50