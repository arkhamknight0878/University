#pragma once

#include "Function.h"
#include "Line.h"
#include "Exponent.h"
#include "Polynomial.h"

class Menu
{
private:
	Function** obj_ptr;

	int GetFunctionIndex(size_t options_amount_);
public:
	Menu() { obj_ptr = nullptr; }

	Menu(Function** func_arr_) { obj_ptr = func_arr_; }

	Function* SelectedFunction();
};