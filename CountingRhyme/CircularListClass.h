#pragma once

#include <iostream>

class Iterator
{
private:
	struct Node* ptr;
public:
	int& operator* () const;

	Iterator& operator=(Node* node_);

	Iterator& operator=(const Iterator& other_);

	bool operator== (const Iterator& other_) const;

	bool operator!=(const Iterator& other_) const;

	Iterator operator+(int amount_);

	Iterator& operator+=(int amount_);

	Iterator& operator++();

	Iterator& operator++(int);

	friend class CircularListClass;
};

struct Node
{
	int data = 0;
	Node* next = nullptr;

	Node() { data = 0; next = nullptr; }

	Node(int data_, Node* next_) { data = data_; next = next_; }

	Node& operator= (const Node& other_) { data = other_.data; next = other_.next; }
};

class CircularListClass
{
private:
	Node* first;
	Node* last;
	int size;
public:
	/**
	 * @brief : Default constructor
	 */
	CircularListClass();

	/**
	 * @brief : Constructs a list with count_ default-inserted objects
	 * @param count_ : The size of the container
	 */
	CircularListClass(int count_);

	/**
	 * @brief : Constructs a list with count_ copies of elements with value value_
	 * @param count_ : The size of the container
	 * @param value_ : The value to initialize elements of the container with
	 */
	CircularListClass(int count_, int value_);

	/**
	 * @brief : Constructs a list with the contents of the range [first_; last_]
	 * @param first_, last_ : The to copy elements from
	 * @param  : Dummy argument
	 */
	CircularListClass(int first_, int last_, int);

	/**
	 * @brief : Copy constructor
	 * @param other_ : Another container to use as data source
	 */
	CircularListClass(const CircularListClass& other_);

	/**
	 * @brief : Destructor
	 */
	~CircularListClass();

	/**
	 * @brief : Returns an iterator to the first element of the list
	 * @return : Iterator to the first element
	 */
	Iterator begin() const;

	/**
	 * @brief : Returns an iterator to the last element of the list
	 * @return : Iterator to the last element
	 */
	Iterator end() const;

	/**
	 * @brief : Copy assignment operator. Replaces the contents with a copy of the contents of other_.
	 * @param other_ : Another container to use as data source
	 * @return : *this
	 */
	CircularListClass& operator= (const CircularListClass& other_);

	/**
	 * @brief : Checks if the contnts of *this and other_ are equal: same size & same elements arrangement & values
	 * @param other_ : List which contents is compared
	 * @return : true if the contents of the lists are equal, false otherwise.
	 */
	bool operator== (const CircularListClass& other_) const;

	/**
	 * @brief : Checks if the contnts of *this and other_ are not equal
	 * @param other_ : List which contents is compared
	 * @return : false if the contents of the lists are equal, true otherwise.
	 */
	bool operator!= (const CircularListClass& other_) const;

	/**
	 * @brief : Erases all elements from the container.
	 */
	void clear();

	/**
	 * @brief : Prepends element with new_data_ value to the begining of the container
	 * @param new_data_ : the value of prepended element
	 * @return : Iterator to prepended element (first element)
	 */
	Iterator push_front(int new_data_);

	/**
	 * @brief : Prepends element with new_data_ value to the end of the container
	 * @param new_data_ : the value of prepended element
	 * @return : Iterator to prepended element (last element)
	 */
	Iterator push_back(int new_data_);

	/**
	 * @brief : Inserts element with new_data_ value before the index_ element of the container
	 * @param index_ : Index of inserted element
	 * @param data_ : Value of inserted element
	 * @return : Iterator to inserted element
	 */
	Iterator insert(Iterator& pos_, int data_);

	/**
	 * @brief : Inserts emount_ elements with new_data_ value before the index_ element of the container
	 * @param index_ : 	Index of element before which the content will be inserted
	 * @param amount_ : amount of unserted elements
	 * @param data_ : the value of inserted elements
	 * @return 
	 */
	Iterator insert(Iterator& pos_, int amount_, int data_);

	/**
	 * @brief : Inserts elements with copies of values in range [first_; last_] before the index_ element of the container
	 * @param index_ : Index of element before which the content will be inserted
	 * @param first_, last_ : The range of elements to insert, cannot be iterators into container for which insert is called
	 * @param  : Dummy argument
	 * @return : Iterator pointing to the first element inserted
	 */
	Iterator insert(Iterator& index_, int first_, int last_, int);

	/**
	 * @brief : Removes the first element of the container
	 */
	void pop_front();

	/**
	 * @brief : Removes the last element of the container
	 */
	void pop_back();

	/**
	 * @brief : Removes the element at index_ position
	 * @param index_ : Index of removed element
	 * @return : Iterator following the last removed element.
	 */
	Iterator erase(Iterator& index_);

	/**
	 * @brief : Removes the elements with indexes in range [first_; last_]
	 * @param first_, last_ : The range of elements to erase
	 * @return : Iterator following the last removed element.
	 */
	// Iterator erase(int first_, int last_);

	/**
	 * @brief : Replaces the contents with new_size_ copies of value_ value
	 * @param new_size_ : The new size of the container
	 * @param value_ : The value to initialize elements of the container with
	 */
	void assign(int new_size_, int value_);

	/**
	 * @brief : Replaces the contents with copies of those in the range [first; last]
	 * @param first_, last_: The range to copy the elements from
	 * @param  : Dummy argument
	 */
	void assign(int first_, int last_, int);

	/**
	 * @brief : Checkes if the container is empty
	 * @return : True if container is empty, false otherwise
	 */
	bool empty();

	/**
	 * @brief : Returns the number of elements in the container
	 * @return : The number of elements in the container
	 */
	int get_size();

	/**
	 * @brief : Returns a reference to the first element in the container
	 * @return : Reference to the first element in the container
	 */
	int& get_first();

	/**
	 * @brief : Returns a reference to the last element in the container
	 * @return : Reference to the last element in the container
	 */
	int& get_last();
};