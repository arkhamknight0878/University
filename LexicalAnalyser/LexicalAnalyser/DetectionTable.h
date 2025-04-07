#pragma once

#include "LexicalAnalyser.h"

extern struct StartVector start_vector;
extern struct TransitionTable transition_table;

struct StartVector
{
	int letter[26];
	int rob[26]{  0,   0,   0,   0,   1,   3,   5,   0,  11,   0,   0,  12,   0,  14,   0,   0,   0,  17,  23,  26,   0,   0,   0,   0,   0,   0 };

	StartVector()
	{
		for (int i = 'A'; i <= 'Z'; ++i)
			letter[i - 'A'] = i;
	}
};

struct TransitionTable
{
	int letter[26]		{ 'N', 'D', 'O', 'R', 'O', 'T', 'O', 'S', 'U', 'B', 'F', 'E', 'T', 'E', 'X', 'T', 'E', 'T', 'U', 'R', 'N', 'M', 'T', 'E', 'P', 'O' };
	int alternative[26]	{  0,   0,   0,   0,   0,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  22,   0,   0,   0,   0,   0,   0,   0,   0  };
	typedef int(LexicalAnalyser::* fptr);
	fptr transitions[26];
};