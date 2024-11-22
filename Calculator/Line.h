#pragma once
#pragma warning (disable: 4996)

#include "Function.h"

class Line : public Function
{
private:
	double a;
	double b;
public:
	Line();

	~Line() override { delete[] name; }

	char* GetName() override { return name; }

	void Calculate() override;
};

