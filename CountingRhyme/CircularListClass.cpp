#include "CircularListClass.h"

int& Iterator::operator*() const { return ptr->data; }

Iterator& Iterator::operator=(Node* node_)
{
	this->ptr = node_;
	return *this;
}

Iterator& Iterator::operator=(const Iterator& other_)
{
	this->ptr = other_.ptr;
	return *this;
}

bool Iterator::operator==(const Iterator& other_) const { return (((ptr->data == other_.ptr->data) && (ptr->next == other_.ptr->next)) ? true : false); }

bool Iterator::operator!=(const Iterator& other_) const { return !(*this == other_); }

Iterator Iterator::operator+(int amount_)
{
	Iterator new_it = *this;

	for (int i = 0; i < amount_; ++i)
		++new_it;

	return new_it;
}

Iterator& Iterator::operator+=(int amount_)
{
	for (int i = 0; i < amount_; ++i)
		++(*this);

	return *this;
}

Iterator& Iterator::operator++() { ptr = ptr->next; return *this; }

Iterator& Iterator::operator++(int)
{
	Iterator tmp = *this;

	if (ptr->next)
		ptr = ptr->next;
	else
		ptr = nullptr;

	return tmp;
}

CircularListClass::CircularListClass() { first = last = nullptr; size = 0; }

CircularListClass::CircularListClass(int count_)
{
	if (size < 0)
		throw 2;

	size = count_;

	if (!size)
	{
		first = last = nullptr;
	}
	else
	{
		first = new Node;

		Node* current = first;

		for (int i = 0; i < size - 1; ++i)
		{
			current->data = 0;
			current = current->next = new Node;
		}

		current->data = 0;
		current->next = first;
		last = current;
	}
}

CircularListClass::CircularListClass(int count_, int value_)
{
	if (size < 0)
		throw 2;

	size = count_;

	if (!size)
	{
		first = last = nullptr;
	}
	else
	{
		first = new Node;

		Node* current = first;

		for (int i = 0; i < size - 1; ++i)
		{
			current->data = value_;
			current = current->next = new Node;
		}

		current->data = value_;
		current->next = first;
		last = current;
	}
}

CircularListClass::CircularListClass(int first_, int last_, int)
{
	if (first_ > last_)
		throw 4;

	first = new Node;

	if (first_ == last_)
		size = 1;
	else
		size = last_ - first_ + 1;

	Node* current = first;

	for (int i = first_; i < last_; ++i)
	{
		current->data = i;
		current = current->next = new Node;
	}

	current->data = last_;
	current->next = first;
	last = current;
}

CircularListClass::CircularListClass(const CircularListClass& other_)
{
	size = other_.size;

	if (!size)
	{
		first = last = nullptr;
		return;
	}

	first = new Node;

	Node* current = first;
	Node* o_current = other_.first;

	while (o_current->next != other_.first)
	{
		current->data = o_current->data;
		current = current->next = new Node;

		o_current = o_current->next;
	}

	current->data = o_current->data;
	current->next = first;
	last = current;
}

CircularListClass::~CircularListClass()
{
	if (!size)
		return;
	else if (size == 1)
		delete first;
	else
	{
		Node* current = first;
		Node* c_next = first->next;

		while (c_next != last)
		{
			delete current;
			current = c_next;
			c_next = c_next->next;
		}

		delete current;
		delete c_next;
	}
}

Iterator CircularListClass::begin() const
{
	Iterator it;
	it.ptr = first;

	return it;
}

Iterator CircularListClass::end() const
{
	Iterator it;
	it.ptr = last;

	return it;
}

CircularListClass& CircularListClass::operator=(const CircularListClass& other_)
{
	if (size)
		clear();

	size = other_.size;

	if (!size)
	{
		first = last = nullptr;
		return *this;
	}

	first = new Node;

	Node* current = first;
	Node* o_current = other_.first;

	while (o_current->next != other_.first)
	{
		current->data = o_current->data;
		current = current->next = new Node;

		o_current = o_current->next;
	}

	current->data = o_current->data;
	current->next = first;
	last = current;

	return *this;
}

