#include "detection_table.h"
#include "lexical_analyzer.h"

detection_table_node::detection_table_node()
{
	letter = -1;
	alternative = -1;
	detection_table_transition = nullptr;
}

detection_table::detection_table()
{
	// Заполняем начальный вектор
	//				 A  B  C  D  E  F  G  H   I  J  K   L  M   N  O  P  Q   R   S   T  U  V  W  X  Y  Z
	start_vector = { 0, 0, 0, 0, 1, 3, 5, 0, 11, 0, 0, 12, 0, 14, 0, 0, 0, 17, 23, 23, 0, 0, 0, 0, 0, 0 };

	detection_table_node new_node;

	for (int i = 0; i < 26; ++i)
		table.push_back(new_node);

	// Заполняем вектор букв
	table[0].letter = 14;
	table[1].letter = 4;
	table[2].letter = 15;
	table[3].letter = 18;
	table[4].letter = 15;
	table[5].letter = 20;
	table[6].letter = 15;
	table[7].letter = 19;
	table[8].letter = 21;
	table[9].letter = 2;
	table[10].letter = 6;
	table[11].letter = 5;
	table[12].letter = 20;
	table[13].letter = 5;
	table[14].letter = 24;
	table[15].letter = 20;
	table[16].letter = 5;
	table[17].letter = 20;
	table[18].letter = 21;
	table[19].letter = 18;
	table[20].letter = 14;
	table[21].letter = 13;
	table[22].letter = 20;
	table[23].letter = 5;
	table[24].letter = 16;
	table[25].letter = 15;

	// Заполняем вектор алтернатив
	for (int i = 0; i < 26; ++i)
	{
		if (i == 5) table[i].alternative = 8;
		else if (i == 17) table[i].alternative = 22;
		else table[i].alternative = 0;
	}

	// Заполняем вектор переходов
	for (int i = 0; i < 26; ++i)
	{
		if (i == 1) table[i].detection_table_transition = &lexical_analyzer::A2q;
		else if (i == 3) table[i].detection_table_transition = &lexical_analyzer::F1b;
		else if (i == 6) table[i].detection_table_transition = &lexical_analyzer::E1a;
		else if (i == 9) table[i].detection_table_transition = &lexical_analyzer::E1b;
		else if (i == 10) table[i].detection_table_transition = &lexical_analyzer::A2r;
		else if (i == 12) table[i].detection_table_transition = &lexical_analyzer::F1a;
		else if (i == 15) table[i].detection_table_transition = &lexical_analyzer::C1a;
		else if (i == 20) table[i].detection_table_transition = &lexical_analyzer::A2s;
		else if (i == 21) table[i].detection_table_transition = &lexical_analyzer::G1a;
		else if (i == 24) table[i].detection_table_transition = &lexical_analyzer::A2t;
		else if (i == 25) table[i].detection_table_transition = &lexical_analyzer::A2u;
		else table[i].detection_table_transition = &lexical_analyzer::next;
	}
}