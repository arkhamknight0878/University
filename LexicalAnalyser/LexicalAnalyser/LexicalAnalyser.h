#pragma once

#include "Token.h"
#include "DetectionTable.h"

#include <fstream>
#include <string>

enum States
{
	s_A1, s_A2, s_A3, s_B1, s_C1, s_C2, s_D1, s_D2, s_D3, s_D4, s_D5, s_D6, s_E1, s_E2, s_F1, s_F2, s_F3, s_G1, s_H1, s_M1, s_M2, s_M3, s_EXIT1, s_EXIT2, s_EXIT3, s_EXIT4, s_EXIT5, s_EXIT6, s_DA1D, s_DA2D, s_DA3D, s_DA1E, s_DA1ECYCLE
};

class LexicalAnalyser
{
private:
	std::fstream error_list;
	std::string string_reg;
	void(LexicalAnalyser::* current_state)();
	std::vector<Token>* tok_table_ptr;
	double number_reg;
	int current_value;
	int order_sign_reg;
	int order_reg;
	int counter_reg;
	int lex_class_reg;
	int relation_value_reg;
	int char_value_reg;
	int state_reg;
	int detection_reg;
	int char_class_value_reg;
	int error_counter;

	friend struct TransitionTable;

	int transliterator(int ch_)
	{
		if (isalpha(ch_))
		{
			state_reg = LETTER;
			current_value = ch_;
		}
		else if (isdigit(ch_))
		{
			state_reg = DIGIT;
			current_value = ch_ - '0';
		}
		else if (ch_ == '+' || ch_ == '-' || ch_ == '*' || ch_ == '/' || ch_ == '^')
		{
			state_reg = ARITH_OPER;

			switch (ch_)
			{
			case '+':
				current_value = ADD;
				break;
			case '-':
				current_value = SUB;
				break;
			case '*':
				current_value = MULT;
				break;
			case '/':
				current_value = DIV;
				break;
			case '^':
				current_value = POW;
				break;
			}
		}
		else if (ch_ == '<' || ch_ == '>' || ch_ == '=')
		{
			state_reg = RELATION_OPER;

			switch (ch_)
			{
			case '<':
				current_value = LESS;
				break;
			case '>':
				current_value = GREATER;
				break;
			case '=':
				current_value = EQ;
				break;
			}
		}
		else if (ch_ == '(')
		{
			state_reg = LBRACE;
			current_value = LBRACE;
		}
		else if (ch_ == ')')
			current_value = RBRACE;
		else if (ch_ == '.')
			current_value = DOT;
	}

	void CreateToken();

	void ErrorHandler();

	void A1();

	void A2();

	void A3();

	void B1();

	void C1();

	void C2();

	void D1();

	void D2();

	void D3();

	void D4();

	void D5();

	void D6();

	void E1();

	void E2();

	void F1();

	void F2();

	void F3();

	void G1();

	void H1();

	void M1();

	void M2();

	void M3();

	void EXIT1();

	void EXIT2();

	void EXIT3();

	void EXIT4();

	void EXIT5();

	void EXIT6();

	void DA1D();

	void DA2D();

	void DA3D();

	void DA1E();

	void DA1ECYCLE();

	void A1a()
	{
		CreateToken();
		current_state = A1;
	}

	void A1b()
	{
		DA1D();
		current_state = A1;
	}

	void A1c()
	{
		DA2D();
		A1a();

		current_state = A1;
	}

	void A1d()
	{
		DA3D();
		A1a();

		current_state = A1;
	}

	void A1e()
	{
		DA1E();
		A1a();

		current_state = A1;
	}

	void A2a()
	{
		char_class_value_reg = ARITH_OPER;
		current_state = A2;
	}

	void A2b()
	{
		CreateToken();
		current_state = A2;
	}

	void A2c()
	{
		DA1D();
		current_state = A2;
	}

	void A2d()
	{
		DA2D();
		A2g();

		current_state = A2;
	}

	void A2e()
	{
		DA3D();
		A2g();

		current_state = A2;
	}

	void A2f()
	{
		DA1E();
		A2g();

		current_state = A2;
	}

