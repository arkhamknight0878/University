#pragma once

#include "Function.h"
#include "Line.h"
#include "Exponent.h"
#include "Polynomial.h"
#include "Cube.h"

class Menu
{
private:
	Function** obj_ptr;
	int size;

	int GetFunctionIndex(size_t options_amount_);
public:
	Menu() { obj_ptr = nullptr; size = 0; }

	Menu(Function** func_arr_, int size_);

	Function* SelectedFunction();
};