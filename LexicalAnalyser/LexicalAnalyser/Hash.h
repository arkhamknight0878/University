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

class Hash
{
private:
	el_ts* hash_table;
	int max_size;
	int main_scope_size;	// Main Scope Size
	int closest_alternative;	// First Availible Data in String Table

	int hash_function(int key_);

	void resize();
public:
	Hash();

	Hash(int max_size_, int main_scope_size_);

	Hash(const Hash& other_);

	~Hash();

	int find(int key_);

	int add(int key_, int ind);

	void erase(int key_);

	friend ostream& operator<< (ostream& out_, const Hash& hash_);
};