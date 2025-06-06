#include "synthax_analyzer.h"

#include <iomanip>

void synthax_analyzer::A() { error("Ошибка: Программа начинается неверно."); }

void synthax_analyzer::B() { error("Ошибка: Оператор начинается неверно."); }

void synthax_analyzer::G1() { error("Ошибка: Неожиданный вход после for-оператора."); }

void synthax_analyzer::G2() { error("Ошибка: Лишняя правая скобка в выражении после TO."); }

void synthax_analyzer::C() { error(" "); }

void synthax_analyzer::D() { error("Ошибка: Неожиданный вход после оператора."); }

void synthax_analyzer::K1() { error("Ошибка: Недопустимый вид записи выражения. Нет операнда."); }

void synthax_analyzer::K2() { error("Ошибка: Оператор незакончен."); }

void synthax_analyzer::K3() { error("Ошибка: В выражении пропущен операнд."); }

void synthax_analyzer::K4() { error("Ошибка: Неожиданный вход после выражения."); }

void synthax_analyzer::K5() { error("Ошибка: Выражение начинается с вход."); }

void synthax_analyzer::K6() { error("Ошибка: Два знака операции в выражении."); }

void synthax_analyzer::K7() { error("Ошибка: В выражении пропущен знак операции."); }

void synthax_analyzer::E1() { error("Ошибка: Неожиданный вход в if-операторе."); }

void synthax_analyzer::E2() { error("Ошибка: if-оператор незакончен."); }

void synthax_analyzer::E3() { error("Ошибка: Лишняя правая скобка в выражении после if."); }

void synthax_analyzer::L() { error("Ошибка: Неверное вложение for-операторов. Был пропущен next."); }

void synthax_analyzer::M1() { error("Ошибка: Неожиданный вход в if-операторе."); }

void synthax_analyzer::M2() { error("Ошибка: if-оператор незакончен."); }

void synthax_analyzer::M3() { error("Ошибка: Два знака отношения в if-операторе."); }

void synthax_analyzer::M4() { error("Ошибка: Лишняя правая скобка в выражении после знака отношения."); }

void synthax_analyzer::H1() { error("Ошибка: Пропущена правая скобка перед вход."); }

void synthax_analyzer::H2() { error("Ошибка: Пропущена правая скобка в конце строки."); }

void synthax_analyzer::K() { error("Ошибка: Неверное вложение for-операторов. Встречен лишний next"); }

void synthax_analyzer::P1() { error("Ошибка: Неожиданный вход в for-операторе."); }

void synthax_analyzer::P2() { error("Ошибка: for-оператор незакончен."); }

void synthax_analyzer::P3() { error("Ошибка: Лишняя правая скобка в выражении после to."); }

void synthax_analyzer::P4() { error("Ошибка: Неверное построение for-оператора. to пропущено или не на своём месте."); }

void synthax_analyzer::P() { error("Ошибка: Программа продолжается после end-оператора."); }

void synthax_analyzer::T1() { error("Ошибка: Нет программы."); }

void synthax_analyzer::T2() { error("Ошибка: Пропущен end-оператор."); }

void synthax_analyzer::T3() { error("Ошибка: Программа кончается посреди оператора."); }

void synthax_analyzer::O() { error("Ошибка: Ошибка компилятора."); }

