#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	char* name;
	double argument;
public:
	Function(double argument_ = 0) { name[0] = '\0'; argument = argument_; }

	virtual ~Function() {};

	virtual void Calculate() = 0;

	virtual char* GetName() = 0;
};

