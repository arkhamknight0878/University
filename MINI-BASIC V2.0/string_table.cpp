#include "string_table.h"

int string_table::hash_function(int key_) { return (key_ % 100) + 1; }

string_table::string_table(int max_size_, int main_scope_size_)
{
    size = max_size_;
    main_scope_size = main_scope_size_;
    free_overflow_area_index = main_scope_size_ + 1;

    stable = new string_table_element[size];

    for (int i = 0; i < size; i++)
    {
        stable[i].label = stable[i].index_el = -1;
        stable[i].next = 0;
    }
}

string_table::string_table(const string_table& other_)
{
    size = other_.size;
    main_scope_size = other_.main_scope_size;
    free_overflow_area_index = other_.free_overflow_area_index;;
    stable = new string_table_element[size];

    for (int i = 0; i < size; i++)
    {
        stable = other_.stable;
    }
}

string_table::~string_table() { delete[] stable; }

int string_table::find(int key_)
{
    int i = hash_function(key_);

    while (stable[i].label != key_)
    {
        if (stable[i].next != 0)
            i = stable[i].next;
        else return -1;
    }

    return i;
}

int string_table::get_token_table_index(int string_table_index_)
{
    if (string_table_index_ >= size)
        return -1;

    return stable[string_table_index_].index_el;
}

int string_table::get_label(int string_table_index_) { return stable[string_table_index_].label; }

void string_table::remove(int key_)
{
    int hash_index = hash_function(key_);
    if (stable[hash_index].label == -1)
        return;

    if (stable[hash_index].label == key_ && stable[hash_index].next == 0) // Remove an element in the main area that does not have the following
    {
        stable[hash_index].label = -1;
        stable[hash_index].index_el = -1;
        return;
    }
    else if (stable[hash_index].label == key_ && stable[hash_index].next != 0) // Remove an element in the main area that has the following
    {
        int penultimate_index = hash_index;
        int sv = stable[hash_index].next; // Сhain start index outside the main area

        while (stable[stable[penultimate_index].next].next != 0)
            penultimate_index = stable[penultimate_index].next;

        stable[hash_index] = stable[stable[penultimate_index].next]; // Last element of main scope chain
        stable[hash_index].next = sv;
        stable[stable[penultimate_index].next].next = 0;
        stable[stable[penultimate_index].next].index_el = -1;
        stable[stable[penultimate_index].next].label = -1;

        if (stable[0].next == 0) stable[0].next = stable[penultimate_index].next;
        else
        {
            int cpy = stable[0].next;
            stable[0].next = stable[penultimate_index].next;
            stable[stable[penultimate_index].next].next = cpy;
        }
        stable[penultimate_index].next = 0;

        return;
    }

    while (stable[stable[hash_index].next].label != key_)
        hash_index = stable[hash_index].next;

    int cpy = stable[hash_index].next;
    stable[hash_index].next = stable[cpy].next;
    stable[cpy].label = -1;

    if (stable[0].next == 0) { stable[0].next = cpy; stable[cpy].next = 0; }
    else
    {
        int cpy1 = stable[0].next;
        stable[0].next = cpy;
        stable[cpy].next = cpy1;
    }

    return;
}

void string_table::change_token_table_index(int old_index_, int new_index_) { stable[old_index_].index_el = new_index_; }

int string_table::el_add(int key, int ind)
{
    int hash_index = hash_function(key);
    if (stable[hash_index].label == -1)
    {
        stable[hash_index].label = key;
        stable[hash_index].index_el = ind;
        return hash_index;
    }

    int last_element_index = hash_index;
    while (stable[last_element_index].next != 0)
        last_element_index = stable[last_element_index].next;

    if (stable[0].next == 0)
    {
        stable[last_element_index].next = free_overflow_area_index;
        stable[free_overflow_area_index].label = key;
        stable[free_overflow_area_index].index_el = ind;
        free_overflow_area_index++;
        return free_overflow_area_index - 1;
    }

    if (stable[0].next != 0)
    {
        stable[last_element_index].next = stable[0].next;
        int sv = stable[0].next;
        stable[0].next = stable[sv].next;
        stable[sv].label = key;
        stable[sv].index_el = ind;
        stable[sv].next = 0;
        return sv;
    }
}

void string_table::write_in_file(ofstream& target_file_)
{
    target_file_ << "String Table:" << endl << endl;
    target_file_ << left
        << setw(10) << "Index"
        << setw(10) << "Label"
        << setw(10) << "TL"
        << setw(10) << "Next"
        << endl;

    target_file_ << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    target_file_ << left
        << setw(10) << "0"
        << setw(10) << stable[0].label
        << setw(10) << stable[0].index_el
        << setw(10) << stable[0].next
        << endl;

    for (int i = 1; i < free_overflow_area_index; ++i) {
        if (stable[i].label != -1) {
            target_file_ << left
                << setw(10) << i
                << setw(10) << stable[i].label
                << setw(10) << stable[i].index_el
                << setw(10) << stable[i].next
                << endl;
        }
    }
}

void string_table::table_output()
{
    std::cout << "String Table:" << endl << endl;
    std::cout << std::setw(7) << 0 << "|"
        << std::setw(10) << stable[0].label << "|"
        << std::setw(10) << stable[0].index_el << "|"
        << std::setw(10) << stable[0].next << "|" << std::endl;
    for (int i = 1; i < size; i++)
    {
        if (stable[i].label != -1)
            std::cout << std::setw(7) << i << "|"
            << std::setw(10) << stable[i].label << "|"
            << std::setw(10) << stable[i].index_el << "|"
            << std::setw(10) << stable[i].next << "|" << std::endl;
    }
    std::cout << std::endl;
}

ostream& operator<<(ostream& output_stream_, const string_table& string_table_)
{
    output_stream_ << left
        << setw(10) << "Индекс"
        << setw(10) << "Метка"
        << setw(10) << "TL"
        << setw(10) << "Следующий"
        << endl;

    // Разделитель
    output_stream_ << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    output_stream_ << left
        << setw(10) << "0"
        << setw(10) << string_table_.stable[0].label
        << setw(10) << string_table_.stable[0].index_el
        << setw(10) << string_table_.stable[0].next
        << endl;

    // Печатаем остальные элементы
    for (int i = 1; i < string_table_.free_overflow_area_index; ++i) {
        if (string_table_.stable[i].label != -1) {
            output_stream_ << left
                << setw(10) << i
                << setw(10) << string_table_.stable[i].label
                << setw(10) << string_table_.stable[i].index_el
                << setw(10) << string_table_.stable[i].next
                << endl;
        }
    }

    return output_stream_;
}