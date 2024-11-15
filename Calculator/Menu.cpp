#include "Menu.h"

int Menu::SelectItem(size_t options_amount_)
{
	int option = 0;
	cin >> option;

	while (option <= 0 && option > options_amount_)
	{
		cout << "!!!Incorrect Input !!! Try Again" << endl << "> ";
		cin >> option;
	}

	return option;
}
