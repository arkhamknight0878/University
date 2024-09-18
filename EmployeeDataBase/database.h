#pragma once

#include "employee_class.h"

class DataBase
{
private:
	Employee* base;
	size_t size;
	size_t current_amount;

	int Base_Expansion();
public:
	// Constructor
	DataBase()
	{
		size = 100;
		current_amount = 0;
		base = new Employee[size];
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

	int Element_Delete();

	int Element_Change();
};