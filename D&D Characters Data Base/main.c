#include "Character_Type.h"

#include <stdio.h>

int main()
{
	size_t option = 0;
	size_t index = 0;
	size_t size = 0;
	size_t capacity = 1;

	/*Character* character = Character_Create();

	Info_Print(character);*/

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
			List_Print(database);
		case 7:
			printf("Goodbye\n");
			break;
		}
	}

	return 0;
}