#pragma once

#include <iostream>
#include <string>

using namespace std;

//#ifndef  FUNCTION_H
//#define FUNCTION_H

class Function
{
protected:
	char* name;
	double argument;
public:
	Function() { name = nullptr; argument = 0; }

	virtual ~Function() {};

	virtual void Calculate() = 0;

	virtual char* GetName() = 0;
};

//#endif // ! FUNCTION_H