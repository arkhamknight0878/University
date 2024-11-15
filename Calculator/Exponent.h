#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

#include <math.h>

class Exponent : protected Function
{
private:
	double eps;

	double Factorial(size_t argument_);
public:
	Exponent(double eps_ = 0, double argument_ = 0);

	~Exponent() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

