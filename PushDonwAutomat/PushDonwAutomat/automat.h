#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

class Automat
{
private:
	typedef void(Automat::* fptr)();

	std::string input;
	std::string magazin;
	std::string output;
	fptr current_state;

	char stack_head;
	char input_head;

	bool stop_flag;
	bool error_flag;

	void q1();

	void q2();

	void q3();

	void rundown_output();
public:
	Automat();

	~Automat();

	void parse(const char* file_name_);
};

