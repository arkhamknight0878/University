#include "synthax_analyzer.h"

void synthax_analyzer::next() { ++in; }

void synthax_analyzer::start(const std::string& file_name_)
{
	lexical_analyzer::start(file_name_);
	NTtemp = NTO;
	NTX = 700;
	NTM = 256;
	for (int i = 0; i < NTL; ++i)
	{
		if (TL[i].TokenClass == 17) TL[i].TokenClass = 22;
		if (TL[i].TokenClass == 18) TL[i].TokenClass = 23;
		if (TL[i].TokenClass == 19) TL[i].TokenClass = 16 + TL[i].TokenValue;
	}

	while (in < NTL)
	{
		mch = stk.top();
		switch (mch)
		{
		case 19:
			d();
			break;
		case 20:
			e();
			break;
		case 21:
			f();
			break;
		case 22:
			g();
			break;
		case 23:
			h();
			break;
		case 24:
			i();
			break;
		case 25:
			j();
			break;
		case 26:
			k();
			break;
		case 27:
			l();
			break;
		case 28:
			m();
			break;
		case 29:
			n();
			break;
		case 30:
			o();
			break;
		case 31:
			p();
			break;
		case 32:
			q();
			break;
		case 33:
			r();
			break;
		default:
			(this->*T[mch][TL[in].TokenClass])();
		}
	}

	print_TA();
}

void synthax_analyzer::A()	{ error("Ошибка: Программа начинается неверно."); }

void synthax_analyzer::B()	{ error("Ошибка: Оператор начинается неверно."); }

void synthax_analyzer::G1() { error("Ошибка: Неожиданный вход после for-оператора."); }

void synthax_analyzer::G2() { error("Ошибка: Лишняя правая скобка в выражении после TO."); }

void synthax_analyzer::C()	{ error(" "); }

void synthax_analyzer::D()	{ error("Ошибка: Неожиданный вход после оператора."); }

void synthax_analyzer::K1() { error("Ошибка: Отсутсвует операнд в выражении."); }

void synthax_analyzer::K2() { error("Ошибка: Операнд не был закончен."); }

void synthax_analyzer::K3() { error("Ошибка: Пропущен операнд в выражении."); }

void synthax_analyzer::K4() { error("Ошибка: Неожиданный вход после выражения."); }

void synthax_analyzer::K5() { error("Ошибка: Выражение начинается с входа."); }

void synthax_analyzer::K6() { error("Ошибка: Два знака операции в выражении."); }

void synthax_analyzer::K7() { error("Ошибка: В выражении пропущен знак операции."); }

void synthax_analyzer::E1() { error("Ошибка: Неожиданный вход в if-операторе."); }

void synthax_analyzer::E2() { error("Ошибка: if-оператор не закончен."); }

void synthax_analyzer::E3() { error("Ошибка: Лишняя правая скобка в выражении после if."); }

void synthax_analyzer::L()	{ error("Ошибка: Неверное вложение for-операторов. Был пропущен next"); }

void synthax_analyzer::M1() { error("Ошибка: Неожиданный вход в if-операторе."); }

void synthax_analyzer::M2() { error("Ошибка: оператор не был закончен."); }

void synthax_analyzer::M3() { error("Ошибка: Два знака отношения в if-операторе."); }

void synthax_analyzer::M4() { error("Ошибка: Лишняя правая скобка в выражении после знака отношения."); }

void synthax_analyzer::H1() { error("Ошибка: Пропущена правая скобка перед входом."); }

void synthax_analyzer::H2() { error("Ошибка: Пропущена правая скобка в конце строки."); }

void synthax_analyzer::K()	{ error("Ошибка: Неверное вложение for-операторов. Лишнее next"); }

void synthax_analyzer::P1() { error("Ошибка: Неожиданный вход в for-операторе."); }

void synthax_analyzer::P2() { error("Ошибка: for-оператор не был закончен."); }

void synthax_analyzer::P3() { error("Ошибка: Лишная правая скобка в выражении после to."); }

void synthax_analyzer::P4() { error("Ошибка: Ношибочный синтаксис for-оператора. to отсутствует или стоит недопустимом месте."); }

void synthax_analyzer::P()	{ error("Ошибка: Программа продолжает работу после end оператора."); }

void synthax_analyzer::T1() { error("Ошибка: Программа отсутствует."); }

void synthax_analyzer::T2() { error("Ошибка: Был пропущен end."); }

void synthax_analyzer::T3() { error("Ошибка: Программа ончается посреди оператора."); }

void synthax_analyzer::O()	{ error("Ошибка компилятора."); }

void synthax_analyzer::F11()
{
	TO[NTO] = 1;
	stk.pop(); stk.pop();
	
	int tmp = stk.top(); stk.pop(); stk.pop();

	stk.push(TO[NTO]);
	stk.push(tmp);
}

void synthax_analyzer::F12()
{
	stk.pop();
	stk.push(4);
	++in;
}

void synthax_analyzer::F13()
{
	stk.pop();
	stk.push(2);

	create_atom(2, TL[in].TokenValue);

	num_str = TS.geg_label(TL[in].TokenValue);

	++in;
}

void synthax_analyzer::F14()
{
	stk.pop();
	stk.push(0);
	stk.push(9);
	stk.push(2);
	stk.push(6);
}

void synthax_analyzer::F15()
{
	stk.pop();
	stk.push(NTtemp);
	stk.push(9);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(32);
	stk.push(2);
	stk.push(6);

	++NTtemp;
	++in;
}

void synthax_analyzer::F16()
{
	stk.pop();
	stk.push(NTtemp);
	stk.push(9);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(33);
	stk.push(2);
	stk.push(6);

	++NTtemp;
	++in;
}

void synthax_analyzer::F17()
{
	stk.pop();

	int tmp = stk.top(); stk.pop();

	stk.push(NTtemp);
	stk.push(9);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(tmp);
	stk.push(27);
	stk.push(3);
	stk.push(6);

	++NTtemp;
	++in;
}

void synthax_analyzer::F18()
{
	stk.pop();

	int tmp = stk.top(); stk.pop();

	stk.push(NTtemp);
	stk.push(9);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(tmp);
	stk.push(28);
	stk.push(3);
	stk.push(6);

	++NTtemp;
	++in;
}

void synthax_analyzer::F19()
{
	stk.pop();

	int tmp	 = stk.top();	  stk.pop();
	int tmp2 = stk.top() - 1; stk.pop();

	std::stack<int> stack_tmp;

	while (tmp2)
	{
		stack_tmp.push(stk.top()); stk.pop();
		--tmp2;
	}
	while (stk.top())
	{
		stack_tmp.push(stk.top());
		stk.pop();
	}

	stk.pop();
	stk.push(tmp);

	while (!stack_tmp.empty())
	{
		stk.push(stk.top());
		stack_tmp.pop();
	}
}
