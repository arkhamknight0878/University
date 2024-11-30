#include "Menu.h"

int main()
{
	Line line_f;
	Exponent exp_f;
	Polynomial pol_f;
	Cube cube_f;

	Function* arr[] = { &line_f, &exp_f, &pol_f, &cube_f };
	int arr_size = sizeof(arr) / sizeof(Function*);

	Menu menu(arr, arr_size);

	while (Function* obj = menu.SelectedFunction())
	{
		obj->Calculate();
	}

	cout << "FIN" << endl;

	return 0;
}