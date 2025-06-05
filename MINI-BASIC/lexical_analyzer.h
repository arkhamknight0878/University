#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include "detection_table.h"
#include "hash.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum RK { Letter, Digit, Ar_oper, Rel_oper, Left_brace, Right_brace, Dot, Space, CR, EndFile, Other };

enum RKL { ROWLABEL = 1, OPERAND, REL_OPER, NEXT, LET, FOR, GOTO, GOSUB, LEFT_BRACE, RIGHT_BRACE, IF, RETURN, END, _TO, STEP, REM, _ERROR, ENDFILE, AR_OPER };

struct Token
{
	int token_class;
	int label;
};

class lexical_analyzer
{
protected:
	std::ofstream errors_file;		// Файл oшибок
	detection_table det_table;		// Таблица обнаружения
	std::string input_str;			// Строка входного файла
	std::vector<Token> TL;			// Таблица лексем
	double TO[1024];				// Таблица оперендов
	string_hash TS;					// Таблица строк

	typedef void (lexical_analyzer::* fptr)(); // Укaзатель на функции соссояния;
	fptr transition_ptr;

	int RCH;						// Регистр числа
	int RZ;							// Регистр знака порядка
	int RP;							// Регистр порядка
	int RS;							// Регистр счётчика
	int RKL;						// Регистр класса лексем
	int ROT;						// Регистр значения отношения
	int RZN;						// Регистр значение символа int
	int RSOS;						// Регистр состояния
	int ROB;						// Регистр обнаружения
	int RK;							// Регистр значения класса символа
	int RSTR;						// Регистр строки
	int RI;							// Регистр номера буквы в имени переменной

	int NTL;						// Указатель на первый свободный элемент в TL
	int NTO;						// Указатель на первый свободный элемент в ТО
	int NTS;						// Указатель на первый свободный элемент таблицы строк
	int RSE;						// Регистр счётчика ошибок

	bool is_there_no_E;

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

	void transliterator(char currrent_ch_);

	void parse();

	void end();

	void create_token();

	void write_tokens();

	void write_operands();

	void write_labels();

public:
	lexical_analyzer();

	void start(const char* filename_);

	void next();

	void A1a();
	void A1b();
	void A1c();
	void A1d();
	void A1e();
	void A1f();

	void A2a();
	void A2b();
	void A2c();
	void A2h();
	void A2l();
	void A2g();
	void A2p();
	void A2r();
	void A2k();
	void A2s();
	void A2q();
	void A2o();
	void A2u();
	void A2j();
	void A2f();
	void A2t();

	void A3a();
	void A3b();
	void A3c();
	void A3d();
	void A3g();

	void B1a();
	void B1b();
	void B1c();
	void B1e();

	void C1a();
	void C2a();
	void C2b();
	void C2d();

	void D1a();
	void D1b();
	void D1c();

	void D2a();
	void D2b();
	void D2c();

	void D3a();

	void D4a();

	void D5a();

	void D5b();
	void D5c();

	void D6a();
	void D6b();

	void E1a();
	void E1b();

	void E2a();
	void E2b();
	void E2c();

	void F1a();
	void F1b();

	void F2a();

	void F3a();

	void G1a();
	void G1b();

	void H1a();
	void H1b();
	void H1c();
	void H1f();

	void M1();
	void M2();
	void M3();

	void exit1();
	void exit2();
	void exit3();
	void exit4();
	void exit5();

	void error2();
};

#endif