bool CircularListClass::operator==(const CircularListClass& other_) const
{
	if (size != other_.size)
		return false;

	if (size == 1)
		return ((first->data == other_.first->data) ? true : false);

	Node* current = first;
	Node* o_current = other_.first;

	while (current->next != first)
	{
		if (current->data != o_current->data)
			return false;

		current = current->next;
		o_current = o_current->next;
	}

	return true;
}

bool CircularListClass::operator!=(const CircularListClass& other_) const { return !(*this == other_); }

void CircularListClass::clear()
{
	if (!size)
		return;
	else if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		Node* current = first;
		Node* c_next = first->next;

		while (c_next != last)
		{
			delete current;
			current = c_next;
			c_next = c_next->next;
		}

		delete current;
		delete c_next;

		first = last = nullptr;
		size = 0;
	}
}

Iterator CircularListClass::push_front(int new_data_)
{
	Iterator it;
	Node* new_node = new Node;
	new_node->data = new_data_;

	if (!size)
	{
		new_node->next = new_node;
		last = first = new_node;
	}
	else
	{
		Node* tmp = first;

		new_node->next = tmp;
		last->next = new_node;

		first = new_node;
	}

	++size;

	return (it = first);
}

Iterator CircularListClass::push_back(int new_data_)
{
	Iterator it;
	Node* new_node = new Node;
	new_node->data = new_data_;

	if (!size)
	{
		new_node->next = new_node;
		last = first = new_node;
	}
	else
	{
		Node* tmp = first;
		Node* current = first;

		while (current->next != first)
			current = current->next;

		current->next = new_node;
		new_node->next = tmp;

		last = new_node;
	}

	++size;

	return (it = last);
}

Iterator CircularListClass::insert(Iterator& pos_, int data_)
{
	Node* tmp = new Node(pos_.ptr->data, pos_.ptr->next);

	pos_.ptr->data = data_;
	pos_.ptr->next = tmp;

	if (pos_ == this->end())
		last = tmp;

	++size;

	return pos_;
}

Iterator CircularListClass::insert(Iterator& pos_, int amount_, int data_)
{
	if (amount_ < 0)
		throw 2;

	if (amount_)
	{
		if (!size)
			pos_.ptr = new Node;

		Iterator it_tmp = pos_;
		Node* node_tmp = new Node(pos_.ptr->data, pos_.ptr->next);

		for (int i = 0; i < amount_ - 1; ++i)
		{
			pos_.ptr->data = data_;
			pos_.ptr->next = new Node;

			++pos_;
		}

		pos_.ptr->data = data_;
		pos_.ptr->next = node_tmp;

		if (it_tmp == this->end() || !size)
			last = node_tmp;

		size += amount_;
	}

	return pos_;
}

Iterator CircularListClass::insert(Iterator& pos_, int first_, int last_, int)
{
	if (first_ > last_)
		throw 4;

	if (first_ == last_)
		return this->insert(pos_, first_);
	else
	{
		Iterator it_tmp = pos_;
		Node* node_tmp = new Node(pos_.ptr->data, pos_.ptr->next);

		for (int i = first_; i < last_ - 1; ++i)
		{
			pos_.ptr->data = i;
			pos_.ptr->next = new Node;

			++pos_;
		}

		pos_.ptr->data = last_;
		pos_.ptr->next = node_tmp;

		if (it_tmp == this->end() || !size)
			last = node_tmp;

		size += last_ + first_ - 1;
	}

	return pos_;

	/*if (first_ == last_)
	{
		if (!pos_ || !size)
			it = this->push_front(first_);
		else
			it =  this->insert(pos_, first_);
	}
	else
	{
		if (!pos_ || !size)
		{
			for (int i = last_; i >= first_; --i)
				push_front(i);

			it = first;
		}
		else if (pos_ == size + 1)
		{
			Node* current = last;

			for (int i = first_; i <= last_; ++i)
			{
				current = current->next = new Node;
				current->data = i;
			}

			it = last->next;
			current->next = first;
			last = current;

			size = last_ - first_ + 1;
		}
		else
		{
			Node* current = first;

			for (int i = 0; i < pos_ - 1; ++i)
				current = current->next;

			Node* it_tmp = current;
			Node* tmp = current->next;

			for (int i = first_; i <= last_; ++i)
			{
				current = current->next = new Node;
				current->data = i;
			}

			it = it_tmp->next;
			current->next = tmp;

			size = last_ - first_ + 1;
		}
	}

	return it;*/
}

