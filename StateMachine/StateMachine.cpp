#include "StateMachine.h"

int StateMachine::Begin() { return s_begin; }

int StateMachine::Error() { return s_error; }

int StateMachine::End() { return s_end; }

int StateMachine::Transliterator(int ch_)
{
	if (ch_ == '0')
		return zero;
	else if (ch_ == '1')
		return one;
	else if (ch_ == '\n')
		return ln;
	else
		return -1;
}