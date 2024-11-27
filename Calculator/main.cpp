#include "Menu.h"

int main()
{
	Line line_f;
	Exponent exp_f;
	Polynomial pol_f;

	Function* arr[] = { &line_f, &exp_f, &pol_f, nullptr };

	Menu menu(arr);

	while (Function* obj = menu.SelectedFunction())
	{
		obj->Calculate();
	}

	cout << "FIN" << endl;

	return 0;
}