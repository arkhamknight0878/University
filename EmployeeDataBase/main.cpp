#include "database.h"

#include <iostream>

using namespace std;

int main()
{
	/*Employee* list = nullptr;
	size_t index = 0;

	int creation_output = Employee_Create_F("list.txt", list, index);

	switch (creation_output)
	{
	case -1:
		cout << "File Was Not Found" << endl;
		break;
	case -2:
		cout << "Memmory Allocation Problem" << endl;
		break;
	case -3:
		cout << "File Was Not Opened" << endl;
		break;
	case 0:
		for (size_t i = 0; i < index; ++i)
		{
			printf("%2Iu. ", i);
			list[i].Info_Out();
		}
		break;
	}*/

	DataBase* data_base = new DataBase[1];
	int creation_output = data_base->Base_Create_F("list.txt");

	data_base->Base_Output();
	data_base->Element_Add();
	data_base->Base_Output();

	return 0;
}