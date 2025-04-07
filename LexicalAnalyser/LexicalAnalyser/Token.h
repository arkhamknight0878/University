#pragma once

#include <vector>

extern std::vector<Token> tokens_table;

enum TokenClass
{
	DIGIT, LETTER, SPACE, LF, DOT, LABEL, OPERAND, ARITH_OPER, RELATION_OPER, NEXT, LET, FOR, GOTO, GOSUB, LBRACE, RBRACE, IF, RETURN, END, TO, STEP, REM, ERROR, FILE_END, CYCLE_END
};

enum ArithOper
{
	ADD = 1, SUB, MULT, DIV, POW
};

enum RelationOper
{
	EQ = 1, LESS, GREATER, LEQ, GEQ, NEQ
};

struct Token
{
	int token_class;
	int token_value;
};