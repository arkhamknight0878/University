#include "StateMachine.h"

#include <string>

namespace stq
{
	void string_input(std::string& string_to_input_)
	{
		char input_char;

		while (true)
		{
			input_char = std::cin.get();

			if (input_char == '\n')
				break;

			string_to_input_ += input_char;
		}
	}
}

int main()
{
	StateMachine machine;
	std::string input_string;
	std::cout << "Enter Your String:" << std::endl;
	stq::string_input(input_string);

	bool is_oke = 

	return 0;
}