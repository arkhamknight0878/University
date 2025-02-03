#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class CircleListClass
{
private:
	Node* first;
	int amount;
	Node* Find(int key_);
public:
	CircleListClass() { amount = 0; first = nullptr; }

	CircleListClass(vector<int> arr_);

	~CircleListClass();

	void DeleteNode(Node* to_delete_)
	{
		if (amount == 1)
			delete to_delete_;

		Node* tmp = to_delete_->next;
		Node* back = first;
		while (back->next != tmp)
			back = back->next;

		if (tmp == first)
			back->next = first;
		else if (to_delete_ == first)
			first = to_delete_->next;

		delete to_delete_;
		--amount;
	}

	void DeleteByCount(int k_, vector<string>& delete_order_, string* names_arr_)
	{
		if (!amount)
			return;

		Node* current = first;

		while (amount != 1)
		{
			for (int i = 1; i < k_; ++i)
				current = current->next;

			Node* tmp = current->next;
			delete_order_.push_back(names_arr_[current->data]);
			delete current;
			current = tmp;
		}
	}

	friend ostream& operator<< (ostream& ostream_, CircleListClass& class_);
};

