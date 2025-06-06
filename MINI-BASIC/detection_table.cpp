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
		hash_table.push_back(new_node);

	// Заполняем вектор букв
	hash_table[0].letter = 14;
	hash_table[1].letter = 4;
	hash_table[2].letter = 15;
	hash_table[3].letter = 18;
	hash_table[4].letter = 15;
	hash_table[5].letter = 20;
	hash_table[6].letter = 15;
	hash_table[7].letter = 19;
	hash_table[8].letter = 21;
	hash_table[9].letter = 2;
	hash_table[10].letter = 6;
	hash_table[11].letter = 5;
	hash_table[12].letter = 20;
	hash_table[13].letter = 5;
	hash_table[14].letter = 24;
	hash_table[15].letter = 20;
	hash_table[16].letter = 5;
	hash_table[17].letter = 20;
	hash_table[18].letter = 21;
	hash_table[19].letter = 18;
	hash_table[20].letter = 14;
	hash_table[21].letter = 13;
	hash_table[22].letter = 20;
	hash_table[23].letter = 5;
	hash_table[24].letter = 16;
	hash_table[25].letter = 15;

	// Заполняем вектор алтернатив
	for (int i = 0; i < 26; ++i)
	{
		if (i == 5) hash_table[i].alternative = 8;
		else if (i == 17) hash_table[i].alternative = 22;
		else hash_table[i].alternative = 0;
	}

	// Заполняем вектор переходов
	for (int i = 0; i < 26; ++i)
	{
		if (i == 1) hash_table[i].detection_table_transition = &lexical_analyzer::A2q;
		else if (i == 3) hash_table[i].detection_table_transition = &lexical_analyzer::F1b;
		else if (i == 6) hash_table[i].detection_table_transition = &lexical_analyzer::E1a;
		else if (i == 9) hash_table[i].detection_table_transition = &lexical_analyzer::E1b;
		else if (i == 10) hash_table[i].detection_table_transition = &lexical_analyzer::A2r;
		else if (i == 12) hash_table[i].detection_table_transition = &lexical_analyzer::F1a;
		else if (i == 15) hash_table[i].detection_table_transition = &lexical_analyzer::C1a;
		else if (i == 20) hash_table[i].detection_table_transition = &lexical_analyzer::A2s;
		else if (i == 21) hash_table[i].detection_table_transition = &lexical_analyzer::G1a;
		else if (i == 24) hash_table[i].detection_table_transition = &lexical_analyzer::A2t;
		else if (i == 25) hash_table[i].detection_table_transition = &lexical_analyzer::A2u;
		else hash_table[i].detection_table_transition = &lexical_analyzer::next;
	}
}