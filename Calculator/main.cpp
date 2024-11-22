#include "Menu.h"
#include "Function.h"
#include "Line.h"
#include "Exponent.h"

int main()
{
	Line line_finction;
	Exponent exponent_function;

	Function* ptrs[] = { &line_finction, &exponent_function, nullptr };

	Menu menu(ptrs, 3);

	while (Function* obj = menu.SelectedFunction())
		obj->Calculate();

	cout << endl << "FIN" << endl;

	return 0;
}