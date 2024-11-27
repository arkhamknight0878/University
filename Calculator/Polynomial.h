#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Polynomial : public Function
{
private:
	double* coefficients;
public:
	Polynomial();

	~Polynomial() override { delete[] coefficients; }

	char* GetName() override { return name; }

	void Calculate() override;
};