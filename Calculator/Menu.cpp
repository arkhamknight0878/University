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

Menu::Menu(Function** func_arr_, int size_)
{
	size = size_ + 1;

	obj_ptr = new Function * [size];
	for (size_t i = 0; i < size - 1; ++i)
		obj_ptr[i] = func_arr_[i];

	obj_ptr[size - 1] = nullptr;
}

Function* Menu::SelectedFunction()
{
	int option = 0;

	cout << "Which Function Do You Want To Use?" << endl;

	for (size_t i = 0; i < size - 1; ++i)
		cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

	cout << size << ". Exit" << endl << "> ";

	return obj_ptr[GetFunctionIndex(size) - 1];
}