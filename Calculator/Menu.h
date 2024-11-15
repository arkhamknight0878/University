#pragma once

#include "Function.h"
#include "Line.h"
#include "Exponent.h"

class Menu
{
private:
	Function** obj_ptr;
	size_t options_amount;

	int SelectItem(size_t options_amount_);
public:
	Menu()
	{
		options_amount = 3;

		Line line_function;
		Exponent exponent_function;

		obj_ptr = new (Function*)[3];
	}

	Function* SelectedFunction()
	{
		int option = 0;

		cout << "Which Function Do You Want To Use?" << endl << endl;

		for (size_t i = 0; i < options_amount - 1; ++i)
			cout << i + 1 << ". " << obj_ptr[i]->GetName() << endl;

		cout << options_amount << ". Exit" << endl << "> ";

		return obj_ptr[SelectItem(options_amount) - 1];
	}
};