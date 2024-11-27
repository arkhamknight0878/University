#pragma once

#include <iostream>

using namespace std;

class Function
{
protected:
	double argument;
public:
	Function() { argument = 0; }

	virtual ~Function() {};

	void SetArg(double arg_) {argument = arg_;}

	virtual void SetCoeff() = 0;

	virtual double GetValue() = 0;

	virtual const string& GetName() const = 0;
};