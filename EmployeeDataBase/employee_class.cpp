#include "employee_class.h"

void Employee::Set_Name(const char* name_)
{
	strcpy(name, name_);
}

void Employee::Set_Birth_Year(const size_t birth_year_)
{
	birth_year = birth_year_;
}

void Employee::Set_Start_Date(const char* start_date_)
{
	strcpy(start_date, start_date_);
}

void Employee::Set_Salary(const float salary_)
{
	salary = salary_;
}

char* Employee::Get_Name()
{
	return name;
}

size_t Employee::Get_Birth_Year()
{
	return birth_year;
}

char* Employee::Get_Start_Date()
{
	return start_date;
}

float Employee::Get_Salary()
{
	return salary;
}

void Employee::Info_Out()
{
	printf(" %-16s | %10Iu | %18s | %16.2f |\n", name, birth_year, start_date, salary);
}

void Employee::Info_Input()
{
	char initials[5];

	printf("\nEnter Employee Information:\nExample: Last_Name Initials Birth_Year Start_Date Salary\n> ");
	scanf_s("%s %s %Iu %s %f", name, 31, initials, 5, &birth_year, start_date, 11, &salary);

	strcat(name, " ");
	strcat(name, initials);
}

int Employee_Create_F(const char* file_name_, Employee*& employee_, size_t& index_)
{
	if (!file_name_)
		return -1;

	employee_ = new Employee[100];
	if (!employee_)
		return -2;

	FILE* fp;
	fopen_s(&fp, file_name_, "r");
	if (!fp)
		return -3;

	char name[31];
	char initials[5];
	char start_date[11];
	size_t date_birth;
	float salary;

	while (fscanf_s(fp, "%s %s %Iu %s %f", name, 31, initials, 5, &date_birth, start_date, 11, &salary) == 5)
	{
		strcat(name, " ");
		strcat(name, initials);

		employee_[index_].Set_Name(name);
		employee_[index_].Set_Start_Date(start_date);
		employee_[index_].Set_Birth_Year(date_birth);
		employee_[index_].Set_Salary(salary);

		++index_;
	}

	return 0;
}

int Get_Year(char* date_)
{
	if (!date_)
		return -1;

	int year = 1;

	for (int i = 6; i < 10; ++i)
		year = (year * 10) + (date_[i] - '\0' * 1000);

	return year;
}

float First_Request(Employee* employee_list_, size_t list_size_, char** filtered_list_, size_t& filtered_list_size_, size_t current_year_)
{
	if (!employee_list_ || list_size_ == 0)
		return -1;

	float average_salary = 0;
	size_t job_start_year = 0;
	char date[11];

	for (size_t i = 0; i < list_size_; ++i)
	{
		strcpy(date, employee_list_[i].Get_Start_Date());
		job_start_year = Get_Year(date);

		if (current_year_ - job_start_year > 25)
		{
			strcpy(filtered_list_[filtered_list_size_], employee_list_[i].Get_Name());
			++filtered_list_size_;

			average_salary += employee_list_[i].Get_Salary();
		}
	}

	if (filtered_list_size_ != 0)
		average_salary /= filtered_list_size_;

	return average_salary;
}