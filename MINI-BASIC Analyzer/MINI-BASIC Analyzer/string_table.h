#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

struct el_ts
{
	int label;
	int index_tl;	// element index in TL table
	int next;		// collisions solving (alternative)
};

class string_table
{
private:
	el_ts* hash_table;
	int max_size;
	int main_scope_size;	// Main Scope Size
	int closest_alternative;	// First Availible Data in String Table

	int hash_function(int key_);

	void resize();
public:
	string_table();

	string_table(int max_size_, int main_scope_size_);

	string_table(const string_table& other_);

	~string_table();

	int find(int key_);

	int add(int key_, int ind);

	void erase(int key_);

	friend ostream& operator<< (ostream& out_, const string_table& hash_);
};