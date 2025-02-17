#include "Task4.h"

int Task4::One() { return s_one; }

int Task4::IsThree() { return s_is_three; }

Task4::Task4()
{
	value = 0;

	states_table[s_begin][zero] = &Task4::One;
	states_table[s_begin][one] = &Task4::One;
	states_table[s_begin][ln] = &Task4::End;

	states_table[s_one][zero] = &Task4::IsThree;
	states_table[s_one][one] = &Task4::IsThree;
	states_table[s_one][ln] = &Task4::End;

	states_table[s_is_three][zero] = &Task4::Error;
	states_table[s_is_three][one] = &Task4::Begin;
	states_table[s_is_three][ln] = &Task4::End;
}

bool Task4::Parse(const char* file_name_)
{
	int current_state = s_begin;
	std::ifstream fp(file_name_);
	if (!fp)
	{
		std::cout << "File Was Not Opened";
		return false;
	}

	while (fp)
	{
		value = fp.get();

		if (value != '\n')
			std::cout << (char)value;

		current_state = (this->*states_table[current_state][Transliterator(value)])();

		if (current_state == s_end || current_state == s_error)
		{
			if (current_state == s_error)
			{
				while (fp.peek() != '\n' && fp.peek() != EOF)
				{
					value = fp.get();
					if (value != '\n' && value != EOF)
						std::cout << (char)value;
				}

				std::cout << " : Not Oke";
			}
			else
				std::cout << " : Oke";

			current_state = s_begin;
			std::cout << std::endl;
		}
	}

	fp.close();
}