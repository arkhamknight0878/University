#pragma once

#include "Function.h"

class Polynomial : public Function
{
private:
	size_t pow;
	double* arr;
public:
	Polynomial();

	Polynomial(size_t numerator_);

	~Polynomial() { delete[] arr; }

	char* GetName() { return name; }
};

