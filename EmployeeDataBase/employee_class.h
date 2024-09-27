#pragma once
#pragma warning (disable: 4996)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Employee
{
private:
	char* name;				// Employee Name
	size_t birth_year;		// Employee Year of Birth
	char start_date[11];	// Date of First Day on Job
	float salary;			// Employee Salary
public:
	// Constructor
	Employee()
	{
		name = new char[31];
		birth_year = 0;
		start_date[0] = '\0';
		salary = 0.0;
	}
	Employee(Employee& src_)
	{
		name = new char[strlen(src_.name) + 1];
		strcpy(name, src_.name);
		birth_year = src_.birth_year;
		salary = src_.salary;
		strcpy(start_date, src_.start_date);
	}
	// Destructor
	~Employee()
	{
		if (name != nullptr)
			delete[] name;
	}

	const Employee& operator = (const Employee& other_)
	{
		if (&other_ == this)
			return *this;

		if (name)
			delete[] name;

		if (other_.name)
		{
			name = new char[strlen(other_.name) + 1];
			strcpy(name, other_.name);
		}
		else
			name = nullptr;

		if (other_.start_date)
			strcpy(start_date, other_.start_date);

		birth_year = other_.birth_year;
		salary = other_.salary;
	}

	// Fields Set Functions
	void Set_Name(const char* name_);

	void Set_Birth_Year(const size_t birth_year_);

	void Set_Start_Date(const char* start_date_);

	void Set_Salary(const float salary_);

	// Fields Get Functions
	char* Get_Name();

	size_t Get_Birth_Year();

	char* Get_Start_Date();

	float Get_Salary();

	// Info Input/Output Functions
	void Info_Out();

	void Info_Input();
};

int Employee_Create_F(const char* file_name_, Employee*& employee_, size_t& index_);

int Get_Year(char* date_);

float First_Request(Employee* employee_list_, size_t list_size_, char** filtered_list_, size_t& filtered_list_size_, size_t current_year_);