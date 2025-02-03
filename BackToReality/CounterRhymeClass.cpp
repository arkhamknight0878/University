#include "CircleListClass.h"

Node* CircleListClass::Find(int key_)
{
	Node* current = first;

	do
	{
		if (current->data == key_)
			return current;

		current = current->next;
	} while (current != first);

	return nullptr;
}

CircleListClass::CircleListClass(vector<int> arr_)
{
	amount = (int)arr_.size();

	Node* current = first = new Node;

	for (int i = 0; i < amount; ++i)
	{
		current->data = arr_[i];
		current = current->next = new Node;
	}

	current->next = first;
}

CircleListClass::~CircleListClass()
{
	Node* current = first;
	if (!current)
		return;

	Node* c_next = current->next;

	do
	{
		delete current;
		current = c_next;
		c_next = c_next->next;
	} while (c_next != first);
}

ostream& operator<<(ostream& ostream_, CircleListClass& class_)
{
	Node* current = class_.first;
	if (current)
	{
		do
		{
			ostream_ << current->data << ", ";
			current = current->next;
		} while (current->next->next != class_.first);

		ostream_ << current->data;
	}
	else
		ostream_ << "There is No Elements in List" << endl;

	return ostream_;
}
