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

bool Task4::Parse(const std::string str_)
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