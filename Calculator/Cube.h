#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Cube : public Function
{
public:
	Cube();

	~Cube() { delete[] name; }

	char* GetName() { return name; }

	void Calculate();
};