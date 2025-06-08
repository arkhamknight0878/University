#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "iostream"

using namespace std;

struct string_table_element
{
	int label;		// Label value
	int index_el;	// Index of label in tokens table
	int next;		// Collision solving
};

class string_table
{
	int size;
	int main_scope_size;			// Main scope size
	int free_overflow_area_index;	// The first free area in the overflow area

	string_table_element* stable;

	int hash_function(int key_);
public:
	string_table(int max_size_ = 1000, int main_scope_size_ = 200);

	string_table(const string_table& other_);

	~string_table();

	int find(int key_);

	int get_token_table_index(int string_table_index_);

	int get_label(int string_table_index_);

	void remove(int key_);

	void change_token_table_index(int old_index_, int new_index_);

	int el_add(int key, int ind);

	void write_in_file(ofstream& target_file_);

	void table_output();

	friend ostream& operator<<(ostream& output_stream_, const string_table& string_table_);
};

#endif // !STRING_TABLE_H