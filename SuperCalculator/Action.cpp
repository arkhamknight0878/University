#include "Action.h"

void Calculation::Operate(Function* func_)
{
	cout << "-----------------------" << endl;
	cout << "Calculate Function y = ";
	cout << func_->GetName() << endl;

	func_->SetCoeff();

	double x = 0;
	cout << endl << "Enter x" << endl;
	cout << "x = "; cin >> x;
	func_->SetArg(x);

	cout << endl << "y = " << func_->GetValue() << endl;
	cout << "-----------------------" << endl;
}

void Tabulation::Operate(Function* func_)
{
	cout << "----------------------------" << endl;
	cout << "Tabulation For Function y = ";
	cout << func_->GetName() << endl;

	func_->SetCoeff();

	double begin, step, end;
	cout << endl << "Enter Begin, Step, And" << endl;
	cout << "begin = "; cin >> begin;
	cout << "step = ";	cin >> step;
	cout << "end = ";	cin >> end;

	double x = begin;

	while (x <= end)
	{
		func_->SetArg(x);
		cout << setw(6) << x << "|" << setw(14) << func_->GetValue() << endl;

		x += step;
	}

	cout << "----------------------------" << endl;
}