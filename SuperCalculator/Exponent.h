#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

#include <math.h>

class Exponent : public Function
{
private:
	string name;
	double eps;

	double Factorial(size_t argument_);
public:
	Exponent() : name("e^x") { eps = 0; };

	~Exponent() {}

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override;
};