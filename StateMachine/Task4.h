#pragma once

#include "StateMachine.h"

enum States { s_one = 3, s_is_three };

const int states_amount = 5;

class Task4 : public StateMachine
{
private:
	typedef int(Task4::* func_ptr)();
	func_ptr states_table[states_amount][alfabet_size];

	int One();

	int IsThree();
public:
	Task4();

	bool Parse(const std::string str_);
};

