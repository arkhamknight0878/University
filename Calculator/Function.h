#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	char* name;
	double argument;
public:
	Function() { name = new char; name[0] = '\0'; argument = 0; }

	virtual ~Function() {};

	virtual void Calculate() = 0;

	virtual char* GetName() = 0;
};