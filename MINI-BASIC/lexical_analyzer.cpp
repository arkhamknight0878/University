#include "lexical_analyzer.h"

lexical_analyzer::lexical_analyzer() : TL(512), errors_file("errors.txt")
{
	for (int i = 0; i < 1024; i++)
		TO[i] = 0;

	transition_ptr = &lexical_analyzer::A1;
	NTO = 287;
	NTL = 1;
	NTS = 1;
	RZ = 1;
	RK = RKL = ROB = ROT = RSOS = RSTR = RZN =  RI = RCH = RP = RS = RSE = 0;
	is_there_no_E = false;
}

void lexical_analyzer::start(const char* filename_)
{
	std::ifstream input(filename_);
	if (!input)
	{
		std::cout << "Ошибка: Не удалось открыть файл." << std::endl;
		return;
	}

	while (!input.eof())
	{
		getline(input, input_str);
		input_str += '\n';
		parse();
	}

	end();
	input.close();
}

void lexical_analyzer::parse()
{
	for (int i = 0; i < input_str.size(); ++i)
	{
		transliterator(input_str[i]);
		(this->*transition_ptr)();
	}
}

void lexical_analyzer::transliterator(char currrent_ch_)
{
	if (currrent_ch_ >= 'a' && currrent_ch_ <= 'z')
	{
		RK = Letter;
		RZN = currrent_ch_ - 'a' + 1;
	}
	else if (currrent_ch_ >= 'A' && currrent_ch_ <= 'Z')
	{
		RK = Letter;
		RZN = currrent_ch_ - 'A' + 1;
	}
	else if (currrent_ch_ >= '0' && currrent_ch_ <= '9')
	{
		RK = Digit;
		RZN = currrent_ch_ - '0';
	}
	else if (currrent_ch_ == '+' || currrent_ch_ == '-' || currrent_ch_ == '*' || currrent_ch_ == '/' || currrent_ch_ == '^')
	{
		RK = Ar_oper;

		switch (currrent_ch_)
		{
		case '+':
			RZN = 1;
			break;
		case '-':
			RZN = 2;
			break;
		case '*':
			RZN = 3;
			break;
		case '/':
			RZN = 4;
			break;
		default:
			RZN = 5;
			break;
		}
	}
	else if (currrent_ch_ == ' ' || currrent_ch_ == '\t')
		RK = Space;
	else if (currrent_ch_ == '.')
		RK = Dot;
	else if (currrent_ch_ == '\n')
		RK = CR;
	else if (currrent_ch_ == '(')
		RK = Left_brace;
	else if (currrent_ch_ == ')')
		RK = Right_brace;
	else if (currrent_ch_ == '<' || currrent_ch_ == '>' || currrent_ch_ == '=')
	{
		RK = Rel_oper;

		switch (currrent_ch_)
		{
		case '=':
			RZN = 1;
			break;
		case '<':
			RZN = 2;
			break;
		default:
			RZN = 3;
			break;
		}
	}
}

void lexical_analyzer::end()
{
	if (transition_ptr == &lexical_analyzer::A1 || transition_ptr == &lexical_analyzer::A2 || transition_ptr == &lexical_analyzer::A3 ||transition_ptr == &lexical_analyzer::G1)
		transition_ptr = &lexical_analyzer::exit1;
	else if (transition_ptr == &lexical_analyzer::C1 || transition_ptr == &lexical_analyzer::D1) transition_ptr = &lexical_analyzer::exit3;
	else if (transition_ptr == &lexical_analyzer::C2 || transition_ptr == &lexical_analyzer::D2) transition_ptr = &lexical_analyzer::exit4;
	else if (transition_ptr == &lexical_analyzer::H1) transition_ptr = &lexical_analyzer::exit2;
	else if (transition_ptr == &lexical_analyzer::D5) transition_ptr = &lexical_analyzer::exit5;
	else transition_ptr = &lexical_analyzer::error2;

	(this->*transition_ptr)();

	write_tokens();
	write_operands();
	write_labels();

	errors_file.close();
}

