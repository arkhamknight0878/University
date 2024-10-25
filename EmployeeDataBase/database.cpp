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

void DataBase::Employees_to_Edit(const char* name_)
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

void DataBase::Swap(Employee& emp1_, Employee& emp2_)
{
	Employee tmp = emp1_;
	emp1_ = emp2_;
	emp2_ = tmp;
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
	initials[4] = '\0';
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
		if (current_amount == capasity)
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

int DataBase::Element_Add(Employee& employee_)
{
	if (current_amount >= capasity)
	{
		int expanton_output = 0;
		expanton_output = Base_Expansion();

		if (expanton_output == -1)
			return -3;
	}

	size_t index = 0;

	Employee* new_base = new Employee[capasity];
	if (!new_base)
		return -1;

	for (size_t i = 0; i < current_amount; ++i)
	{
		if (strcmp(base[i].Get_Name(), employee_.Get_Name()) > 0)
		{
			new_base[index++] = employee_;

			for (size_t j = i; j < current_amount ; ++j)
				new_base[index++] = base[j];

			++current_amount;

			base = new_base;

			return 0;
		}

		new_base[index++] = base[i];
	}

	return 0;
}

void DataBase::Element_Delete(const char* name_)
{
	size_t index = 0;
	size_t n1 = 0;

	Employees_to_Edit(name_);

	printf("\nWhich One Do You Want to Delete? (Enter Index)\n> ");
	scanf_s("%Iu", &index);

	for (size_t j = index - 1; j < current_amount - 1; ++j)
		base[j] = base[j + 1];

	--current_amount;
}

int DataBase::Element_Change(char* name_)
{
	size_t index = 0;
	int option = 0;
	char initials[5];
	initials[4] = '\0';

	Employees_to_Edit(name_);

	printf("\nWhich One Do You Want to Change? (Enter Index)\n> ");
	scanf_s("%Iu", &index);

	--index;

	Edit_Element_Menu_Print();
	option = Option_Choosing(5);

	switch (option)
	{
	case 1:
	{
		printf("\nEnter New Name:\n> ");
		scanf_s("%s %s", name_, 31, initials, 5);

		strcat(name_, " ");
		strcat(name_, initials);

		base[index].Set_Name(name_);

		break;
	}
	case 2:
	{
		size_t new_birth_date = 0;

		printf("Enter New Birth Date:\n> ");
		scanf_s("%Iu", &new_birth_date);

		base[index].Set_Birth_Year(new_birth_date);

		break;
	}
	case 3:
	{
		char new_start_date[11];

		printf("Enter New Start Date:\n> ");
		scanf_s("%s", new_start_date, 11);

		base[index].Set_Start_Date(new_start_date);

		break;
	}
	case 4:
	{
		float new_salary = 0;

		printf("Enter New Start Date:\n> ");
		scanf_s("%f", &new_salary);

		base[index].Set_Salary(new_salary);
		break;
	}
	}

	return 0;
}

int DataBase::Copy_to_File(const char* filename_)
{
	if (!filename_)
		return -1;

	FILE* fp;
	fopen_s(&fp, filename_, "w");
	if (!fp)
		return -2;

	for (size_t i = 0; i < current_amount; ++i)
		fprintf_s(fp, "%Iu. %s %Iu %s %f\n", i + 1, base[i].Get_Name(), base[i].Get_Birth_Year(), base[i].Get_Start_Date(), base[i].Get_Salary());
}

void Main_Menu_Print()
{
	system("cls");
	printf("What Do You Want to Do?\n");
	printf("1. Create Employee Data Base From File\n");
	printf("2. Print Out Data Base\n");
	printf("3. Edit Data Base\n");
	printf("4. Copy Base to File\n");
	printf("5. Exit\n");
	printf("> ");
}

void Edit_Base_Menu_Print()
{
	printf("\nWhat Exactly Do You Want to Change?\n");
	printf("1. Add New Element\n");
	printf("2. Delete Element\n");
	printf("3. Change Element\n");
	printf("4. Cancel\n");
	printf("> ");
}

void Edit_Element_Menu_Print()
{
	printf("\nWhat Do You Want to Change?\n");
	printf("1. Name\n");
	printf("2. Birth Date\n");
	printf("3. Start Date\n");
	printf("4. Salary\n");
	printf("5. Cancel\n");
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