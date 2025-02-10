#pragma once

#include <iostream>
#include <fstream>

enum states { begin, not_even_ones, even_ones, not_even_zeroes, even_zeroes, error, end };
enum alfbet { zero, one, ln };

const int states_amount = 7;
const int alfabet_size = 3;

class StateMachine
{
private:
	typedef int(StateMachine::* func_ptr)();
	func_ptr states_table[states_amount][alfabet_size];

	int value;

	int Q0()
	{
		if (!value)
			return not_even_zeroes;
		else if (value == 1)
			return not_even_ones;
		else
			return error;
	}

	int Q1()
	{
		if (!value)
			return error;
		else if (value == 1)
			return even_ones;
		else
			return error;
	}

	int Q2()
	{
		if (!value)
			return not_even_zeroes;
		else if (value == 1)
			return not_even_ones;
		else
			return error;
	}

	int Q3()
	{
		if (!value)
			return even_zeroes;
		else if (value == 1)
			return error;
		else
			return end;
	}

	int Q4()
	{
		if (!value)
			return not_even_zeroes;
		else
			return error;
	}

	int ERROR()
	{
		return error;
	}

	int END()
	{
		return end;
	}

	int Transliterator(int ch_)
	{
		if (!ch_)
			return zero;
		else if (ch_ == 1)
			return one;
		else if (ch_ == '\n')
			return ln;
		else
			return -1;
	}

public:
		StateMachine()
		{
			value = 0;

			states_table[begin][zero] = &StateMachine::Q3;
			states_table[begin][one] = &StateMachine::Q1;
			states_table[begin][ln] = &StateMachine::ERROR;

			states_table[not_even_ones][zero] = &StateMachine::ERROR;
			states_table[not_even_ones][one] = &StateMachine::Q2;
			states_table[not_even_ones][ln] = &StateMachine::ERROR;

			states_table[even_ones][zero] = &StateMachine::Q3;
			states_table[even_ones][one] = &StateMachine::Q1;
			states_table[even_ones][ln] = &StateMachine::ERROR;

			states_table[not_even_zeroes][zero] = &StateMachine::Q4;
			states_table[not_even_zeroes][one] = &StateMachine::ERROR;
			states_table[not_even_zeroes][ln] = &StateMachine::END;

			states_table[even_zeroes][zero] = &StateMachine::Q3;
			states_table[even_zeroes][one] = &StateMachine::ERROR;
			states_table[even_zeroes][ln] = &StateMachine::ERROR;
		}

		bool Parse(const char* file_name_)
		{
			std::ifstream in(file_name_);
			if (!in)
			{
				std::cout << "File Was Not Opened" << std::endl;
				return;
			}

			int ch;
			int current_state = begin;

			while (current_state != end && current_state != error)
			{
				ch = std::cin.get();
				current_state = (this->*states_table[current_state][Transliterator(ch)])();
			}

			if (current_state == error)
				return false;
			else
				return true;
		}
};