synthax_analyzer::synthax_analyzer()
{
	stk.push(18);
	stk.push(1);
	NTA = 0;
	in = 1;
	NTX = NTM = 1;
	str_num = 0;
	error_flag = false;

	// Строка 1
	T[1][1] = &synthax_analyzer::F1;

	for (int i = 2; i < 22; ++i)
		T[1][i] = &synthax_analyzer::A;

	T[1][22] = &synthax_analyzer::C;
	T[1][23] = &synthax_analyzer::T1;

	// Строка 2
	T[2][1] = &synthax_analyzer::F3;
	T[2][2] = &synthax_analyzer::B;
	T[2][3] = &synthax_analyzer::B;
	T[2][4] = &synthax_analyzer::F2;
	T[2][5] = &synthax_analyzer::F4;
	T[2][6] = &synthax_analyzer::F9;
	T[2][7] = &synthax_analyzer::F5;
	T[2][8] = &synthax_analyzer::F7;
	T[2][9] = &synthax_analyzer::B;
	T[2][10] = &synthax_analyzer::B;
	T[2][11] = &synthax_analyzer::F6;
	T[2][12] = &synthax_analyzer::F8;
	T[2][13] = &synthax_analyzer::F2;
	T[2][14] = &synthax_analyzer::B;
	T[2][15] = &synthax_analyzer::B;
	T[2][16] = &synthax_analyzer::F12;
	T[2][17] = &synthax_analyzer::B;
	T[2][18] = &synthax_analyzer::B;
	T[2][19] = &synthax_analyzer::B;
	T[2][20] = &synthax_analyzer::B;
	T[2][21] = &synthax_analyzer::B;
	T[2][22] = &synthax_analyzer::C;
	T[2][23] = &synthax_analyzer::T2;

	// Строка 3
	T[3][1] = &synthax_analyzer::F11;

	for (int i = 2; i < 22; ++i)
		T[3][i] = &synthax_analyzer::G1;

	T[3][10] = &synthax_analyzer::G2;
	T[3][15] = &synthax_analyzer::F10;
	T[3][16] = &synthax_analyzer::G1;
	T[3][22] = &synthax_analyzer::C;
	T[3][23] = &synthax_analyzer::T2;

	// Строка 4
	T[4][1] = &synthax_analyzer::F13;

	for (int i = 2; i < 22; ++i)
		T[4][i] = &synthax_analyzer::D;

	T[4][16] = &synthax_analyzer::D;
	T[4][22] = &synthax_analyzer::C;
	T[4][23] = &synthax_analyzer::T2;

	// Строка 5
	T[5][1] = &synthax_analyzer::K2;
	T[5][2] = &synthax_analyzer::F14;
	T[5][3] = &synthax_analyzer::K1;
	T[5][4] = &synthax_analyzer::K4;
	T[5][5] = &synthax_analyzer::K4;
	T[5][6] = &synthax_analyzer::K4;
	T[5][7] = &synthax_analyzer::K1;
	T[5][8] = &synthax_analyzer::K4;
	T[5][9] = &synthax_analyzer::F14;
	T[5][10] = &synthax_analyzer::K3;
	T[5][11] = &synthax_analyzer::K4;
	T[5][12] = &synthax_analyzer::K4;
	T[5][13] = &synthax_analyzer::K4;
	T[5][14] = &synthax_analyzer::K1;
	T[5][15] = &synthax_analyzer::K1;
	T[5][16] = &synthax_analyzer::K4;
	T[5][17] = &synthax_analyzer::F15;
	T[5][18] = &synthax_analyzer::F16;
	T[5][19] = &synthax_analyzer::K5;
	T[5][20] = &synthax_analyzer::K5;
	T[5][21] = &synthax_analyzer::K5;
	T[5][22] = &synthax_analyzer::C;
	T[5][23] = &synthax_analyzer::T3;

	// Строка 6
	T[6][1]  = &synthax_analyzer::K2;
	T[6][2]  = &synthax_analyzer::F20;
	T[6][3]  = &synthax_analyzer::K1;
	T[6][4]  = &synthax_analyzer::K4;
	T[6][5]  = &synthax_analyzer::K4;
	T[6][6]  = &synthax_analyzer::K4;
	T[6][7]  = &synthax_analyzer::K1;
	T[6][8]  = &synthax_analyzer::K4;
	T[6][9]  = &synthax_analyzer::F20;
	T[6][10] = &synthax_analyzer::K3;
	T[6][11] = &synthax_analyzer::K4;
	T[6][12] = &synthax_analyzer::K4;
	T[6][13] = &synthax_analyzer::K4;
	T[6][14] = &synthax_analyzer::K1;
	T[6][15] = &synthax_analyzer::K1;
	T[6][16] = &synthax_analyzer::K4;
	T[6][17] = &synthax_analyzer::K6;
	T[6][18] = &synthax_analyzer::K6;
	T[6][19] = &synthax_analyzer::K6;
	T[6][20] = &synthax_analyzer::K6;
	T[6][21] = &synthax_analyzer::K6;
	T[6][22] = &synthax_analyzer::C;
	T[6][23] = &synthax_analyzer::T3;

	// Строка 7
	T[7][1]  = &synthax_analyzer::K2;
	T[7][2]  = &synthax_analyzer::F24;
	T[7][3]  = &synthax_analyzer::K1;
	T[7][4]  = &synthax_analyzer::K4;
	T[7][5]  = &synthax_analyzer::K4;
	T[7][6]  = &synthax_analyzer::K4;
	T[7][7]  = &synthax_analyzer::K1;
	T[7][8]  = &synthax_analyzer::K4;
	T[7][9]  = &synthax_analyzer::F24;
	T[7][10] = &synthax_analyzer::K3;
	T[7][11] = &synthax_analyzer::K4;
	T[7][12] = &synthax_analyzer::K4;
	T[7][13] = &synthax_analyzer::K4;
	T[7][14] = &synthax_analyzer::K1;
	T[7][15] = &synthax_analyzer::K1;
	T[7][16] = &synthax_analyzer::K4;
	T[7][17] = &synthax_analyzer::K6;
	T[7][18] = &synthax_analyzer::K6;
	T[7][19] = &synthax_analyzer::K6;
	T[7][20] = &synthax_analyzer::K6;
	T[7][21] = &synthax_analyzer::K6;
	T[7][22] = &synthax_analyzer::C;
	T[7][23] = &synthax_analyzer::T3;

	// Строка 8
	T[8][1]  = &synthax_analyzer::K2;
	T[8][2]  = &synthax_analyzer::F28;
	T[8][3]  = &synthax_analyzer::K1;
	T[8][4]  = &synthax_analyzer::K4;
	T[8][5]  = &synthax_analyzer::K4;
	T[8][6]  = &synthax_analyzer::K4;
	T[8][7]  = &synthax_analyzer::K1;
	T[8][8]  = &synthax_analyzer::K4;
	T[8][9]  = &synthax_analyzer::F27;
	T[8][10] = &synthax_analyzer::K3;
	T[8][11] = &synthax_analyzer::K4;
	T[8][12] = &synthax_analyzer::K4;
	T[8][13] = &synthax_analyzer::K4;
	T[8][14] = &synthax_analyzer::K1;
	T[8][15] = &synthax_analyzer::K1;
	T[8][16] = &synthax_analyzer::K4;
	T[8][17] = &synthax_analyzer::K6;
	T[8][18] = &synthax_analyzer::K6;
	T[8][19] = &synthax_analyzer::K6;
	T[8][20] = &synthax_analyzer::K6;
	T[8][21] = &synthax_analyzer::K6;
	T[8][22] = &synthax_analyzer::C;
	T[8][23] = &synthax_analyzer::T3;

	// Строка 9
	T[9][1]  = &synthax_analyzer::F19;
	T[9][2]  = &synthax_analyzer::K7;
	T[9][3]  = &synthax_analyzer::F19;
	T[9][4]  = &synthax_analyzer::O;
	T[9][5]  = &synthax_analyzer::O;
	T[9][6]  = &synthax_analyzer::O;
	T[9][7]  = &synthax_analyzer::F19;
	T[9][8]  = &synthax_analyzer::O;
	T[9][9]  = &synthax_analyzer::K7;
	T[9][10] = &synthax_analyzer::F19;
	T[9][11] = &synthax_analyzer::O;
	T[9][12] = &synthax_analyzer::O;
	T[9][13] = &synthax_analyzer::O;
	T[9][14] = &synthax_analyzer::F19;
	T[9][15] = &synthax_analyzer::F19;
	T[9][16] = &synthax_analyzer::O;
	T[9][17] = &synthax_analyzer::F17;
	T[9][18] = &synthax_analyzer::F18;
	T[9][19] = &synthax_analyzer::O;
	T[9][20] = &synthax_analyzer::O;
	T[9][21] = &synthax_analyzer::O;
	T[9][22] = &synthax_analyzer::O;
	T[9][23] = &synthax_analyzer::O;

	// Строка 10
	T[10][1]  = &synthax_analyzer::F23;
	T[10][2]  = &synthax_analyzer::K7;
	T[10][3]  = &synthax_analyzer::F23;
	T[10][4]  = &synthax_analyzer::O;
	T[10][5]  = &synthax_analyzer::O;
	T[10][6]  = &synthax_analyzer::O;
	T[10][7]  = &synthax_analyzer::F23;
	T[10][8]  = &synthax_analyzer::O;
	T[10][9]  = &synthax_analyzer::K7;
	T[10][10] = &synthax_analyzer::F23;
	T[10][11] = &synthax_analyzer::O;
	T[10][12] = &synthax_analyzer::O;
	T[10][13] = &synthax_analyzer::O;
	T[10][14] = &synthax_analyzer::F23;
	T[10][15] = &synthax_analyzer::F23;
	T[10][16] = &synthax_analyzer::O;
	T[10][17] = &synthax_analyzer::F23;
	T[10][18] = &synthax_analyzer::F23;
	T[10][19] = &synthax_analyzer::F21;
	T[10][20] = &synthax_analyzer::F22;
	T[10][21] = &synthax_analyzer::O;
	T[10][22] = &synthax_analyzer::O;
	T[10][23] = &synthax_analyzer::O;

	// Строка 11
	T[11][1]  = &synthax_analyzer::F26;
	T[11][2]  = &synthax_analyzer::K7;
	T[11][3]  = &synthax_analyzer::F26;
	T[11][4]  = &synthax_analyzer::K4;
	T[11][5]  = &synthax_analyzer::K4;
	T[11][6]  = &synthax_analyzer::K4;
	T[11][7]  = &synthax_analyzer::F26;
	T[11][8]  = &synthax_analyzer::K4;
	T[11][9]  = &synthax_analyzer::K7;
	T[11][10] = &synthax_analyzer::F26;
	T[11][11] = &synthax_analyzer::K4;
	T[11][12] = &synthax_analyzer::K4;
	T[11][13] = &synthax_analyzer::K4;
	T[11][14] = &synthax_analyzer::F26;
	T[11][15] = &synthax_analyzer::F26;
	T[11][16] = &synthax_analyzer::K4;
	T[11][17] = &synthax_analyzer::F26;
	T[11][18] = &synthax_analyzer::F26;
	T[11][19] = &synthax_analyzer::F26;
	T[11][20] = &synthax_analyzer::F26;
	T[11][21] = &synthax_analyzer::F25;
	T[11][22] = &synthax_analyzer::C;
	T[11][23] = &synthax_analyzer::T2;

	// Строка 12
	T[12][1] = &synthax_analyzer::E2;

	for (int i = 2; i < 22; ++i)
		T[12][i] = &synthax_analyzer::E1;

	T[12][3]  = &synthax_analyzer::b;
	T[12][16] = &synthax_analyzer::E1;
	T[12][22] = &synthax_analyzer::C;
	T[12][23] = &synthax_analyzer::T2;

	// Строка 13
	for (int i = 1; i < 24; ++i)
		T[13][i] = &synthax_analyzer::O;

	T[13][4]  = &synthax_analyzer::b;
	T[13][13] = &synthax_analyzer::L;
	T[13][16] = &synthax_analyzer::O;

	// Строка 14
	T[14][1] = &synthax_analyzer::M2;

	for (int i = 2; i < 22; ++i)
		T[14][i] = &synthax_analyzer::M1;

	T[14][3]  = &synthax_analyzer::M3;
	T[14][7]  = &synthax_analyzer::b;
	T[14][16] = &synthax_analyzer::M1;
	T[14][22] = &synthax_analyzer::c;
	T[14][23] = &synthax_analyzer::T3;

	// Строка 15
	T[15][1] = &synthax_analyzer::H2;

	for (int i = 2; i < 22; ++i)
		T[15][i] = &synthax_analyzer::H1;

	T[15][10] = &synthax_analyzer::a;
	T[15][16] = &synthax_analyzer::H1;
	T[15][22] = &synthax_analyzer::c;
	T[15][23] = &synthax_analyzer::T3;

	// Строка 16
	for (int i = 1; i < 24; ++i)
		T[16][i] = &synthax_analyzer::O;

	T[16][4]  = &synthax_analyzer::K;
	T[16][13] = &synthax_analyzer::a;
	T[16][16] = &synthax_analyzer::O;

	// Строка 17
	T[17][1] = &synthax_analyzer::P1;

	for (int i = 2; i < 22; ++i)
		T[17][i] = &synthax_analyzer::P1;

	T[17][10] = &synthax_analyzer::P3;
	T[17][14] = &synthax_analyzer::a;
	T[17][15] = &synthax_analyzer::P4;
	T[17][16] = &synthax_analyzer::P1;
	T[17][22] = &synthax_analyzer::c;
	T[17][23] = &synthax_analyzer::T3;

	// Строка 18
	for (int i = 1; i < 23; ++i)
		T[18][i] = &synthax_analyzer::P;

	T[18][16] = &synthax_analyzer::P;
	T[18][23] = &synthax_analyzer::c;
}

