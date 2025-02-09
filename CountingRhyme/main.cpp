#include <list>
#include <vector>
#include <string>
#include <string_view>

#include "CircularListClass.h"

namespace stq
{
	void string_input(std::string& string_)
	{
		char input_char;

		while (true)
		{
			input_char = std::cin.get();
			if (input_char == '\n')
				break;

			string_ += input_char;
		}
	}

	template <class T>
	void vector_output(const std::vector<T>& vector)
	{
		auto it = vector.begin();

		while ((it + 1) != vector.end())
			std::cout << *(it++) << ", ";

		std::cout << *(it);
	}

	void str_vector_from_input(std::vector<std::string>& names_vector_, std::string names_)
	{
		auto it = names_.begin();
		std::string name;

		while (*it == ' ')
			++it;

		while (true)
		{
			if (it == names_.end() || *it == ',')
			{
				names_vector_.push_back(name);
				name.clear();

				if (it == names_.end())
					return;

				++it;
			}

			while (*it == ' ')
				++it;

			name += *(it++);
		}
	}

	void circ_list_output(CircularListClass& list_)
	{
		if (!list_.get_size())
		{
			std::cout << "()";
			return;
		}

		Iterator it = list_.begin();

		while (it != list_.end())
		{
			std::cout << *it << ", ";
			++it;
		}

		std::cout << *it;
	}
}

std::string CountingRhyme(const std::vector<std::string>& names_vector_, std::vector<std::string>& dropout_oreder_, int dropout_frequency_)
{
	if (!names_vector_.size())
	{
		std::string empty_str;
		return empty_str;
	}

	CircularListClass ind_list(0, names_vector_.size() - 1, 0);
	Iterator it = ind_list.begin();

	while (ind_list.get_size() != 1)
	{
		it += dropout_frequency_ - 1;

		dropout_oreder_.push_back(names_vector_[*it]);
		it = ind_list.erase(it);
	}

	return names_vector_[*it];
}

int main()
{
	std::vector<std::string> names_vector;
	std::vector<std::string> droped_order;
	std::string names;
	std::string winner;

	std::cout << "Enter Names With Comma:" << std::endl;
	stq::string_input(names);
	stq::str_vector_from_input(names_vector, names);

	winner = CountingRhyme(names_vector, droped_order, 3);

	std::cout << "Winner: " << winner << std::endl;
	std::cout << "Drop Out Order: "; stq::vector_output(droped_order);

	return 0;
}

// TODO: add cecker if container is empty in insert's

// pop_front & pop_back							- throw 1 : nothing to pop
// CircularListClass(int size_)					- throw 2 : size can not be negative value
// void insert(int index_, int data_), erases	- throw 3 : index out of range
// int erase(int first_, int last_)				- throw 4 : left border can not be greater than right one

// Jack, Emory, Clara, Pouder, Vi, Jace, Caitlyn