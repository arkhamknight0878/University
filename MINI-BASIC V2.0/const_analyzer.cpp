#include "const_analyzer.h"

int ConstAnalyzer::transliterator(const char char_to_transliterate_)
{
	if (isdigit(char_to_transliterate_)) return CA_LETTER;

	switch (char_to_transliterate_)
	{
	case 'E':
		return CA_E;
	case 'e':
		return CA_E;
	case '.':
		return CA_DOT;
	case '+':
	case '-':
		return CA_SIGN;
	case '\n':
	case '\0':
		return CA_ENDL;
	default:
		return 5;
	}
}

double ConstAnalyzer::change_number_of_decimal_places(double initial_number_, int number_of_decimal_places_)
{
	if (!number_of_decimal_places_);
	else if (number_of_decimal_places_ == 1) initial_number_ /= 10;
	else if (number_of_decimal_places_ < 0)
	{
		for (int i = 0; i > number_of_decimal_places_; i--)
			initial_number_ *= 10;
	}
	else
	{
		for (int i = 1; i <= number_of_decimal_places_; i++)
			initial_number_ /= 10;
	}

	return initial_number_;
}

int ConstAnalyzer::P1(const char current_ch_)
{
	RCH += atoi(&current_ch_);
	return q1;
}

int ConstAnalyzer::P2(const char current_ch_)
{
	RCH = 0;
	RS = 0;
	return q6;
}

int ConstAnalyzer::P3(const char current_ch_)
{
	RCH = RCH * 10 + atoi(&current_ch_);
	return q1;
}

int ConstAnalyzer::P4(const char current_ch_)
{
	RS = 0;
	return q3;
}

int ConstAnalyzer::P5(const char current_ch_)
{
	RS = 0;
	return q2;
}

int ConstAnalyzer::P6(const char current_ch_)
{
	RCH = RCH * 10 + atoi(&current_ch_);
	RS++;
	return q2;
}

int ConstAnalyzer::P7(const char current_ch_) { return q3; }

int ConstAnalyzer::P8(const char current_ch_)
{
	RP = atoi(&current_ch_);
	return q5;
}

int ConstAnalyzer::P9(const char current_ch_)
{
	if (current_ch_ == '-')RZ = 0;
	else if (current_ch_ == '+') RZ = 1;

	return q4;
}

int ConstAnalyzer::P10(const char current_ch_)
{
	RP = atoi(&current_ch_);
	return q5;
}

int ConstAnalyzer::P11(const char current_ch_)
{
	RP = RP * 10 + atoi(&current_ch_);
	return q5;
}

int ConstAnalyzer::ERROR1(const char current_ch_) { return error1; throw "Error: Wrong input."; }

int ConstAnalyzer::ERROR2(const char current_ch_) { return error2; throw "Error: Second dot detected."; }

int ConstAnalyzer::ERROR3(const char current_ch_) { return error3; throw "Error: Wrong sign position."; }

int ConstAnalyzer::ERROR4(const char current_ch_) { return error4; throw "Error: No digits after E."; }

int ConstAnalyzer::ERROR5(const char current_ch_) { return error5; throw "Error: Empty number."; }

int ConstAnalyzer::ERROR6(const char current_ch_) { return error6; throw "Error: No digits after sign."; }

int ConstAnalyzer::ERROR7(const char current_ch_) { return error7; throw "Error: No digits after dot with empty integer part."; }

ConstAnalyzer::ConstAnalyzer()
{
	val = RCH = RP = RS = 0;
	RZ = 1;

	control_table[q0][CA_LETTER] = &ConstAnalyzer::P1;
	control_table[q0][CA_E] = &ConstAnalyzer::ERROR1;
	control_table[q0][CA_DOT] = &ConstAnalyzer::P2;
	control_table[q0][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q0][CA_ENDL] = &ConstAnalyzer::ERROR5;

	control_table[q1][CA_LETTER] = &ConstAnalyzer::P3;
	control_table[q1][CA_E] = &ConstAnalyzer::P4;
	control_table[q1][CA_DOT] = &ConstAnalyzer::P5;
	control_table[q1][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q1][CA_ENDL] = &ConstAnalyzer::END1;

	control_table[q2][CA_LETTER] = &ConstAnalyzer::P6;
	control_table[q2][CA_E] = &ConstAnalyzer::P7;
	control_table[q2][CA_DOT] = &ConstAnalyzer::ERROR2;
	control_table[q2][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q2][CA_ENDL] = &ConstAnalyzer::END2;

	control_table[q3][CA_LETTER] = &ConstAnalyzer::P8;
	control_table[q3][CA_E] = &ConstAnalyzer::ERROR1;
	control_table[q3][CA_DOT] = &ConstAnalyzer::ERROR2;
	control_table[q3][CA_SIGN] = &ConstAnalyzer::P9;
	control_table[q3][CA_ENDL] = &ConstAnalyzer::ERROR4;

	control_table[q4][CA_LETTER] = &ConstAnalyzer::P10;
	control_table[q4][CA_E] = &ConstAnalyzer::ERROR1;
	control_table[q4][CA_DOT] = &ConstAnalyzer::ERROR2;
	control_table[q4][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q4][CA_ENDL] = &ConstAnalyzer::ERROR6;

	control_table[q5][CA_LETTER] = &ConstAnalyzer::P11;
	control_table[q5][CA_E] = &ConstAnalyzer::ERROR1;
	control_table[q5][CA_DOT] = &ConstAnalyzer::ERROR2;
	control_table[q5][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q5][CA_ENDL] = &ConstAnalyzer::END3;

	control_table[q6][CA_LETTER] = &ConstAnalyzer::P12;
	control_table[q6][CA_E] = &ConstAnalyzer::ERROR1;
	control_table[q6][CA_DOT] = &ConstAnalyzer::ERROR2;
	control_table[q6][CA_SIGN] = &ConstAnalyzer::ERROR1;
	control_table[q6][CA_ENDL] = &ConstAnalyzer::ERROR7;
}

bool ConstAnalyzer::parse(const string strk)
{
	int current_state = q0;
	auto it = strk.begin();

	try
	{
		while (current_state != CA_ENDL1 && current_state != CA_ENDL2 && current_state != CA_ENDL3 && current_state != CA_ERROR && current_state != error1 && current_state != error2 &&
			current_state != error3 && current_state != error4 && current_state != error5 && current_state != error6 && current_state != error7)
		{
			if (it == strk.end())val = '\n';
			else val = *(it++);

			int transliterated_char_value = transliterator(val);

			if (transliterated_char_value == 5) current_state = error1;
			else
				current_state = (this->*control_table[current_state][transliterated_char_value])(val);

			RCH = RCH;
			RZ = RZ;
			RP = RP;
			RS = RS;
		}
	}
	catch (const char* error_message)
	{
		cout << error_message << endl;
		return false;
	}

	if (current_state == CA_ENDL1) { cout << endl << "number: " << RCH << endl; }
	if (current_state == CA_ENDL2) { cout << endl << "number: " << change_number_of_decimal_places(RCH, RS) << endl; }
	if (current_state == CA_ENDL3)
	{
		if (RZ) RS = RS - RP;
		else RS += RP;

		cout << endl << "number: " << change_number_of_decimal_places(RCH, RS) << endl;
	}

	return true;
}