void synthax_analyzer::error(std::string errMsg)
{
	std::ofstream errors_file("errors.txt");

	errors_file << "OШИБКА: Строка " << str_num << ' ' << errMsg;
	error_flag = true;

	if (TL[in].token_class == 23) ++in;
	else
	{
		while (in < TL.size() && TL[in].token_class != 1)
			++in;
	}

	if (stk.top() == 1 || stk.top() == 2 || stk.top() == 4)
		return;
	else if (stk.top() == 16 || stk.top() == 18)
	{
		stk.pop();
		stk.push(2);
	}
	else
	{
		while (stk.top() != 4)
			stk.pop();
	}

	errors_file.close();
}

void synthax_analyzer::next() { ++in; }

void synthax_analyzer::start(const char* file_name_)
{
	lexical_analyzer::start(file_name_);
	NTtemp = NTO;
	NTX = 700;
	NTM = 256;

	Print_table_tokens();

	ofstream fa("Atoms.txt");

	for (int i = 0; i < NTL; ++i)
	{
		if (TL[i].token_class >= 4 && TL[i].token_class <= 17)
			--TL[i].token_class;
		if (TL[i].token_class == 18) TL[i].token_class = 22;
		if (TL[i].token_class == 19) TL[i].token_class = 23;
		if (TL[i].token_class == 3) TL[i].token_class = 16 + TL[i].token_value;
	}

	while (in < NTL)
	{
		machine_ch = stk.top();
		fa << machine_ch << " " << TL[in].token_class << endl;


		PrintStk_in_file(fa);
		PrintTA_in_file(fa);

		fa << endl;
		switch (machine_ch)
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
			(this->*T[machine_ch][TL[in].token_class])();
		}
	}

	print_TA();
}

