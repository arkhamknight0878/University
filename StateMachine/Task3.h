#pragma once

#include "StateMachine.h"

enum States { s_first_one = 3, s_is_next_zero };

const int states_amount = 5;

class Task3 : public StateMachine
{
private:
	typedef int(Task3::* func_ptr)();
	func_ptr states_table[states_amount][alfabet_size];

	int FirstOne();

	int IsNextZero();
public:
	Task3();

	bool Parse(const char* file_name_);
};