void CircularListClass::pop_front()
{
	if (!size)
		throw 1;
	else if (size == 1)
	{
		delete first;
		last = first = nullptr;
	}
	else
	{
		Node* tmp = first->next;

		delete first;
		last->next = first = tmp;
	}
}

void CircularListClass::pop_back()
{

	if (!size)
		throw 1;
	else if (size == 1)
	{
		delete first;
		last = first = nullptr;
	}
	else
	{
		Node* current = first;

		while (current->next != last)
			current = current->next;

		delete current->next;

		current->next = first;
		last = current;
	}
}

Iterator CircularListClass::erase(Iterator& pos_)
{
	Node* to_delete = pos_.ptr;

	if (!size)
		pos_.ptr = nullptr;
	else
	{
		if ((to_delete == first && first->next == first))
		{
			delete first;
			pos_.ptr = first = nullptr;
		}
		else
		{
			Node* prev = first;

			while (prev->next != to_delete)
				prev = prev->next;

			if (to_delete == first)
				pos_.ptr = first = first->next;
			else if (to_delete == last)
			{
				pos_.ptr = prev->next = first;
				last = prev;
			}
			else
				pos_.ptr = prev->next = to_delete->next;

			delete to_delete;
		}
	}

	--size;
	return pos_;
}

//Iterator CircularListClass::erase(int first_, int last_)
//{
//	if (first_ < 0 || last_ > size - 1)
//		throw 3;
//
//	if (first_ > last_)
//		throw 4;
//
//	Iterator it;
//
//	Node* current;
//	Node* c_next;
//
//	if (first_ == last_)
//	{
//		it = this->erase(first_);
//		--size;
//	}
//	else if (!first_)
//	{
//			current = first;
//			c_next = first->next;
//
//			for (int i = first_; i <= last_; ++i)
//			{
//				delete current;
//				current = c_next;
//				c_next = c_next->next;
//			}
//
//			if (last_ == size - 1)
//				it = first = last = nullptr;
//			else
//				it = first = current;
//
//			size -= (last_ - first_ + 1);
//	}
//	else
//	{
//		current = first;
//
//		for (int i = 0; i < first_ - 1; ++i)
//			current = current->next;
//
//		Node* tmp = current;
//
//		current = current->next;
//		c_next = current->next;
//
//		for (int i = first_; i <= last_; ++i)
//		{
//			delete current;
//			current = c_next;
//			c_next = c_next->next;
//		}
//
//		if (last_ == size - 1)
//		{
//			tmp->next = first;
//			it = last = tmp;
//		}
//		else
//			it = tmp->next = current;
//
//		size -= (last_ - first_ + 1);
//	}
//
//	return it;
//}

void CircularListClass::assign(int new_size_, int value_)
{
	if (new_size_ < 0)
		throw 2;

	clear();

	if (!new_size_)
		return;

	first = new Node;
	Node* current = first;

	for (int i = 0; i < new_size_ - 1; ++i)
	{
		current->data = value_;
		current = current->next = new Node;

		++size;
	}

	current->data = value_;
	current->next = first;
	last = current;
}

void CircularListClass::assign(int first_, int last_, int)
{
	if (first_ > last_)
		throw 4;

	clear();

	if (first_ == last_)
		this->push_front(first_);
	else
	{
		first = new Node;
		size = last_ - first_ + 1;

		Node* current = first;

		for (int i = first_; i < last_; ++i)
		{
			current->data = i;
			current = current->next = new Node;
		}

		current->data = last_;
		current->next = first;
		last = current;
	}
}

bool CircularListClass::empty() { return ((!size) ? true : false); }

int CircularListClass::get_size() { return size; }

int& CircularListClass::get_first() { return first->data; }

int& CircularListClass::get_last() { return last->data; }
