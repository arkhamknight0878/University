#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Line : public Function
{
private:
	string name;
	double a;
	double b;
public:
	Line() : name("ax + b") { a = 0; b = 0; }

	~Line() {}

	void SetCoeff() override;

	const string& GetName() const override { return name; }

	double GetValue() override { return a * argument + b; }
};