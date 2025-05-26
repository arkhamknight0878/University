#include "synthax_analyzer.h"

#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<synthax_analyzer> sa = std::make_unique<synthax_analyzer>();

	sa->start("input1.txt");
	std::cout << "FIN" << std::endl;

	return 0;
}