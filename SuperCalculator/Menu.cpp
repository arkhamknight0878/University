#include "Menu.h"

int Menu::GetIndex(size_t options_amount_)
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
	int arr_size = 4;


	cout << "Which Function Do You Want To Use?" << endl;

	for (int i = 0; i < arr_size - 1; ++i)
		cout << i + 1 << ". " << func_ptrs[i]->GetName() << endl;

	cout << arr_size << ". Exit" << endl << "> ";

	return (func_ptrs[GetIndex(arr_size) - 1]);
}

Action* Menu::SelectedAction()
{
	int option = 0;
	int arr_size = 2;

	cout << endl << "Which Action Do You Want To Use?" << endl;

	for (int i = 0; i < arr_size; ++i)
		cout << i + 1 << ". " << act_ptrs[i]->GetName() << endl;

	cout << "> ";

	return (act_ptrs[GetIndex(arr_size) - 1]);
}
