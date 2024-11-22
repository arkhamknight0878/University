#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

#include <math.h>

class Exponent : public Function
{
private:
	double eps;

	double Factorial(size_t argument_);
public:
	Exponent();

	~Exponent() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

