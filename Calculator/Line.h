#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Line : protected Function
{
private:
	double a;
	double b;
public:
	Line(double a_ = 0, double b_ = 0, double argument_ = 0);

	~Line() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

