#pragma once

#include "token.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class lexical_analyzer
{
private:
	typedef void (lexical_analyzer::* pfunc)();	// Укaзатель на функшии состояния;

	std::vector<Token> TL;	//Таблиша лексем
	double TO[1024];		//Таблица оперендов

	std::vector<int> TS;	//Таблича строк
	int NTO;				//Указатель на первый свободный элемент в ТО
	int NTS;				//Указатель на первый свободный элемент таблицы строк
	int NTL;				//Указатель на первый свободный элемент в TL

	std::vector<int> InitialVector; // Начальный вектор
	int RCH;						// Регистр числа
	int RZ;							// Регистр знака порядка
	int RP;							// Регистр порядка
	int RS;							// Регистр счётчика
	int RKL;						// Регистр класса лексем
	int ROT;						// Регистр значения отношения
	int RZN;						// Регистр значение символа int
	int SOS;						// Регистр состояния
	int ROB;						// Регистр обнаружения
	int RK;							// Регистр значения класса символа
	int RSTR;						// Регистр строки
	int RI;							// Регистр номера буквы в имени переменной
	int RSE;						// Регистр счётчика ошибок
	std::string str;				// Строка входного файла
	std::ofstream ferr;				// Файл oшибок

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

	void Trans(char);

	void Parse();

	void End();

	void CreateToken();

	void SaveLexems();

	void SaveOperands();

public:
	void SaveLabels();

	lexical_analyzer();

	void Start(const char*);

	struct Str
	{
		int RowLabel;
	};

	struct node
	{
		int leter;
		int alternativa;
	};
};