void synthax_analyzer::create_atom(int type_, int atr1_, int atr2_, int atr3_, int atr4_)
{
	TA[NTA].atom_type = type_;
	TA[NTA].atr1 = atr1_;
	TA[NTA].atr2 = atr2_;
	TA[NTA].atr3 = atr3_;
	TA[NTA].atr4 = atr4_;
	NTA++;
}

void synthax_analyzer::print_TA()
{
	std::ofstream fout("TableAtoms.txt");
	if (!fout)
	{
		std::cout << std::endl << "Не удаётся сохранить таблицу атомов." << std::endl;
		return;
	}

	std::string types[19];
	types[1] = "ОКОНЧАНИЕ";
	types[2] = "HOMCTPOK";
	types[3] = "ПРИСВ";
	types[4] = "ПЕРЕХОД";
	types[5] = "ХРАН ПЕРЕХОД";
	types[6] = "ВОЗВРПЕРЕХОД";
	types[7] = "УСЛПЕРЕХОД";
	types[8] = "ХРАНЕНИЕ";
	types[9] = "METKA";
	types[10] = "ПРОВЕРКА";
	types[11] = "УВЕЛИЧ";
	types[12] = "СЛОЖ";
	types[13] = "ВЫЧИТ";
	types[14] = "УМНОЖ";
	types[15] = "ДЕЛЕН";
	types[16] = "ЭКСП";
	types[17] = "ПЛЮС";
	types[18] = "МИНУС";

	for (int i = 0; i < NTA; ++i)
	{
		fout << std::setw(2) << TA[i].atom_type << " " << std::setw(3) << TA[i].atr1 << " " << std::setw(3) << TA[1].atr2 << " " <<
			std::setw(3) << TA[i].atr2 << " " << std::setw(3) << TA[i].atr3 << " " << std::setw(3) << TA[i].atr4 << std::endl;
	}

	fout.close();
}

