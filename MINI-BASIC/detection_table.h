#ifndef DETECTION_TABLE_H
#define DETECTION_TABLE_H

#include <vector>

class lexical_analyzer;

struct detection_table_node
{
	int letter;
	int alternative;

	typedef void (lexical_analyzer::* transition_ptr)();
	transition_ptr detection_table_transition;

	detection_table_node();
};

struct detection_table
{
	std::vector<int> start_vector;
	std::vector<detection_table_node> hash_table;

	detection_table();
};

#endif