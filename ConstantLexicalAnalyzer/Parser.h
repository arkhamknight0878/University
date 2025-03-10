#pragma once

#include <iostream>
#include <fstream>

enum States
{
	s_q0, s_q1, s_q2, s_q3, s_q4, s_q5, s_q6, s_Skip, s_End
};

enum Alphabeth
{
	DIGIT, EXP, DOT, SIGN, OTHER, END
};

const int states_amount = 9;
const int alphabeth_size = 6;

class Parser
{
private:
	int current;
	int number_r;
	int counter_r;
	int order_r;
	int error_code;
	double res;
	bool sign_r;

	typedef int(Parser::* fptr)();
	fptr parser_table[states_amount][alphabeth_size];

	int transliterator(int ch_);

	int q0();

	int q1();

	int q2();

	int q3();

	int q4();

	int q5();

	int q6();

	int Skip();

	int P1();

	int P2();

	int P3();

	int P4();

	int P5();

	int P6();

	int P7();

	int P8();

	int P9();

	int P10();

	int P11();

	int P12();

	int K1();

	int K2();

	int K3();

	int ErrorOther();

	int Error0();

	int Error1();

	int Error2();

	int Error3();

	int Error4();

	int Error5();

	int Error6();
public:
	Parser()
	{
		current = number_r = counter_r = order_r = error_code = 0;
		res = 0.0;
		sign_r = false;

		parser_table[s_q0][DIGIT] = &Parser::P1;
		parser_table[s_q0][DOT] = &Parser::P2;
		parser_table[s_q0][EXP] = parser_table[s_q0][SIGN] = parser_table[s_q0][END] = &Parser::Error0;
		parser_table[s_q0][OTHER] = &Parser::ErrorOther;

		parser_table[s_q1][DIGIT] = &Parser::P3;
		parser_table[s_q1][EXP] = &Parser::P4;
		parser_table[s_q1][DOT] = &Parser::P5;
		parser_table[s_q1][END] = &Parser::K1;
		parser_table[s_q1][SIGN] = &Parser::Error1;
		parser_table[s_q1][OTHER] = &Parser::ErrorOther;

		parser_table[s_q2][DIGIT] = &Parser::P6;
		parser_table[s_q2][EXP] = &Parser::P7;
		parser_table[s_q2][END] = &Parser::K2;
		parser_table[s_q2][DOT] = parser_table[s_q2][SIGN] = &Parser::Error2;
		parser_table[s_q2][OTHER] = &Parser::ErrorOther;

		parser_table[s_q3][DIGIT] = &Parser::P8;
		parser_table[s_q3][SIGN] = &Parser::P9;
		parser_table[s_q3][EXP] = parser_table[s_q3][DOT] = parser_table[s_q3][END] = &Parser::Error3;
		parser_table[s_q3][OTHER] = &Parser::ErrorOther;

		parser_table[s_q4][DIGIT] = &Parser::P10;
		parser_table[s_q4][EXP] = parser_table[s_q4][DOT] = parser_table[s_q4][SIGN] = parser_table[s_q4][END] = &Parser::Error4;
		parser_table[s_q4][OTHER] = &Parser::ErrorOther;

		parser_table[s_q5][DIGIT] = &Parser::P11;
		parser_table[s_q5][END] = &Parser::K3;
		parser_table[s_q5][OTHER] = &Parser::ErrorOther;
		parser_table[s_q5][EXP] = parser_table[s_q5][DOT] = parser_table[s_q5][SIGN] = &Parser::Error5;

		parser_table[s_q6][DIGIT] = &Parser::P12;
		parser_table[s_q6][OTHER] = &Parser::ErrorOther;
		parser_table[s_q6][EXP] = parser_table[s_q6][DOT] = parser_table[s_q6][SIGN] = &Parser::Error5;

		parser_table[s_Skip][DIGIT] = &Parser::Skip;
		parser_table[s_Skip][EXP] = &Parser::Skip;
		parser_table[s_Skip][DOT] = &Parser::Skip;
		parser_table[s_Skip][SIGN] = &Parser::Skip;
		parser_table[s_Skip][END] = &Parser::q0;
		parser_table[s_Skip][OTHER] = &Parser::Skip;
	}

	void parse(const char* filename_)
	{
		int current_state = s_q0;
		int value = 0;
		std::ifstream fp(filename_);
		if (!fp)
		{
			std::cout << "Ошибка при открытии файла";
			return;
		}

		while (value != EOF)
		{
			value = fp.get();

			current_state = (this->*parser_table[current_state][transliterator(value)])();
		}
	}
};