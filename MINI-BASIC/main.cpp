#include "assembler_code_generator.h"

#include <iostream>
#include <memory>

std::string decode_char_name(int TO_index_)
{
	std::string res;
	if (TO_index_ <= 26)
		res += (char)(TO_index_ + 'A' - 1);
	else
	{
		int RZN_plus_1 = TO_index_ / 26;
		int RI = TO_index_ % 26;
		int RZN = RZN_plus_1 - 1;

		res += (char)('A' + RI - 1) + std::to_string(RZN);
	}

	return res;
}

int main()
{
	/*std::unique_ptr<synthax_analyzer> sa = std::make_unique<synthax_analyzer>();

	sa->start("task_14.txt");
	std::cout << "FIN" << std::endl;*/

	std::unique_ptr<assembler_code_generator> acg = std::make_unique<assembler_code_generator>("task_14.txt");
	acg->generate("fin.asm");

	/*for (int i = 1; i <= 286; i++)
		std::cout << i << ". " << decode_char_name(i) << std::endl;*/

	return 0;
} 