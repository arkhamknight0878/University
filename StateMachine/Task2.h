#pragma once

#include "StateMachine.h"

enum States { s_one = 3, s_not_even_zeroes, s_even_zeroes };

const int states_amount = 7;

class Task2 : public StateMachine
{
private:
	typedef int(Task2::* func_ptr)();
	func_ptr states_table[states_amount][alfabet_size];

	int One();

	int NEZeroes();

	int EZeroes();

public:
	Task2();

	bool Parse(const char* file_name_);
};