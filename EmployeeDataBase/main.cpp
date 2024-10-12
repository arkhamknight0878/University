#include "database.h"

#include <iostream>

using namespace std;

int main()
{
	DataBase* data_base = new DataBase[1];
	size_t main_option = 0;
	size_t options = 0;
	int functions_output = 0;

	while (main_option != 5)
	{
		Main_Menu_Print();

		main_option = Option_Choosing(5);
		switch (main_option)
		{
		case 1:
			functions_output = data_base->Base_Create_F("list.txt");
			switch (functions_output)
			{
			case -1:
				printf("\n!!! File Was Not Found !!!\n");
				return -1;
			case -2:
				printf("\n!!! Memmory Allocation Problem !!!\n");
				return -2;
			case -3:
				printf("\n!!! File Was Not Opened!!! \n");
				return -3;
			case -4:
				printf("\n!!! Memmory Alocation Problem While Trying To Expand Data Base !!!\n");
				return -4;
			case 0:
				printf("\nCreation Ended Successfully\n\n");
				break;
			}

			system("pause");

			break;
		case 2:
			data_base->Base_Output();
			system("pause");
			break;
		case 3:
			Edit_Base_Menu_Print();

			options = Option_Choosing(4);
			switch (options)
			{
			case 1:
			{
				Employee employee;
				employee.Info_Input();

				functions_output = data_base->Element_Add(employee);
				switch (functions_output)
				{
				case -4:
					printf("\n!!! Memmory Alocation Problem While Trying To Expand Data Base !!!\n");
					return -3;
				case 0:
					printf("\nElement Was Added Successfully\n\n");
					break;
				}
				break;
			}
			case 2:
			{
				char name[31];
				char initials[5];
				initials[4] = '\0';

				printf("\nEnter The Name of Employee You Want To Delete:\n> ");
				scanf_s("%s %s", name, 31, initials, 5);

				strcat(name, " ");
				strcat(name, initials);

				data_base->Element_Delete(name);
				printf("\nElement Was Deleted Successfully\n\n");
				break;
			}
			case 3:
			{
				char name[31];
				char initials[5];
				initials[4] = '\0';

				printf("\nEnter The Name of Employee You Want To Delete:\n> ");
				scanf_s("%s %s", name, 31, initials, 5);

				strcat(name, " ");
				strcat(name, initials);

				data_base->Element_Change(name);
				printf("\nElement Was Changed Successfully\n\n");
				break;
			}
			}

			if (options != 4)
				system("pause");

			break;
		case 4:
		{
			char filename[50];

			printf("\nEnter File Name:\n> ");
			scanf_s("%s", filename, 50);

			switch (functions_output)
			{
			case -1:
				printf("\n!!! File Was Not Found !!!\n");
				return -1;
			case -2:
				printf("\n!!! File Was Not Opened!!! \n");
				return -2;
			case 0:
				functions_output = data_base->Copy_to_File(filename);
				break;
			}

			printf("\nFile Was Copied Succsessfully\n");
			system("pause");

			break;
		}
		}
	}

	return 0;
}