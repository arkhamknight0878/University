#include "Menu.h"
#include "Line.h"
#include "Exponent.h"
#include "Polynomial.h"

int main()
{
	Line line_func;
	Exponent exp_func;
	Polynomial polym_func;

	Calculation calc_action;
	Tabulation tabul_action;

	Function* f_arr[]	= { &line_func, &exp_func, &polym_func, nullptr };
	Action* a_arr[]		= { &calc_action, &tabul_action };

	Menu main_menu(f_arr, a_arr);

	while (Function* f_ptr = main_menu.SelectedFunction())
	{
		Action* a_ptr = main_menu.SelectedAction();
		a_ptr->Operate(f_ptr);
	}

	cout << "FIN" << endl;

	return 0;
}