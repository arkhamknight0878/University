#pragma once

#include <vector>

enum RK
{
	Letter,
	Digit,
	Ar_oper,
	Attitude,
	Left_bracket,
	Right_bracket,
	Point,
	Space,
	CR,
	EndFile,
	Other
};

enum RKL
{
	ROWLABEL = 1,
	OPERAND,
	ATTITUDE,
	NEXT,
	LET,
	FOR,
	GOTO,
	GOSUB,
	LEFT,
	BRACKET,
	RIGHT,
	BRACKET,
	IF,
	RETURN,
	END,
	TO,
	STEP,
	REM,
	ERROR,
	ENDFILE,
	AR,
	OPER
};

enum ArithOperator
{
	ADD = 1, SUB, MULT, DIV, MOD
};

enum AssociaiveOperator
{
	EQ = 1, LESS, GREATER, LEQ, GEQ, NEQ
};

struct Token
{
	int TokenClass;
	int TokenValue;
};