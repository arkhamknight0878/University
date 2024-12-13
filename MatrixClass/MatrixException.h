#pragma once

#include <iostream>

using namespace std;

class MatrixException
{
public:
	virtual void PrintErr() = 0;
};

class DiffSize : public MatrixException
{
public:
	void PrintErr() override { cout << "Matrixes Must Have Same Size" << endl; }
};

class IncorrectInput : public MatrixException
{
public:
	void PrintErr() override { cout << "Incorrect Input" << endl; }
};

class DiffRowsColumns : public MatrixException
{
public:
	void PrintErr() override { cout << "Rows Not Equal To Columns Of Other Matrix" << endl; }
};