void synthax_analyzer::show_stack()
{
	std::stack<int> stack_for_copy;
	int tmp;

	std::cout << "Содержимое стека: ";

	while (!stk.empty())
	{
		tmp = stk.top(); stk.pop();
		stack_for_copy.push(tmp);

		std::cout << std::endl << tmp;
	}

	while (!stack_for_copy.empty())
	{
		tmp = stack_for_copy.top(); stack_for_copy.pop();
		stk.push(tmp);
	}

	std::cout << std::endl;
}

void synthax_analyzer::PrintTA_in_file(ofstream& fa)
{
	fa << "TA" << endl << string(25, '-') << endl;
	for (int i = 0; i < NTA; i++)
	{
		fa << AtomTypeString[TA[i].atom_type];
		if (TA[i].atr1 != -1)
			fa << " " << TA[i].atr1;
		if (TA[i].atr2 != -1)
			fa << " " << TA[i].atr2;
		if (TA[i].atr3 != -1)
			fa << " " << TA[i].atr3;
		if (TA[i].atr4 != -1)
			fa << " " << TA[i].atr4;
		fa << endl << string(25, '-') << endl;
	}
}

void synthax_analyzer::PrintStk_in_file(ofstream& fa)
{
	fa << "Stk" << endl;
	stack<int> temp;
	for (int i = 0; i < stk.size();)
	{
		fa << stk.top() << " " << endl;
		temp.push(stk.top());
		stk.pop();
	}
	for (int i = 0; i < temp.size();)
	{
		stk.push(temp.top());
		temp.pop();
	}
	fa << endl;
}

