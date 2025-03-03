#include "Parser.h"
#include <locale>

int main()
{
	std::setlocale(LC_ALL, "rus");

	Parser p;

	p.parse("true_test.txt");

	return 0;
}