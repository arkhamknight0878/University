#pragma once

#include <iostream>
#include <fstream>

enum StandartStates {s_begin, s_error, s_end};
enum Alphabeth {zero, one, ln, other};

const int alfabet_size = 4;

class StateMachine
{
protected:
	int value = 0;

	int Begin();

	int Error();

	int End();

	int Transliterator(int ch_);
};