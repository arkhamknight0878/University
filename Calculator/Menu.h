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
	Menu();

	Menu(Function** arr_, size_t options_amount_);

	Function* SelectedFunction();

};