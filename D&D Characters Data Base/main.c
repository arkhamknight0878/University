#include "Character_Type.h"

#include <stdio.h>

int main()
{
	size_t option = 0;
	size_t index = 0;
	size_t size = 0;
	size_t capacity = 1;

	DataBase* database = DataBase_Create(5);

	while (option != 7)
	{
		DataBase_Menu_Print();

		option = Option_Chooing(7);

		switch (option)
		{
		case 1:
			Add_Element(database, "Characters.txt");
			break;
		case 2:
			Edit_Element(database);
			break;
		case 3:
			Data_Base_List_Print(database);
			break;
		case 5:
			Search_By_Key(database);
			break;
		case 6:
			Delete_By_Key(database);
			break;
		case 7:
			printf("Goodbye\n");
			break;
		}
	}

	return 0;
}