void synthax_analyzer::F1()
{
	stk.pop();
	stk.push(16);
	stk.push(2);
	create_atom(2, TL[in].token_value);
	str_num = TS[TL[in].token_value];
	++in;
}

void synthax_analyzer::F2()
{
	stk.pop();
	int k = stk.top();
}

void synthax_analyzer::F3()
{
	create_atom(2, TL[in].token_value);
	str_num = TS[TL[in].token_value];
	++in;
}

void synthax_analyzer::F4()
{
	stk.pop();
	stk.push(4);
	stk.push(0);
	stk.push(TL[in].token_value);
	stk.push(19);
	stk.push(3);
	stk.push(5);
	++in;
}

void synthax_analyzer::F5()
{
	stk.pop();
	stk.push(4);
	create_atom(4, TL[in].token_value);
	++in;
}

void synthax_analyzer::F6()
{
	stk.pop();
	stk.push(4);
	stk.push(0);
	stk.push(0);
	stk.push(0);
	stk.push(0);
	stk.push(20);
	stk.push(5);
	stk.push(14);
	stk.push(5);
	stk.push(5);
	stk.push(8);
	stk.push(12);
	stk.push(8);
	stk.push(5);
	++in;
}

void synthax_analyzer::F7()
{
	stk.pop();
	stk.push(4);
	create_atom(5, TL[in].token_value);
	++in;
}

void synthax_analyzer::F8()
{
	stk.pop();
	stk.push(4);
	create_atom(6);
	++in;
}

