#include "database.h"

int DataBase::Base_Expansion()
{
	Employee* tmp = new Employee[capasity += 50];
	if (!tmp)
		return -1;

	for (size_t i = 0; i < current_amount; ++i)
		tmp[i] = base[i];

	base = tmp;

	return 0;
}

void DataBase::Employees_to_Delete(const char* name_)
{
	printf("\nFounded Employees:\n\n");

	printf("+----+------------------+------------+--------------------+------------------+\n");
	printf("| In |       Name       | Birth Year |     Start Date     |      Salary      |\n");
	printf("+----+------------------+------------+--------------------+------------------+\n");

	for (size_t i = 0; i < capasity; ++i)
	{
		if (strcmp(name_, base[i].Get_Name()) == 0)
		{
			printf("| %2Iu |", i + 1);
			base[i].Info_Out();
		}
	}

	printf("+----+------------------+------------+--------------------+------------------+\n");
}

int DataBase::Base_Create_F(const char* file_name_)
{
	if (!file_name_)
		return -1;

	FILE* fp;
	fopen_s(&fp, file_name_, "r");
	if (!fp)
		return -2;

	char name[31];
	char initials[5];
	char start_date[11];
	size_t date_birth;
	float salary;

	while (fscanf_s(fp, "%s %s %Iu %s %f", name, 31, initials, 5, &date_birth, start_date, 11, &salary) == 5)
	{
		strcat(name, " ");
		strcat(name, initials);

		base[current_amount].Set_Name(name);
		base[current_amount].Set_Start_Date(start_date);
		base[current_amount].Set_Birth_Year(date_birth);
		base[current_amount].Set_Salary(salary);

		++current_amount;
		if (current_amount >= capasity)
		{
			int expanton_output = 0;
			expanton_output = Base_Expansion();

			if (expanton_output == -1)
				return -4;
		}
	}
	
	return 0;
}

void DataBase::Base_Output()
{
	printf("+----+------------------+------------+--------------------+------------------+\n");
	printf("| No |       Name       | Birth Year |     Start Date     |      Salary      |\n");
	printf("+----+------------------+------------+--------------------+------------------+\n");

	for (size_t i = 0; i < current_amount; ++i)
	{
		printf("| %2Iu |", i + 1);
		base[i].Info_Out();
	}

	printf("+----+------------------+------------+--------------------+------------------+\n");
}

int DataBase::Element_Add()
{
	if (current_amount >= capasity)
	{
		int expanton_output = 0;
		expanton_output = Base_Expansion();

		if (expanton_output == -1)
			return -4;
	}

	base[current_amount].Info_Input();
	current_amount += 1;

	return 0;
}

void DataBase::Element_Delete()
{
	char name[31];
	char initials[5];
	size_t index = 0;

	printf("\nEnter The Name of Employee You Want To Delete:\n> ");
	scanf_s("%s %s", name, 31, initials, 5);

	strcat(name, " ");
	strcat(name, initials);

	Employees_to_Delete(name);

	printf("\nWhich One Do You Want to Delete? (Enter Index)\n> ");
	scanf_s("%Iu", &index);

	for (size_t j = index - 1; j < current_amount; ++j)
		base[j] = base[j + 1];

	--current_amount;
}

int DataBase::Element_Change()
{
	char name[31];
	char initials[5];

	printf("Enter The Name of Employee You Want To Delete:\n> ");
	scanf_s("%s %s", name, 31, initials, 5);

	strcat(name, " ");
	strcat(name, initials);

	for (size_t i = 0; i < capasity; ++i)
	{
		if (strcmp(name, base[i].Get_Name()) == 0)
		{
			// Menu Print
			// Option Choosing

			// Changing Fields
		}
	}

	return 0;
}

void Main_Menu_Print()
{
	system("cls");
	printf("What Do You Want to Do?\n");
	printf("1. Create Employee Data Base From File\n");
	printf("2. Print Out Data Base\n");
	printf("3. Edit Data Base\n");
	printf("4. Exit\n");
	printf("> ");
}

void Edit_Menu_Print()
{
	printf("\nWhat Exactly Do You Want to Change?\n");
	printf("1. Add New Element\n");
	printf("2. Delete Element\n");
	printf("3. Change Element\n");
	printf("4. Cancel\n");
	printf("> ");
}

int Option_Choosing(size_t options_amount_)
{
	int option = 0;

	scanf_s("%d", &option);

	while (option <= 0 || option > options_amount_)
	{
		printf("\n!!! Incprrect Input !!! Try Again...\n> ");
		scanf_s("%d", &option);
	}

	return option;
}