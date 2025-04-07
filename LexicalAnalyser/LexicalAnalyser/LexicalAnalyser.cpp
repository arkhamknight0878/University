#include "LexicalAnalyser.h"

std::vector<Token> tokens_table;
struct StartVector start_vector;
struct TransitionTable transition_table;

void LexicalAnalyser::A1()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = E2a;
		break;
	case SPACE:
		break;
	case LF:
		break;
	case FILE_END:
		current_state = EXIT1;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::A2()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = C2a;
		break;
	case DIGIT:
		current_state = D1a;
		break;
	case ARITH_OPER:
		A2a();
		break;
	case RELATION_OPER:
		current_state = H1a;
		break;
	case LBRACE:
		current_state = A2h;
		break;
	case RBRACE:
		current_state = A3b;
		break;
	case DOT:
		current_state = D6;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1;
		break;
	case FILE_END:
		current_state = EXIT1;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::A3()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = B1a;
		break;
	case DIGIT:
		current_state = D1a;
		break;
	case ARITH_OPER:
		current_state = A2a;
		break;
	case RELATION_OPER:
		current_state = H1a;
		break;
	case LBRACE:
		current_state = A2h;
		break;
	case RBRACE:
		current_state = A3b;
		break;
	case DOT:
		current_state = D6;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1;
		break;
	case FILE_END:
		current_state = EXIT1;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::B1()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = M1;
		break;
	case SPACE:
			break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::C1()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = C2d;
		break;
	case SPACE:
		break;
	case FILE_END:
		current_state = EXIT3;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::C2()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = B1a;
		break;
	case DIGIT:
		current_state = A3a;
		break;
	case ARITH_OPER:
		current_state = A2g;
		break;
	case RELATION_OPER:
		current_state = H1b;
		break;
	case LBRACE:
		current_state = A2k;
		break;
	case RBRACE:
		current_state = A3c;
		break;
	case SPACE:
		break;
	case LF:
		A1a();
		break;
	case FILE_END:
		current_state = EXIT4;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D1()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = M2;
		break;
	case DIGIT:
		current_state = D1b;
		break;
	case ARITH_OPER:
		current_state = A2c;
		break;
	case RELATION_OPER:
		current_state = H1c;
		break;
	case LBRACE:
		current_state = A2l;
		break;
	case RBRACE:
		current_state = A3d;
		break;
	case DOT:
		current_state = D2c;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1b;
		break;
	case FILE_END:
		current_state = EXIT3;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D2()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = M3;
		break;
	case DIGIT:
		current_state = D2a;
		break;
	case ARITH_OPER:
		current_state = A2d;
		break;
	case RELATION_OPER:
		current_state = H1d;
		break;
	case LBRACE:
		current_state = A2m;
		break;
	case RBRACE:
		current_state = A3e;
		break;
	case SPACE:
		break;
	case LF:
		A1c();
		break;
	case FILE_END:
		current_state = EXIT4;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D3()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = D5a;
		break;
	case ARITH_OPER:
		current_state = D4a;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D4()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = D5b;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D5()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = B1c;
		break;
	case DIGIT:
		current_state = D5c;
		break;
	case ARITH_OPER:
		current_state = A2e;
		break;
	case RELATION_OPER:
		current_state = H1c;
		break;
	case LBRACE:
		current_state = A2n;
		break;
	case RBRACE:
		current_state = A3f;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1d;
		break;
	case FILE_END:
		current_state = EXIT5;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::D6()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = D2b;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::E1()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = E2b;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::E2()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = B1e;
		break;
	case DIGIT:
		current_state = E2c;
		break;
	case ARITH_OPER:
		current_state = A2f;
		break;
	case RELATION_OPER:
		current_state = H1f;
		break;
	case LBRACE:
		current_state = A2j;
		break;
	case RBRACE:
		current_state = A3g;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1e;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::F1()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = F2a;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::F2()
{
	switch (char_class_value_reg)
	{
	case DIGIT:
		current_state = F3a;
		break;
	case RELATION_OPER:
		current_state = A2o;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::F3()
{
	switch (char_class_value_reg)
	{
	case RELATION_OPER:
		current_state = A2o;
		break;
	case SPACE:
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::G1()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		break;
	case DIGIT:
		break;
	case ARITH_OPER:
		break;
	case RELATION_OPER:
		break;
	case LBRACE:
		break;
	case RBRACE:
		break;
	case DOT:
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1;
		break;
	case FILE_END:
		current_state = EXIT1;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::H1()
{
	switch (char_class_value_reg)
	{
	case LETTER:
		current_state = C2b;
		break;
	case DIGIT:
		current_state = D1c;
		break;
	case ARITH_OPER:
		current_state = A2g;
		break;
	case RELATION_OPER:
		current_state = A2p;
		break;
	case LBRACE:
		current_state = A2k;
		break;
	case RBRACE:
		current_state = A3c;
		break;
	case DOT:
		current_state = D6a;
		break;
	case SPACE:
		break;
	case LF:
		current_state = A1a;
		break;
	case FILE_END:
		current_state = EXIT2;
		break;
	default:
		++error_counter;
		current_state = G1b;
	}
}

void LexicalAnalyser::M1() { return s_M1; }

void LexicalAnalyser::M2() { return s_M2; }

void LexicalAnalyser::M3() { return s_M3; }

void LexicalAnalyser::EXIT1() { return s_EXIT1; }

void LexicalAnalyser::EXIT2() { return s_EXIT2; }

void LexicalAnalyser::EXIT3() { return s_EXIT3; }

void LexicalAnalyser::EXIT4() { return s_EXIT4; }

void LexicalAnalyser::EXIT5() { return s_EXIT5; }

void LexicalAnalyser::EXIT6() { return s_EXIT6; }

void LexicalAnalyser::DA1D()
{
}


