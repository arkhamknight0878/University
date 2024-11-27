#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Polynomial : public Function
{
private:
	string name;
	double* coefficients;
public:
	Polynomial() : name("a(n)x^n + ... + a(0)") { coefficients = nullptr; }

	~Polynomial() { delete[] coefficients; }

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override;
};