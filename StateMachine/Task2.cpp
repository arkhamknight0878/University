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

bool Task2::Parse(const std::string str_)
{
	int current_state = s_begin;
	auto it = str_.begin();

	while (current_state != s_end && current_state != s_error)
	{
		if (it == str_.end())
			value = '\n';
		else
			value = *(it++);
		current_state = (this->*states_table[current_state][Transliterator(value)])();
	}

	if (current_state == s_error)
		return false;
	else
		return true;
}