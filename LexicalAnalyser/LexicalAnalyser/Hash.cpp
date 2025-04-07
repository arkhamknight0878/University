#include "Hash.h"

int Hash::hash_function(int key_) { return (key_ % main_scope_size + 1); }

void Hash::resize()
{
	el_ts* new_hash = new el_ts[max_size *= 2];

	for (int i = 0; i < closest_alternative; ++i)
	{
		new_hash[i].label = hash_table[i].label;
		new_hash[i].index_tl = hash_table[i].index_tl;
		new_hash[i].next = hash_table[i].next;
	}

	for (int i = closest_alternative; i < max_size; ++i)
	{
		new_hash[i].label = -1;
		new_hash[i].index_tl = i;
		new_hash[i].next = 0;
	}

	main_scope_size *= 2;

	delete[] hash_table;
	hash_table = new_hash;
}

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

int Hash::add(int key_, int ind)
{
	int hash_index = hash_function(key_);

	if (hash_table[hash_index].label == -1)
	{
		hash_table[hash_index].index_tl = ind;
		hash_table[hash_index].label = key_;
		return hash_index;
	}

	if (hash_table[0].next == 0)
	{
		while (hash_table[hash_index].next)
		{
			hash_index = hash_table[hash_index].next;
			if (hash_table[hash_index].label == key_) return hash_index;
		}

		hash_table[hash_index].next = closest_alternative;

		hash_table[closest_alternative].index_tl = ind;
		hash_table[closest_alternative].label = key_;

		++closest_alternative;

		if (closest_alternative > max_size)
			resize();

		return closest_alternative - 1;
	}

	int tmp = hash_table[0].next;
	int last = hash_index;

	while (hash_table[last].next)
	{
		last = hash_table[last].next;
		if (hash_table[last].label == key_) return last;
	}
	hash_table[0].next = hash_table[tmp].next;
	hash_table[tmp].next = 0;

	hash_table[last].next = tmp;
	hash_table[tmp].label = key_;
	hash_table[tmp].index_tl = ind;

	return tmp;
}

void Hash::erase(int key_)
{
	int hash_index = hash_function(key_);

	if (hash_table[hash_index].label == -1)
		return;

	if (hash_table[hash_index].label == key_ && hash_table[hash_index].next == 0)
	{
		hash_table[hash_index].index_tl = -1;
		hash_table[hash_index].label = -1;

		return;
	}

	if (hash_table[hash_index].label == key_ && hash_table[hash_index].next)
	{
		int prev = hash_index;

		while (hash_table[hash_table[prev].next].next)
			prev = hash_table[prev].next;

		int last_index = hash_table[prev].next;

		if (hash_table[0].next)
			hash_table[last_index].next = hash_table[0].next;

		hash_table[0].next = last_index;

		hash_table[hash_index].index_tl = 1;
		hash_table[hash_index].label = hash_table[last_index].label;

		hash_table[last_index].index_tl = -1;
		hash_table[last_index].label = -1;

		hash_table[prev].next = 0;

		return;
	}

	int prev = hash_index;

	while (hash_table[hash_table[prev].next].label != key_)
		prev = hash_table[prev].next;

	int to_delete = hash_table[prev].next;

	hash_table[prev].next = hash_table[to_delete].next;

	hash_table[to_delete].next = hash_table[0].next;

	hash_table[0].next = to_delete;

	hash_table[to_delete].index_tl = -1;
	hash_table[to_delete].label = -1;

	return;
}

ostream& operator<<(ostream& out_, const Hash& hash_)
{
	cout << left
		<< setw(8) << "Index"
		<< setw(12) << "Index_TL"
		<< setw(12) << "Label"
		<< "Next"
		<< endl;

	cout << setfill('-')
		<< setw(30) << ""
		<< endl;

	cout << setfill(' ');

	cout << left
		<< setw(8) << 0
		<< setw(12) << hash_.hash_table[0].index_tl
		<< setw(12) << hash_.hash_table[0].label
		<< hash_.hash_table[0].next
		<< endl;

	for (int i = 1; i < hash_.max_size; ++i)
	{
		if (hash_.hash_table[i].label != -1)
		{
			cout << left
				<< setw(8) << i
				<< setw(12) << hash_.hash_table[i].index_tl
				<< setw(12) << hash_.hash_table[i].label
				<< hash_.hash_table[i].next
				<< endl;
		}
	}

	cout << '\n';

	return out_;
}
