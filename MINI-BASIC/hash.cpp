#include "hash.h"

int string_hash::hash_function(int key_) { return key_ % 100; }

void string_hash::initialize_table()
{
    hash_table = new hash_element[table_size];
    hash_table[0].token_value = 0;
    hash_table[0].index = 0;
    hash_table[0].alt = 0;

    for (size_t i = 1; i < table_size; i++)
    {
        hash_table[i].token_value = -1;
        hash_table[i].index = -1;
        hash_table[i].alt = 0;
    }
}

void string_hash::expand()
{
    int new_size = table_size * 2;

    hash_element* new_table = new hash_element[new_size];
    hash_element* temp = hash_table;

    for (int i = 0; i < table_size; i++)
    {
        new_table[i].token_value = hash_table[i].token_value;
        new_table[i].index = hash_table[i].index;
        new_table[i].alt = hash_table[i].alt;
    }
    for (int i = table_size; i < new_size; i++)
    {
        new_table[i].token_value = -1;
        new_table[i].index = -1;
        new_table[i].alt = 0;
    }

    table_size *= 2;

    delete[] hash_table;
    hash_table = new_table;
}

int string_hash::collision_solving(int key_, int index_)
{
    if (next_in_alt_table == table_size)
        expand();

    int hash_index = hash_function(key_) + 1;

    while (hash_table[hash_index].alt != 0)
        hash_index = hash_table[hash_index].alt;

    if (hash_table[0].alt == 0)
    {
        hash_table[hash_index].alt = next_in_alt_table;
        hash_table[next_in_alt_table].token_value = key_;
        hash_table[next_in_alt_table].index = index_;

        return next_in_alt_table++;
    }
    else
    {
        int alt_zero = hash_table[0].alt;

        hash_table[0].alt = hash_table[alt_zero].alt;
        hash_table[alt_zero].alt = 0;

        hash_table[hash_index].alt = alt_zero;
        hash_table[alt_zero].token_value = key_;
        hash_table[alt_zero].index = index_;

    }

    return hash_index;
}

void string_hash::correct_removal(int key_)
{
    int hash_index = hash_function(key_) + 1;

    if (hash_table[hash_index].token_value == key_)
    {
        if (hash_table[hash_index].alt == 0)
            hash_table[hash_index].token_value = -1;
        else
        {
            int prev = hash_index;

            while (hash_table[hash_table[hash_index].alt].alt != 0)
                hash_index = hash_table[hash_index].alt;

            hash_table[prev].token_value = hash_table[hash_table[hash_index].alt].token_value;

            hash_table[hash_table[hash_index].alt].alt = hash_table[0].alt;
            hash_table[0].alt = hash_table[hash_index].alt;

            hash_table[hash_table[hash_index].alt].token_value = -1;
            hash_table[hash_table[hash_index].alt].index = -1;
            hash_table[hash_index].alt = 0;
        }
    }
    else
    {

        while (hash_table[hash_table[hash_index].alt].token_value != key_)
            hash_index = hash_table[hash_index].alt;

        int temp = hash_table[hash_table[hash_index].alt].alt;

        hash_table[hash_table[hash_index].alt].alt = hash_table[0].alt;

        hash_table[hash_table[hash_index].alt].token_value = -1;
        hash_table[hash_table[hash_index].alt].index = -1;

        hash_table[0].alt = hash_table[hash_index].alt;

        hash_table[hash_index].alt = temp;

    }
}

int string_hash::find_alternative(int key_)
{
    int hash_index = hash_function(key_) + 1;

    while (hash_table[hash_index].alt != 0)
    {
        hash_index = hash_table[hash_index].alt;
        if (hash_table[hash_index].token_value == key_)
            return hash_index;
    }

    return 0;
}

int string_hash::find_alternative_index(int key_)
{
    int hash_index = hash_function(key_) + 1;

    while (hash_table[hash_index].alt != 0)
    {
        hash_index = hash_table[hash_index].alt;

        if (hash_table[hash_index].token_value == key_)
            return hash_table[hash_index].index;
    }

    return -1;
}

string_hash::string_hash()
{
    table_size = 300;
    main_area_size = 100 + 1;
    next_in_alt_table = 100 + 2;

    initialize_table();
}

string_hash::string_hash(int table_size_, int area_size_)
{
    if (area_size_ >= table_size_)
        std::cerr << "There are no cells for alternatives" << std::endl;

    table_size = table_size_;
    main_area_size = area_size_ + 1;
    next_in_alt_table = area_size_ + 1;

    initialize_table();
}

int string_hash::insert_element(int key_, int index_)
{
    if (get_value(key_))
        return get_value(key_);
    if (hash_table[hash_function(key_) + 1].token_value == -1)
    {
        hash_table[hash_function(key_) + 1].token_value = key_;
        hash_table[hash_function(key_) + 1].index = index_;

        return (hash_function(key_) + 1);
    }
    else
        return collision_solving(key_, index_);
}

int string_hash::insert_index(int key_, int index_)
{
    hash_table[key_].index = index_;
    return key_;
}

void string_hash::remove(int key_) { if (get_value(key_)) correct_removal(key_); }

int& string_hash::operator[](int index_) const
{
    if (index_ >= table_size)
        std::cerr << "Index out of rnage." << std::endl;

    return hash_table[index_].token_value;
}

int string_hash::get_value(int key_)
{
    if (hash_table[hash_function(key_) + 1].token_value == key_)
        return hash_function(key_) + 1;
    else
        return find_alternative(key_);
}

int string_hash::find_and_return_index(int key_)
{
    if (hash_table[hash_function(key_) + 1].token_value == key_)
        return hash_table[hash_function(key_) + 1].index;
    else
        return find_alternative_index(key_);
}

bool string_hash::is_there_errors()
{
    for (int i = 1; i < table_size; i++)
    {
        if (hash_table[i].token_value != -1 && hash_table[i].index == -1)
            return true;
    }

    return false;
}

void string_hash::hash_print()
{
    for (int i = 0; i < main_area_size; i++)
    {
        if (hash_table[i].token_value == -1 && hash_table[i].alt == 0)
            continue;

        std::cout << "--------------------------" << std::endl;
        std::cout << i << "\t | " << hash_table[i].token_value << "\t | " << hash_table[i].alt << "\t | " << std::endl;
    }

    std::cout << "==========================" << std::endl;
    for (int i = main_area_size; i < table_size; i++)
    {
        if (hash_table[i].token_value == -1 && hash_table[i].alt == 0)
            continue;

        std::cout << i << "\t | " << hash_table[i].token_value << "\t | " << hash_table[i].alt << "\t | " << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

void string_hash::main_scope_print() const
{
    for (int i = 0; i < main_area_size; i++)
    {
        std::cout << "--------------------------------" << std::endl;
        std::cout << i << "\t | " << hash_table[i].token_value << "\t | " << hash_table[i].alt << std::endl;
    }
}

void string_hash::alternatives_print() const
{
    std::cout << "===================================" << std::endl;

    for (int i = main_area_size; i < table_size; i++)
    {
        std::cout << "--------------------------------" << std::endl;
        std::cout << i << "\t | " << hash_table[i].token_value << "\t | " << hash_table[i].alt << std::endl;
    }
}