void lexical_analyzer::create_token()
{
	Token new_token;
	new_token.token_class = RKL;
	new_token.token_value = -1;

	if (RKL == ROWLABEL || RKL == GOTO || RKL == GOSUB)
	{
		TS.insert_element(RSTR, NTL);
		new_token.token_value = TS.hash_function(RSTR) + 1;

		RSTR = 0;
	}
	else if (RKL == OPERAND || RKL == NEXT)
	{
		if (RI)
		{
			int new_token_value;

			if (RK == Digit) new_token_value = RI + 26 * (RZN + 1);
			else			 new_token_value = RI;

			TO[new_token_value] = 1;
			new_token.token_value = new_token_value;
			RI = 0;
		}
		else
		{
			double new_token_value;

			if (RZ == 1)		new_token_value = RCH * pow(10.0, RP - RS);
			else if (RZ == -1)	new_token_value = RCH / pow(10.0, RP + RS);
			else				new_token_value = RCH / pow(10, RS);

			RCH = RP = RS = 0;
			RZ = 1;

			for (int i = 287; i < NTO; i++)
			{
				if (TO[i] == new_token_value)
				{
					new_token.token_value = i;
					TL[NTL] = new_token;
					NTL++;
					return;
				}
			}

			TO[NTO] = new_token_value;
			new_token.token_value = NTO;
			NTO++;
		}
	}
	else if (RKL == LET || RKL == FOR)
	{
		TO[RI] = 1;
		new_token.token_value = RI;
		RI = 0;
	}
	else if (RKL == AR_OPER)
		new_token.token_value = RZN;
	else if (RKL == REL_OPER)
		new_token.token_value = ROT;

	TL[NTL] = new_token;
	NTL++;
}

void lexical_analyzer::A1()
{
	switch (RK)
	{
	case Digit:
		E2a();
		break;
	case Space:
		break;
	case CR:
		break;
	default:
		RSE++;
		G1b();
	}
}

void lexical_analyzer::A2()
{
	switch (RK)
	{
	case Letter:
		C2a();
		break;
	case Digit:
		D1a();
		break;
	case Ar_oper:
		A2a();
		break;
	case Rel_oper:
		H1a();
		break;
	case Left_brace:
		A2h();
		break;
	case Right_brace:
		A3b();
		break;
	case Dot:
		D6b();
		break;
	case Space:
		break;
	case CR:
		transition_ptr = &lexical_analyzer::A1;
		break;
	}
}

void lexical_analyzer::A3()
{
	switch (RK)
	{
	case Letter:
		B1a();
		break;
	case Digit:
		D1a();
		break;
	case Ar_oper:
		A2a();
		break;
	case Rel_oper:
		H1a();
		break;
	case Left_brace:
		A2h();
		break;
	case Right_brace:
		A3b();
		break;
	case Dot:
		D6b();
		break;
	case Space:
	case CR:
		transition_ptr = &lexical_analyzer::A1; break;
		break;
	}
}

void lexical_analyzer::B1()
{
	switch (RK)
	{
	case Letter:
		M1();
		break;
	case Space:
		break;
	case CR:
		A1f();
		break;
	default:
		RSE++;
		G1b();
	}
}

