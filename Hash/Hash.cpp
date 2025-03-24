#include "Hash.h"

int Hash::hash_function(int key_) { return (key_ % main_scope_size + 1); }

Hash::Hash()
{
	max_size = 50;
	main_scope_size = 10;
	closest_alternative = main_scope_size + 1;
	hash_table = new el_ts[max_size];

	for (int i = 0; i < max_size; ++i)
	{
		hash_table[i].index_tl = -1;
		hash_table[i].label = -1;
		hash_table[i].next = 0;
	}
}

Hash::Hash(int max_size_, int main_scope_size_)
{
	max_size = max_size_;
	main_scope_size = main_scope_size_;
	closest_alternative = main_scope_size_ + 1;
	hash_table = new el_ts[max_size];

	for (int i = 0; i < max_size; ++i)
	{
		hash_table[i].index_tl = -1;
		hash_table[i].label = -1;
		hash_table[i].next = 0;
	}
}

Hash::Hash(const Hash& other_)
{
	max_size = other_.max_size;
	main_scope_size = other_.main_scope_size;
	closest_alternative = other_.closest_alternative;

	hash_table = new el_ts[max_size];

	for (int i = 0; i < max_size; ++i)
	{
		hash_table[i].label = other_.hash_table[i].label;
		hash_table[i].index_tl = other_.hash_table[i].index_tl;
		hash_table[i].next = other_.hash_table[i].next;
	}
}

Hash::~Hash() { delete[] hash_table; }

int Hash::find(int key_)
{
	int hash_index = hash_function(key_);

	if (hash_table[hash_index].label == key_)
		return hash_index;

	while (hash_table[hash_index].next != 0)
	{
		hash_index = hash_table[hash_index].next;

		if (hash_table[hash_index].label == key_)
			return hash_index;
	}

	return -1;
}
