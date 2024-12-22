#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ------------------------------------------------------- Constants And Variables -------------------------------------------------------

// Коды типов
enum VariableType {Int = 1, BoolVector};

// Структура для переменных
struct Variable
{
	string name;
	int type;
	int int_value;
};

// --------------------------------------------------------------------------------

// Начальный вектор
int start_vector[] = { 0,0,0,0,1,0,0,0,0,3,0,0,0,0,0,6,0,11,0,0,0,0,14,0,0,0 };

// Таблица обнаружений
// TODO: таблица обнаружений

// --------------------------------------------------------------------------------

// Коды классов лексем
enum SymbolicTokenClass { Letter = 1, Digit, Arithm_Oper, Relation_Oper, Space, StrEnd, Comment, Error, FileEnd, Push, Pop, Ji, Jmp, Read, Write, End };

// Коды арифметических операций
enum ArithmOperType { Plus = 1, Minus, Mult, Div, Mod };

// Коды операций отношения
enum RelationType { Equal, NotEqual, Less, Greater, Leq, Geq, Not };

// Коды состояний
enum States { s_A1 = 1, s_A2,s_B1, s_C1, s_D1, s_E1, s_E2, s_E3, s_F1, s_F2, s_F3, s_G1, s_H1, s_I1, s_I2, s_J1 , s_Stop};

// --------------------------------------------------------------------------------

// Структура лексемы
struct SymbolicToken
{
	SymbolicTokenClass symbolic_class;
	int value;
	int const_table_index;
	int string_number_r;
};

vector<SymbolicToken> tokens_list;

const int classes_amount = 9;
const int states_amount = 16;

// Лексический Анализатор
class Parser
{
private:
	typedef int (Parser::* function_pointer)();
	function_pointer table[states_amount][classes_amount];	// Таблица состояний

	string name_r;											// Регистр имени переменной
	SymbolicToken s;										// Символьная лексема
	SymbolicTokenClass class_r;								// Регистр класса лексемы
	int number_r;											// Регистр числа
	RelationType relation_r;								// Регистр отношение
	int find_r;												// Регистр обнаружения
	int token_value_r;										// Регистр значения лексемы
	int string_number_r;									// Номер строки
	bool is_const;											// Флаг константы

	SymbolicToken Transliterator(int ch_)
	{
		SymbolicToken result;
		result.value = 0;

		if (isalpha(ch_))
		{
			result.symbolic_class = Letter;
			result.value = ch_;
		}
		else if (isdigit(ch_))
		{
			result.symbolic_class = Digit;
			result.value = ch_ - '0';
		}
		else if (ch_ == '+' || ch_ == '-' || ch_ == '*' || ch_ == '/' || ch_ == '%')
		{
			result.symbolic_class = Arithm_Oper;

			// Распознавание арифметической операции
			switch (ch_)
			{
			case '+':
				result.value = Plus;
				break;
			case '-':
				result.value = Minus;
				break;
			case '*':
				result.value = Mult;
				break;
			case '/':
				result.value = Div;
				break;
			case '%':
				result.value = Mod;
				break;
			}
		}
		else if (ch_ == '=' || ch_ == '!' || ch_ == '<' || ch_ == '>')
		{
			result.symbolic_class = Relation_Oper;

			// Распознавание опреции сравнения
			switch (ch_)
			{
			case '=':
				result.value = Equal;
				break;
			case '!':
				result.value = Not;
				break;
			case '<':
				result.value = Less;
				break;
			case '>':
				result.value = Greater;
				break;
			}
		}
		else if (ch_ == ' ' || ch_ == '\t')
		{
			result.symbolic_class = Space;
		}
		else if (ch_ == ';')
		{
			result.symbolic_class = Comment;
		}
		else if (ch_ == EOF)
		{
			result.symbolic_class = FileEnd;
		}
		else
			result.symbolic_class = Error;

		return result;
	}

	int ErrorHandler()
	{
		class_r = Error;
		CreateToken();
		cout << endl << "Error at " << s.string_number_r << "string" << endl;

		return s_J1;
	}

	// TODO: доделать
	void CreateToken()
	{
		s.symbolic_class = class_r;
		s.value = token_value_r;
		s.string_number_r = string_number_r;

		tokens_list.push_back(s);
	}

	// TODO: доделать
	void AddConstant()
	{
		if (!is_const)
			return;
	}

	// TODO: доделать
	void AddVariable()
	{

	}

	int A1() { return s_A1; }

	int A2() { return s_A2; }

	int B1() { return s_B1; }

	int C1() { return s_C1; }

	int D1() { return s_D1; }

	int E1() { return s_E1; }

	int E2() { return s_E2; }

	int E3() { return s_E3; }

	int F1() { return s_F1; }

	int F2() { return s_F2; }

	int F3() { return s_F3; }

	int G1() { return s_G1; }

	int H1() { return s_H1; }

	int I1() { return s_I1; }

	int I2() { return s_I2; }

	int Stop() { return s_Stop; }

	int A1a()
	{
		CreateToken();
		++string_number_r;
		return s_A1;
	}

	int A1b()
	{
		++string_number_r;
		return s_A1;
	}

	int A2a()
	{
		++string_number_r;
		return s_A2;
	}

	int A2b()
	{
		++string_number_r;
		return s_A2;
	}

	// TODO: доделать
	int A2c()
	{
		CreateToken();
	}

	// TODO: доделать
	int A2d()
	{

	}

	int A2e()
	{
		if (relation_r == Not)
			return ErrorHandler();

		CreateToken();

		++string_number_r;

		return s_A2;
	}

	int A2f()
	{
		class_r = Error;

		CreateToken();

		++string_number_r;

		return s_A2;
	}

	int B1a()
	{
		find_r = start_vector[s.value - 97];

		if (!find_r)
			return ErrorHandler();

		return s_B1;
	}

	int B1b()
	{
		++find_r;
		return s_B1;
	}

	// TODO: доделать
	int C1a()
	{
		class_r = Arithm_Oper;
		// TODO: доделать
		// token_value_r

		CreateToken();

		return s_C1;
	}

	int C1b()
	{
		class_r = End;

		CreateToken();

		return s_C1;
	}

	int C1c()
	{
		class_r = Read;

		CreateToken();

		return s_C1;
	}

	int C1d()
	{
		class_r = Write;

		CreateToken();

		return s_C1;
	}

	int C1e()
	{
		AddConstant();

		CreateToken();

		return s_C1;
	}

	int C1f()
	{
		AddVariable();

		CreateToken();

		return s_C1;
	}

	int C1g()
	{
		if (relation_r == Not)
			return ErrorHandler();

		CreateToken();

		return s_C1;
	}

	int C1h()
	{
		switch (relation_r)
		{
		case Not:
			if (s.value == '=')
				relation_r = NotEqual;
			break;
		case Less:
			if (s.value == '=')
				relation_r = Leq;
			break;
		case Greater:
			if (s.value == '=')
				relation_r = Geq;
			break;
		}

		if (!relation_r)
			return ErrorHandler();

		CreateToken();

		return s_C1;
	}

	// TODO: доделать
	int M1()
	{
		
	}
};

