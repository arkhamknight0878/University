#include "Task1.h"

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
}

bool Task1::Parse(const std::string str_)
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