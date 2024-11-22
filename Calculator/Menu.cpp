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

Menu::Menu()
{
	options_amount = 3;

	obj_ptr = new Function * [options_amount];
}

Menu::Menu(Function** arr_, size_t options_amount_)
{
	options_amount = options_amount_;

	obj_ptr = arr_;
}

Function* Menu::SelectedFunction()
{
	int option = 0;

	cout << endl << "Which Function Do You Want To Use?" << endl << endl;

	for (size_t i = 0; i < options_amount - 1; ++i)
		cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

	cout << options_amount << ". Exit" << endl << "> ";

	return obj_ptr[SelectItem(options_amount) - 1];
}
