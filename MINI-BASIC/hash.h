#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <map>

class lexical_analyzer;

struct hash_element
{
    int label;
    int index;
    int alt;
};

class string_hash
{
private:
    hash_element* hash_table;

    int table_size;
    int main_area_size;
    int next_in_alt_table;

    int hash_function(int key_);

    void initialize_table();

    void expand();

    int collision_solving(int key_, int index_);

    void correct_removal(int key_);

    int find_alternative(int key_);

    int find_alternative_index(int key_);
public:
    friend class lexical_analyzer;

    string_hash();

    string_hash(int table_size_, int area_size_);

    int insert_element(int key_, int index_ = -1);

    int insert_index(int key_, int index_);

    void remove(int key_);

    int& operator[](int index_) const;

    int get_value(int key_);

    int find_and_return_index(int key_);

    bool is_there_errors();

    void hash_print();

    void main_scope_print() const;

    void alternatives_print() const;

    int get_label(int index_);
};

#endif