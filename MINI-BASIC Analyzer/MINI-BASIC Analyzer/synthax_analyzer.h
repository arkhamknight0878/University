#pragma once

#include "lexical_analyzer.h"

#include <stack>
#include <string>

struct atom
{
	int atom_type;
	int atr1;
	int atr2;
	int atr3;
	int atr4;
};

class synthax_analyzer : public lexical_analyzer
{
private:
	typedef void(synthax_analyzer::* fptr)();
	fptr T[20][24];
	int TM[512];
	std::stack<int> stk;
	int in;
	int mch;
	int num_str;
	int NTM;

	void print_TA();

	void show_stack();
public:
	atom TA[512];
	int TX[512];
	int NTA;
	int NTX;
	int NTtemp;
	bool error_flag;

	synthax_analyzer();

	void create_atom(int atr1_, int atr2_, int atr3_, int atr4_);

	void error(std::string error_str_);

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

	void next();

	void start(const std::string& file_name_);

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

