#include "assembly_code_generator.h"
#include <locale>


int main()
{
	setlocale(LC_ALL, "RUS");

	AssemblyCodeGenerator g("task_14.txt");
	try
	{
		g.code_generator();
	}
	catch (...)
	{
		cout << "ошибка при выполнении анализа" << endl << "проверьте наличие фходного файла или доступ к онному";
	}
}