#ifndef CONST_ANALYZER_H
#define CONST_ANALYZER_H

#include <cctype>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// CA stands fo "Const Analyzer"
enum MACHINE_ALPHABET { CA_LETTER, CA_E, CA_DOT, CA_SIGN, CA_ENDL, CA_ERROR = 500, CA_ENDL1, CA_ENDL2, CA_ENDL3 };

enum STATES { q0, q1, q2, q3, q4, q5, q6, error1 = 1000, error2, error3, error4, error5, error6, error7 };

const unsigned short alfabet_size = 5;
const unsigned short number_of_sates = 7;

class ConstAnalyzer
{
private:
	typedef int(ConstAnalyzer::* fptr)(const char current_ch_);

	fptr control_table[number_of_sates][alfabet_size];

	int val;
	int RS;
	int RP;
	double RCH;
	bool RZ;

	int transliterator(const char char_to_transliterate_);

	double change_number_of_decimal_places(double initial_number_, int number_of_decimal_places_);

	// Basic working states
	int P1(const char current_ch_);
	int P2(const char current_ch_);
	int P3(const char current_ch_);
	int P4(const char current_ch_);
	int P5(const char current_ch_);
	int P6(const char current_ch_);
	int P7(const char current_ch_);
	int P8(const char current_ch_);
	int P9(const char current_ch_);
	int P10(const char current_ch_);
	int P11(const char current_ch_);
	int P12(const char current_ch_) { RCH = atoi(&current_ch_); RS = 1; return q2; }

	// Error handling states
	int ERROR1(const char current_ch_);
	int ERROR2(const char current_ch_);
	int ERROR3(const char current_ch_);
	int ERROR4(const char current_ch_);
	int ERROR5(const char current_ch_);
	int ERROR6(const char current_ch_);
	int ERROR7(const char current_ch_);

	// Final states
	int END1(const char current_ch_) { return CA_ENDL1; }
	int END2(const char current_ch_) { return CA_ENDL2; }
	int END3(const char current_ch_) { return CA_ENDL3; }

public:
	ConstAnalyzer();

	bool parse(const string strk);
};

#endif // !CONST_ANALYZER_H