#include "Task2.h"

int Task2::One() { return s_one; }

int Task2::NEZeroes() { return s_not_even_zeroes; }

int Task2::EZeroes() { return s_even_zeroes; }

Task2::Task2()
{
	value = 0;

	states_table[s_begin][zero] = &Task2::Begin;
	states_table[s_begin][one] = &Task2::One;
	states_table[s_begin][ln] = &Task2::End;

	states_table[s_one][zero] = &Task2::NEZeroes;
	states_table[s_one][one] = &Task2::Error;
	states_table[s_one][ln] = &Task2::End;

	states_table[s_not_even_zeroes][zero] = &Task2::EZeroes;
	states_table[s_not_even_zeroes][one] = &Task2::Error;
	states_table[s_not_even_zeroes][ln] = &Task2::End;

	states_table[s_even_zeroes][zero] = &Task2::NEZeroes;
	states_table[s_even_zeroes][one] = &Task2::One;
	states_table[s_even_zeroes][ln] = &Task2::End;
}

bool Task2::Parse(const char* file_name_)
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

				fp.ignore();
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