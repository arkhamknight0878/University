#include "database.h"

int DataBase::Base_Expansion()
{
	Employee* tmp = new Employee[size += 50];
	if (!tmp)
		return -1;

	tmp = base;
	delete[] base;

	return 0;
}

int DataBase::Base_Create_F(const char* file_name_)
{
	if (!file_name_)
		return -1;

	FILE* fp;
	fopen_s(&fp, file_name_, "r");
	if (!fp)
		return -2;

	size_t index = 0;

	char name[31];
	char initials[5];
	char start_date[11];
	size_t date_birth;
	float salary;

	while (fscanf_s(fp, "%s %s %Iu %s %f", name, 31, initials, 5, &date_birth, start_date, 11, &salary) == 5)
	{
		strcat(name, " ");
		strcat(name, initials);

		base[index].Set_Name(name);
		base[index].Set_Start_Date(start_date);
		base[index].Set_Birth_Year(date_birth);
		base[index].Set_Salary(salary);

		++index;
		if (index > size)
		{
			int expanton_output = 0;
			expanton_output = Base_Expansion();

			if (expanton_output == -1)
				return -4;
		}
	}

	current_amount += index;
	
	return 0;
}

void DataBase::Base_Output()
{
	for (size_t i = 0; i < current_amount; ++i)
	{
		printf("%2Iu. ", i + 1);
		base[i].Info_Out();
	}
}

int DataBase::Element_Add()
{

	if (current_amount + 1 > size)
	{
		int expanton_output = 0;
		expanton_output = Base_Expansion();

		if (expanton_output == -1)
			return -5;
	}

	base[current_amount].Info_Input();
	current_amount += 1;

	return 0;
}