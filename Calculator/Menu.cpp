#include "Menu.h"

int Menu::GetFunctionIndex(size_t options_amount_)
{
	int option = 0;
	cin >> option;

	while (option <= 0 || option > options_amount_)
	{
		cout << "!!!Incorrect Input !!! Try Again" << endl << "> ";
		cin >> option;
	}

	return option;
}

Function* Menu::SelectedFunction()
{
	int option = 0;
	int arr_size = sizeof(**obj_ptr) / sizeof(Function*);

	cout << "Which Function Do You Want To Use?" << endl;

	for (size_t i = 0; i < arr_size; ++i)
		cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

	cout << arr_size + 1 << ". Exit" << endl << "> ";

	return obj_ptr[GetFunctionIndex(arr_size + 1) - 1];
}