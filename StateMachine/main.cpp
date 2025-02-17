#include "Task2.h"

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
	Task2 machine;
	std::string input_string;
	/*std::cout << "Enter Your String:" << std::endl;
	stq::string_input(input_string);*/

	bool is_oke = machine.Parse("TextFile1.txt");

	return 0;
}

/*000
1111000
111000
110000
110006
00011000
110030
000011
0000
117000
11511000*/