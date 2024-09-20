#pragma once

#include "employee_class.h"

class DataBase
{
private:
	Employee* base;
	size_t capasity;
	size_t current_amount;

	int Base_Expansion();

	void Employees_to_Edit(const char* name_);
public:
	// Constructor
	DataBase()
	{
		capasity = 100;
		current_amount = 0;
		base = new Employee[capasity];
	}
	// Destructor
	~DataBase()
	{
		delete[] base;
	}

	// Class Methods
	int Base_Create_F(const char* file_name_);

	void Base_Output();

	int Element_Add();

	void Element_Delete();

	int Element_Change();
};

void Main_Menu_Print();

void Edit_Base_Menu_Print();

void Edit_Element_Menu_Print();

int Option_Choosing(size_t options_amount_);