	void A2g()
	{
		CreateToken();
		current_state = A2;
	}

	void A2h()
	{
		char_class_value_reg = LBRACE;
		CreateToken();

		current_state = A2;
	}

	void A2j()
	{
		DA1E();

		current_state = A2;
	}

	void A2k()
	{
		CreateToken();

		current_state = A2;
	}

	void A2l()
	{
		DA1D();
		A2k();

		current_state = A2;
	}

	void A2m()
	{
		DA2D();
		A2k();

		current_state = A2;
	}

	void A2n()
	{
		DA3D();
		A2k();

		current_state = A2;
	}

	void A2o()
	{
		if (current_value != EQ)
		{
			++error_counter;
			G1b();
		}
		else
			A2b();

		current_state = A2;
	}

	void A2p()
	{
		if (relation_value_reg == LESS)
		{
			switch (current_value)
			{
			case EQ:
				relation_value_reg = LEQ;
				break;
			case GREATER:
				relation_value_reg = NEQ;
				break;
			}
		}
		else if (relation_value_reg == GREATER && current_value == EQ)
			relation_value_reg = GEQ;
		//else
		//{
		//	////////////////////////////////////////////////////////
		//	////////////////////////////////////////////////////////


		//}

		current_state = A2;
	}

	void A2q()
	{
		lex_class_reg = END;
		A2b();

		current_state = A2;
	}

	void A2r()
	{
		lex_class_reg = IF;
		A2b();

		current_state = A2;
	}

	void A2s()
	{
		lex_class_reg = RETURN;
		A2b();

		current_state = A2;
	}

	void A2t()
	{
		lex_class_reg = STEP;
		A2b();

		current_state = A2;
	}

	void A2u()
	{
		lex_class_reg = FOR;
		A2b();

		current_state = A2;
	}

	/*void A3a()
	{
		current_value = (current_value + 1) * 26;

	}*/

	void A3b()
	{
		lex_class_reg = RBRACE;
		CreateToken();

		current_state = A3;
	}

	void A3c()
	{
		CreateToken();
		current_state = A3;
	}

	void A3d()
	{
		DA1D();
		current_state = A3;
	}

	void A3e()
	{
		DA2D();
		A3c();

		current_state = A3;
	}

	void A3f()
	{
		DA3D();
		A3c();

		current_state = A3;
	}

	void A3g()
	{
		DA1E();
		A3c();

		current_state = A3;
	}

	void B1a()
	{
		detection_reg = start_vector.rob[current_value];

		if (!detection_reg)
		{
			++error_counter;
			G1b();
		}

		current_state = B1;
	}

	void B1b()
	{
		CreateToken();
		current_state = B1;
	}

	void B1c()
	{
		DA3D();
		current_state = B1;
	}

	void B1d()
	{
		++detection_reg;
		current_state = B1;
	}

	void B1e()
	{
		DA1E();
		B1b();

		current_state = B1;
	}

	void C1a()
	{
		lex_class_reg = CYCLE_END;
		current_state = C1;
	}

	void C2a()
	{
		lex_class_reg = OPERAND;
		current_state = C2;
	}

	/*void C2d()
	{

	}*/

	void D1a()
	{
		lex_class_reg = OPERAND;
		number_reg = current_value;

		current_state = D1;
	}

	void D1b()
	{
		number_reg *= 10;
		number_reg += current_value;

		current_state = D1;
	}

	void D2a()
	{
		++counter_reg;
		number_reg *= 10;
		number_reg += current_value;

		current_state = D2;
	}

	void D2b()
	{
		counter_reg = 1;
		current_value = number_reg;

		current_state = D2;
	}

	void D2c()
	{
		counter_reg = 0;
		current_state = D2;
	}

	void D3a()
	{
		counter_reg = 0;
		current_state = D3;
	}

	void D4a()
	{
		if (current_value == 1)
			order_reg = 1;
		else if (current_value == -1)
			order_reg = -1;
		else
		{
			++error_counter;
			current_state = G1b;
		}

		current_state = D4;
	}

	void D5a()
	{
		order_reg = 1;
		current_state = D5;
	}

	void D5b()
	{

	}