void synthax_analyzer::F9()
{
	int p, s, t, u, v, y;
	p = TL[in].token_value;// Значение входа
	s = NTX;// Значение поставляемому вызовом процедуры НОВТX
	NTX++;
	t = NTX;// Значение поставляемому другим вызовом процедуры НОВТХ
	NTX++;
	u = NTM;// значение поставляемому вызовом процедуры НОВТАМ
	NTM++;
	v = NTM;//значение поставляемому другим вызовом процедуры НОВТАМ
	NTM++;
	y = str_num;
	stk.pop();
	stk.push(4);
	stk.push(v);
	stk.push(22);
	stk.push(u);
	stk.push(26);
	stk.push(t);
	stk.push(p);
	stk.push(25);
	stk.push(y);
	stk.push(0);
	stk.push(p);
	stk.push(24);
	stk.push(3);
	stk.push(13);
	stk.push(4);
	stk.push(v);
	stk.push(t);
	stk.push(s);
	stk.push(p);
	stk.push(23);
	stk.push(u);
	stk.push(22);
	stk.push(t);
	stk.push(0);
	stk.push(21);
	stk.push(2);
	stk.push(3);
	stk.push(s);
	stk.push(0);
	stk.push(21);
	stk.push(2);
	stk.push(5);
	stk.push(17);
	stk.push(0);
	stk.push(p);
	stk.push(19);
	stk.push(3);
	stk.push(5);
	++in;
}

void synthax_analyzer::F10()
{
	stk.pop();
	stk.push(5);
	++in;
}

void synthax_analyzer::F11()
{
	TO[NTO] = 1;
	stk.pop(); stk.pop();

	int tmp = stk.top(); stk.pop(); stk.pop();

	stk.push((int)TO[NTO]);
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

	create_atom(2, TL[in].token_value);

	str_num = TS[TL[in].token_value];

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

	int tmp = stk.top();	  stk.pop();
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
		stk.push(stack_tmp.top());
		stack_tmp.pop();
	}
}

void synthax_analyzer::F20()
{
	stk.pop();
	stk.push(0);
	stk.push(10);
	stk.push(2);
	stk.push(7);
}

void synthax_analyzer::F21()
{
	stk.pop();

	int tmp = stk.top(); stk.pop();

	stk.push(NTtemp);
	stk.push(10);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(tmp);
	stk.push(29);
	stk.push(3);
	stk.push(7);

	++NTtemp;
	++in;
}

void synthax_analyzer::F22()
{
	stk.pop();

	int tmp = stk.top(); stk.pop();

	stk.push(NTtemp);
	stk.push(10);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(tmp);
	stk.push(30);
	stk.push(3);
	stk.push(7);

	++NTtemp;
	++in;
}

void synthax_analyzer::F23()
{
	stk.pop();

	int tmp  = stk.top();	  stk.pop();
	int tmp2 = stk.top() - 1; stk.pop();

	std::stack<int> tmp_stack;

	while (tmp2)
	{
		tmp_stack.push(stk.top());
		stk.pop();
		--tmp2;
	}

	while (stk.top())
	{
		tmp_stack.push(stk.top());
		stk.pop();
	}

	stk.pop();
	stk.push(tmp);

	while (!tmp_stack.empty())
	{
		stk.push(tmp_stack.top());
		tmp_stack.pop();
	}
}

void synthax_analyzer::F24()
{
	stk.pop();
	stk.push(0);
	stk.push(11);
	stk.push(2);
	stk.push(8);
}

void synthax_analyzer::F25()
{
	stk.pop();

	int tmp  = stk.top(); stk.pop();
	int tmp2 = stk.top();

	stk.push(NTtemp);
	stk.push(11);
	stk.push(NTtemp);
	stk.push(0);
	stk.push(tmp);
	stk.push(31);
	stk.push(3);
	stk.push(8);

	++NTtemp;
	++in;
}