void lexical_analyzer::C1()
{
	switch (RK)
	{
	case Letter:
		C2d();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::C2()
{
	switch (RK)
	{
	case Letter:
		B1b();
		break;
	case Digit:
		A3a();
		break;
	case Ar_oper:
		A2g();
		break;
	case Rel_oper:
		H1b();
		break;
	case Left_brace:
		A2k();
		break;
	case Right_brace:
		A3c();
		break;
	case Space:
		break;
	case CR:
		A1a();
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::D1()
{
	switch (RK)
	{
	case Letter:
		M2();
		break;
	case Digit:
		D1b();
		break;
	case Ar_oper:
		A2c();
		break;
	case Rel_oper:
		H1c();
		break;
	case Left_brace:
		A2l();
		break;
	case Right_brace:
		A3d();
		break;
	case Dot:
		D2c();
		break;
	case Space:
		break;
	case CR:
		A1b();
		break;
	}
}

void lexical_analyzer::D2()
{
	switch (RK)
	{
	case Letter:
		M3();
		break;
	case Digit:
		D2a();
		break;
	case Ar_oper:
		A2c();
		break;
	case Rel_oper:
		H1c();
		break;
	case Left_brace:
		A2l();
		break;
	case Right_brace:
		A3d();
		break;
	case Space:
		break;
	case CR:
		A1c();
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::D3()
{
	switch (RK)
	{
	case Digit:
		D5a();
		break;
	case Ar_oper:
		D4a();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}
void lexical_analyzer::D4()
{
	switch (RK)
	{
	case Digit:
		D5b();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::D5()
{
	switch (RK)
	{
	case Letter:
		B1c();
		break;
	case Digit:
		D5c();
		break;
	case Ar_oper:
		A2c();
		break;
	case Rel_oper:
		H1c();
		break;
	case Left_brace:
		A2l();
		break;
	case Right_brace:
		A3d();
		break;
	case Space:
		break;
	case CR:
		A1d();
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::D6()
{
	switch (RK)
	{
	case Digit:
		D2b();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::E1()
{
	switch (RK)
	{
	case Digit:
		E2b();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}


void lexical_analyzer::E2()
{
	switch (RK)
	{
	case Letter:
		B1e();
		break;
	case Digit:
		E2c();
		break;
	case Rel_oper:
		H1f();
		break;
	case Space:
		break;
	case Ar_oper:
		A2f();
		break;
	case Left_brace:
		A2j();
		break;
	case Right_brace:
		A3g();
		break;
	case CR:
		A1e();
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::F1()
{
	switch (RK)
	{
	case Letter:
		F2a();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::F2()
{
	switch (RK)
	{
	case Digit:
		F3a();
		break;
	case Rel_oper:
		A2o();
		break;
	case Space:
		break;
	default:
		G1b();
	}
}

void lexical_analyzer::F3()
{
	switch (RK)
	{
	case Rel_oper:
		A2o();
	break; case Space:
		break;
	default:
		RSE++;
		G1b();
	}
}

void lexical_analyzer::G1()
{
	switch (RK)
	{
	case CR:
		transition_ptr = &lexical_analyzer::A1;
		break;
	default:
		transition_ptr = &lexical_analyzer::G1;
	}
}

void lexical_analyzer::H1()
{
	switch (RK)
	{
	case Letter:
		C2b();
		break;
	case Digit:
		D1c();
		break;
	case Ar_oper:
		A2g();
		break;
	case Rel_oper:
		A2p();
		break;
	case Left_brace:
		A2k();
		break;
	case Right_brace:
		A3c();
		break;
	case Dot:
		D6a();
		break;
	case Space:
		break;
	case CR:
		A1a();
		break;
	}
}

void lexical_analyzer::write_tokens()
{
	std::ofstream fout("Anilazer_lex_result_LEXEMS.txt");
	if (!fout) throw 1;

	char Tclass[19][15] = { "LABEL", "OPERAND", "REL_OPER", "NEXT", "LET", "FOR", "GOTO", "GOSUB", "LEFT_BRACE", "RIGHT_BRACE", "IF","RETURN", "END", "TO", "STEP", "REM", "ERROR", "END_MARKER", "OPERATION" };

	for (int i = 1; i < NTL; i++)
	{
		fout.width(3);
		fout << i - 1 << "		" << Tclass[TL[i].token_class - 1] << " " << TL[i].token_value << std::endl;
	}

	fout.close();
}

void lexical_analyzer::write_operands()
{
	std::ofstream fout("Anilazer_lex_result_OPERANDS.txt");
	if (!fout) throw 1;

	for (int i = 1; i < 287; ++i)
	{
		fout.width(3);

		if (TO[i]) fout << i << ' ' << TO[i] << std::endl;
	}

	for (int i = 287; i < NTO; ++i)
	{
		fout.width(3);
		fout << i << ' ' << TO[i] << std::endl;
	}

	fout.close();
}

void lexical_analyzer::write_labels()
{
	std::ofstream fout("Anilazer_lex_result_LABELS.txt");
	if (!fout) throw 1;

	for (int i = 0; i < TS.main_area_size; i++)
	{
		if (TS.hash_table[i].token_value == -1 && TS.hash_table[i].alt == 0)
			continue;

		fout << "--------------------------" << std::endl;
		fout << i << "\t | " << TS.hash_table[i].token_value << "\t | " << TS.hash_table[i].alt << "\t | " << std::endl;
	}

	fout << "==========================" << std::endl;
	for (int i = TS.main_area_size; i < TS.table_size; i++)
	{
		if (TS.hash_table[i].token_value == -1 && TS.hash_table[i].alt == 0)
			continue;

		fout << i << "\t | " << TS.hash_table[i].token_value << "\t | " << TS.hash_table[i].alt << "\t | " << std::endl;
		fout << "--------------------------" << std::endl;
	}

	fout.close();
}

void lexical_analyzer::next() { ROB++; }

void lexical_analyzer::A1a()
{
	create_token();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A1b()
{
	RP = 0;
	create_token();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A1c()
{
	create_token();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A1d()
{
	create_token();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A1e()
{
	A1a();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A1f()
{
	RKL = _ERROR;
	create_token();
	transition_ptr = &lexical_analyzer::A1;
}

void lexical_analyzer::A2a()
{
	RKL = AR_OPER;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2b()
{
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2c()
{
	create_token();
	RKL = AR_OPER;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2h()
{
	RKL = LEFT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2l()
{
	create_token();
	RKL = LEFT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2g()
{
	create_token();
	RKL = AR_OPER;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2p()
{
	if (ROT == 2 && RZN == 1) ROT = 4;
	else if (ROT == 3 && RZN == 1) ROT = 5;
	else if (ROT == 2 && RZN == 3) ROT = 6;

	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2r()
{
	RKL = IF;
	A2b();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2k()
{
	create_token();
	RKL = LEFT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2s()
{
	RKL = RETURN;
	A2b();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2q()
{
	RKL = END;
	A2b();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2o()
{
	if (RZN == 1) create_token();
	else
	{
		G1b();
		return;
	}

	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2u()
{
	RKL = _TO;
	A2b();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2j()
{
	create_token();
	RKL = LEFT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2f()
{
	create_token();
	RKL = AR_OPER;
	create_token();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A2t()
{
	RKL = STEP;
	A2b();
	transition_ptr = &lexical_analyzer::A2;
}

void lexical_analyzer::A3a()
{
	create_token();
	transition_ptr = &lexical_analyzer::A3;
}

void lexical_analyzer::A3b()
{
	RKL = RIGHT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A3;
}

void lexical_analyzer::A3c()
{
	create_token();
	RKL = RIGHT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A3;
}

void lexical_analyzer::A3d()
{
	create_token();
	RKL = RIGHT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A3;
}

void lexical_analyzer::A3g()
{
	create_token();
	RKL = RIGHT_BRACE;
	create_token();
	transition_ptr = &lexical_analyzer::A3;
}

void lexical_analyzer::B1a()
{
	ROB = det_table.start_vector[RZN - 1];
	transition_ptr = &lexical_analyzer::B1;
}

void lexical_analyzer::B1b()
{
	create_token();
	ROB = det_table.start_vector[RZN - 1];
	transition_ptr = &lexical_analyzer::B1;
}

void lexical_analyzer::B1c()
{
	create_token();
	ROB = det_table.start_vector[RZN - 1];
	transition_ptr = &lexical_analyzer::B1;
}

void lexical_analyzer::B1e()
{
	create_token();
	ROB = det_table.start_vector[RZN - 1];
	transition_ptr = &lexical_analyzer::B1;
}

void lexical_analyzer::C1a()
{
	RKL = NEXT;
	transition_ptr = &lexical_analyzer::C1;
}

void lexical_analyzer::C2a()
{
	RKL = OPERAND;
	RI = RZN;
	transition_ptr = &lexical_analyzer::C2;
}

void lexical_analyzer::C2b()
{
	create_token();
	RKL = OPERAND;
	RI = RZN;
	transition_ptr = &lexical_analyzer::C2;
}

void lexical_analyzer::C2d()
{
	RI = RZN;
	transition_ptr = &lexical_analyzer::C2;
}

void lexical_analyzer::D1a()
{
	RKL = OPERAND;
	RCH = RZN;
	transition_ptr = &lexical_analyzer::D1;
}

void lexical_analyzer::D1b()
{
	RCH *= 10;
	RCH += RZN;
	transition_ptr = &lexical_analyzer::D1;
}

void lexical_analyzer::D1c()
{
	create_token();
	RKL = OPERAND;
	RCH = RZN;
	transition_ptr = &lexical_analyzer::D1;
}

void lexical_analyzer::D2a()
{
	RS++;
	RCH *= 10;
	RCH += RZN;
	transition_ptr = &lexical_analyzer::D2;
}

void lexical_analyzer::D2b()
{
	RS = 1;
	RCH = RZN;
	transition_ptr = &lexical_analyzer::D2;
}

void lexical_analyzer::D2c()
{
	RS = 0;
	is_there_no_E = true;
	transition_ptr = &lexical_analyzer::D2;
}

void lexical_analyzer::D3a()
{
	RS = 0;
	transition_ptr = &lexical_analyzer::D3;
}

void lexical_analyzer::D4a()
{
	if (RZN == 1) RZ = 1;
	else if (RZN == 2) RZ = -1;

	transition_ptr = &lexical_analyzer::D4;
}

void lexical_analyzer::D5a()
{
	RZ = 1;
	RP = RZN;
	transition_ptr = &lexical_analyzer::D5;
}

void lexical_analyzer::D5b()
{
	RP = RZN;
	transition_ptr = &lexical_analyzer::D5;
}

void lexical_analyzer::D5c()
{
	RP *= 10;
	RP += RZN;
	transition_ptr = &lexical_analyzer::D5;
}

void lexical_analyzer::D6a()
{
	create_token();
	RKL = OPERAND;
	transition_ptr = &lexical_analyzer::D6;
}

void lexical_analyzer::D6b()
{
	RKL = OPERAND;
	transition_ptr = &lexical_analyzer::D6;
}

void lexical_analyzer::E1a()
{
	RKL = GOTO;
	transition_ptr = &lexical_analyzer::E1;
}

void lexical_analyzer::E1b()
{
	RKL = GOSUB;
	transition_ptr = &lexical_analyzer::E1;
}

void lexical_analyzer::E2a()
{
	RKL = ROWLABEL;
	RSTR = RZN;
	transition_ptr = &lexical_analyzer::E2;
}

void lexical_analyzer::E2b()
{
	RSTR = RZN;
	transition_ptr = &lexical_analyzer::E2;
}

void lexical_analyzer::E2c()
{
	RSTR *= 10;
	RSTR += RZN;
	transition_ptr = &lexical_analyzer::E2;
}

void lexical_analyzer::F1a()
{
	RKL = LET;
	transition_ptr = &lexical_analyzer::F1;
}

void lexical_analyzer::F1b()
{
	RKL = FOR;
	transition_ptr = &lexical_analyzer::F1;
}

void lexical_analyzer::F2a()
{
	RI = RZN;
	transition_ptr = &lexical_analyzer::F2;
}

void lexical_analyzer::F3a()
{
	RI += (RZN) * 26;
	transition_ptr = &lexical_analyzer::F3;
}

void lexical_analyzer::G1a()
{
	RKL = REM;
	create_token();
	transition_ptr = &lexical_analyzer::G1;
}

void lexical_analyzer::G1b()
{
	RKL = _ERROR;
	create_token();
	transition_ptr = &lexical_analyzer::G1;
}

void lexical_analyzer::H1a()
{
	RKL = REL_OPER;
	ROT = RZN;
	transition_ptr = &lexical_analyzer::H1;
}

void lexical_analyzer::H1b()
{
	create_token();
	RKL = REL_OPER;
	ROT = RZN;
	transition_ptr = &lexical_analyzer::H1;
}

void lexical_analyzer::H1c()
{
	create_token();
	RKL = REL_OPER;
	ROT = RZN;
	transition_ptr = &lexical_analyzer::H1;
}

void lexical_analyzer::H1f()
{
	H1b();
	RKL = REL_OPER;
	ROT = RZN;
	transition_ptr = &lexical_analyzer::H1;
}

void lexical_analyzer::M1()
{
	if (!ROB)
	{
		G1b();
		return;
	}

	if (RZN == det_table.table[ROB - 1].letter) (this ->*(det_table.table[ROB - 1].detection_table_transition))();
	else
	{
		ROB = det_table.table[ROB - 1].alternative;

		if (ROB) (this ->*(det_table.table[ROB - 1].detection_table_transition))();
		else G1b();
	}
}

void lexical_analyzer::M2()
{
	if (RZN == 5)
	{
		D3a();
		return;
	}
	else
	{
		create_token();
		ROB = det_table.start_vector[RZN - 1];
		transition_ptr = &lexical_analyzer::B1;
	}
}

void lexical_analyzer::M3()
{
	is_there_no_E = false;
	if (RZN == 5) transition_ptr = &lexical_analyzer::D3;
}

void lexical_analyzer::exit1()
{
	RKL = ENDFILE;
	create_token();
}

void lexical_analyzer::exit2()
{
	create_token();
	RKL = ENDFILE;
	create_token();
}

void lexical_analyzer::exit3()
{
	create_token();
	RKL = ENDFILE;
	create_token();
}

void lexical_analyzer::exit4()
{
	create_token();
	RKL = ENDFILE;
	create_token();
}

void lexical_analyzer::exit5()
{
	create_token();
	RKL = ENDFILE;
	create_token();
}

void lexical_analyzer::error2() { RKL = _ERROR; create_token(); RKL = ENDFILE; create_token(); }