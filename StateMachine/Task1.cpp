#include "Task1.h"

#include <fstream>

int Task1::One() { return s_one; }

int Task1::EOnes() { return s_even_ones; }

int Task1::NEZeroes() { return s_not_even_zeroes; }

int Task1::EZeroes() { return s_even_zeroes; }

Task1::Task1()
{
	value = 0;

	states_table[s_begin][zero] = &Task1::NEZeroes;
	states_table[s_begin][one] = &Task1::One;
	states_table[s_begin][ln] = &Task1::Error;

	states_table[s_one][zero] = &Task1::Error;
	states_table[s_one][one] = &Task1::EOnes;
	states_table[s_one][ln] = &Task1::Error;

	states_table[s_even_ones][zero] = &Task1::NEZeroes;
	states_table[s_even_ones][one] = &Task1::One;
	states_table[s_even_ones][ln] = &Task1::Error;

	states_table[s_not_even_zeroes][zero] = &Task1::EZeroes;
	states_table[s_not_even_zeroes][one] = &Task1::Error;
	states_table[s_not_even_zeroes][ln] = &Task1::End;

	states_table[s_even_zeroes][zero] = &Task1::NEZeroes;
	states_table[s_even_zeroes][one] = &Task1::Error;
	states_table[s_even_zeroes][ln] = &Task1::Error;

	states_table[s_begin][other] = &Task1::Error;
	states_table[s_one][other] = &Task1::Error;
	states_table[s_even_ones][other] = &Task1::Error;
	states_table[s_not_even_zeroes][other] = &Task1::Error;
	states_table[s_even_zeroes][other] = &Task1::Error;
}

bool Task1::Parse(const char* file_name_)
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