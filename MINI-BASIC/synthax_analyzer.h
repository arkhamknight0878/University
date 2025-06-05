#ifndef SYNTHAX_ANALYZER_H
#define SYNTHAX_ANALYZER_H

#include "lexical_analyzer.h"

#include <stack>
#include <string>

struct atom
{
	int atom_type;	// Тип атома
	int atr1;		// Атрибут 1
	int atr2;		// Атрибут 2
	int atr3;		// Атрибут 3
	int atr4;		// Атрибут 4
};

class synthax_analyzer : public lexical_analyzer
{
protected:
	typedef void(synthax_analyzer::* fptr)();
	fptr T[20][24];			// Упраляющая таблица

	int TM[512];			// Таблица меток
	std::stack<int> stk;
	int in;					// Вход
	int machine_ch;			// Магазинный символ
	int str_num;			// Номер строки
	int NTM;				// Индекс первого свободного элемента в таблице меток

	void print_TA();

	void show_stack();
public:
	atom TA[512];			// Таблица атомов
	int TX[512];			// Таблица результатов атома хранения
	int NTA;				// Индекс первого свободного эелемента в таблице атомов
	int NTX;				// Индекс первого свободного эелемента в таблице результатов атома хранения
	int NTtemp;				// Индекс первого свободного элемента в таблице промежуточных результатов
	bool error_flag;		// Флаг ошибки

	synthax_analyzer();

	void create_atom(int type_, int atr1_ = -1, int atr2_ = -1, int atr3_ = -1, int atr4_ = -1);

	void error(std::string error_str_);

	void next();

	void start(const char* file_name_);

	void F1();

	void F2();

	void F3();

	void F4();

	void F5();

	void F6();

	void F7();

	void F8();

	void F9();

	void F10();

	void F11();

	void F12();

	void F13();

	void F14();

	void F15();

	void F16();

	void F17();

	void F18();

	void F19();

	void F20();

	void F21();

	void F22();

	void F23();

	void F24();

	void F25();

	void F26();

	void F27();

	void F28();

	void a();

	void b();

	void c();

	void d();

	void e();

	void f();

	void g();

	void h();

	void i();

	void j();

	void k();

	void l();

	void m();

	void n();

	void o();

	void p();

	void q();

	void r();

	void A();

	void B();

	void G1();

	void G2();

	void C();

	void D();

	void K1();

	void K2();

	void K3();

	void K4();

	void K5();

	void K6();

	void K7();

	void E1();

	void E2();

	void E3();

	void L();

	void M1();

	void M2();

	void M3();

	void M4();

	void H1();

	void H2();

	void K();

	void P1();

	void P2();

	void P3();

	void P4();

	void P();

	void T1();

	void T2();

	void T3();

	void O();
};

#endif