void synthax_analyzer::F26()
{
	stk.pop();

	int tmp  = stk.top();	  stk.pop();
	int tmp2 = stk.top() - 1; stk.pop();

	std::stack<int> tmp_stack;

	while (tmp2)
	{
		tmp_stack.push(stk.top());
		stk.pop();
		--tmp2;
	}

	while (stk.top())
	{
		tmp_stack.push(stk.top());
		stk.pop();
	}

	stk.pop();
	stk.push(tmp);

	while (!tmp_stack.empty())
	{
		stk.push(tmp_stack.top());
		tmp_stack.pop();
	}
}

void synthax_analyzer::F27()
{
	stk.pop();

	int tmp = stk.top(); stk.pop();

	stk.push(15);
	stk.push(tmp);
	stk.push(5);

	++in;
}

void synthax_analyzer::F28()
{
	stk.pop();

	int tmp = stk.top() - 1; stk.pop();

	std::stack<int> tmp_stack;

	while (tmp)
	{
		tmp_stack.push(stk.top());
		stk.pop();
		--tmp;
	}

	while (stk.top())
	{
		tmp_stack.push(stk.top());
		stk.pop();
	}

	stk.pop();
	stk.push(TL[in].token_value);

	while (!tmp_stack.empty())
	{
		stk.push(tmp_stack.top());
		tmp_stack.pop();
	}

	++in;
}

void synthax_analyzer::a()
{
	stk.pop();
	++in;
}

void synthax_analyzer::b()
{
	stk.pop();
	int i = stk.top() - 1;
	stk.pop();
	std::stack<int> tmp;
	while (i != 0)
	{
		tmp.push(stk.top());
		stk.pop();
		i--;
	}
	stk.pop();
	stk.push(TL[in].token_value);
	while (!tmp.empty())
	{
		stk.push(tmp.top());
		tmp.pop();
	}
	++in;
}

void synthax_analyzer::c()
{
	create_atom(1);
	++in;
}

void synthax_analyzer::d()
{
	int k1, k2;
	stk.pop();
	k1 = stk.top();
	stk.pop();
	k2 = stk.top();
	stk.pop();
	create_atom(3, k1, k2);
}

void synthax_analyzer::e()
{
	int p, q, r, s;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	s = stk.top();
	stk.pop();
	create_atom(7, p, q, r, s);

}

void synthax_analyzer::f()
{
	int p, q;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	create_atom(8, p, q);
}

void synthax_analyzer::g()
{
	int p;
	stk.pop();
	p = stk.top();
	stk.pop();
	create_atom(9, p);
}

void synthax_analyzer::h()
{
	int p, q, r, s;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	s = stk.top();
	stk.pop();
	create_atom(10, p, q, r, s);
}

void synthax_analyzer::i()
{
	int k1, k2;
	stk.pop();
	k1 = stk.top();
	stk.pop();
	k2 = stk.top();
	stk.pop();
	if (k1 != k2)
	{
		error("Переменная в next операторе отлична от переменной for оператора");
	}
	stk.pop();
}

void synthax_analyzer::l()
{
	int p, q, r;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	create_atom(12, p, q, r);
}

void synthax_analyzer::j()
{
	int p, q;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	create_atom(11, p, q);
}

void synthax_analyzer::k()
{
	int p;
	stk.pop();
	p = stk.top();
	stk.pop();
	create_atom(4, p);
}

void synthax_analyzer::n()
{
	int p, q, r;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	create_atom(14, p, q, r);
}

void synthax_analyzer::m()
{
	int p, q, r;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	create_atom(13, p, q, r);
}

void synthax_analyzer::o()
{
	int p, q, r;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	create_atom(15, p, q, r);
}

void synthax_analyzer::p()
{
	int p, q, r;
	stk.pop();
	p = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	q = stk.top();
	stk.pop();
	r = stk.top();
	stk.pop();
	create_atom(16, p, q, r);
}

void synthax_analyzer::q()
{
	int k1, k2;
	stk.pop();
	k1 = stk.top();
	stk.pop();
	k2 = stk.top();
	stk.pop();
	create_atom(17, k1, k2);
}

void synthax_analyzer::r()
{
	int k1, k2;
	stk.pop();
	k1 = stk.top();
	stk.pop();
	k2 = stk.top();
	stk.pop();
	create_atom(18, k1, k2);
}