#pragma once

#include "Function.h"
#include "Action.h"

class Menu
{
private:
	Function** func_ptrs;
	Action** act_ptrs;

	int GetIndex(size_t options_amount_);
public:
	Menu() { func_ptrs = nullptr; act_ptrs = nullptr; }

	Menu(Function** func_arr_, Action** act_arr_) { func_ptrs = func_arr_; act_ptrs = act_arr_; }

	Function* SelectedFunction();

	Action* SelectedAction();
};