#include "Task3.h"

int Task3::FirstOne() { return s_first_one; }

int Task3::IsNextZero() { return s_is_next_zero; }

Task3::Task3()
{
	value = 0;

	states_table[s_begin][zero] = &Task3::Begin;
	states_table[s_begin][one] = &Task3::FirstOne;
	states_table[s_begin][ln] = &Task3::End;

	states_table[s_first_one][zero] = &Task3::Begin;
	states_table[s_first_one][one] = &Task3::IsNextZero;
	states_table[s_first_one][ln] = &Task3::End;

	states_table[s_is_next_zero][zero] = &Task3::Begin;
	states_table[s_is_next_zero][one] = &Task3::Error;
	states_table[s_is_next_zero][ln] = &Task3::Error;
}

bool Task3::Parse(const char* file_name_)
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