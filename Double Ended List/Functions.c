#include "Functions.h"

#include <stdio.h>

void Push_Back(List* list_, void* data_)
{
	ListElement* element = malloc(sizeof(ListElement));
	if (!element)
		return NULL;

	element->data = data_;
	element->next = NULL;

	if (list_->size == 0)
	{
		list_->top = element;

		element->prev = NULL;
	}
	else
	{
		list_->back->next = element;

		element->prev = list_->back;
	}

	list_->back = element;
	list_->size++;
}

void Push_Front(List* list_, void* data_)
{
	ListElement* element = malloc(sizeof(ListElement));
	if (!element)
		return;

	element->data = data_;
	element->prev = NULL;

	if (list_->size == 0)
	{
		list_->back = element;

		element->next = NULL;
	}
	else
	{
		list_->top->prev = element;

		element->next = list_->top;
	}

	list_->top = element;
	list_->size++;
}

void* Pop_Back(List* list_)
{
	if (!list_ || list_->size)
		return NULL;

	void* data = list_->back->data;

	ListElement* temp = list_->back;

	if (list_->back->prev == NULL)
	{
		list_->back = NULL;
		list_->top = NULL;
	}
	else
	{
		list_->back = list_->back->prev;
		list_->back->next = NULL;
	}

	free(temp);
	list_->size--;

	return data;
}

void* Pop_Front(List* list_)
{
	if (!list_ || list_->size)
		return NULL;

	void* data = list_->top->data;
	ListElement* temp = list_->back;

	if (list_->top->next == NULL)
	{
		list_->top = NULL;
		list_->back = NULL;
	}
	else
	{
		list_->top = list_->top->next;
		list_->top->prev = NULL;
	}

	free(temp);
	list_->size--;

	return data;
}

ListElement* Find(List* list_, void* data_)
{
	if (!list_ || list_->size == 0)
		return NULL;

	ListElement* element = list_->top;

	while (element != NULL)
	{
		if (element->data == data_)
			break;

		element = element->next;
	}

	return element;
}

bool Erase(List* list_, void* data_)
{
	if (!list_ || list_->size == 0)
		return false;

	ListElement* element = Find(list_, data_);

	if (list_->size == 1)
		Pop_Front(list_);

	if (element->next == NULL)
		Pop_Back(list_);
	else if (element->prev == NULL)
		Pop_Front(list_);
	else
	{
		element->next->prev = element->prev;
		element->prev->next = element->next;
	}

	free(element);
	list_->size--;

	return true;
}

bool Insert(List* list_, void* data1_, void* data2_)
{
	if (!list_ || list_->size == 0)
		return false;

	ListElement* element = Find(list_, data1_);

	ListElement* new_element = malloc(sizeof(ListElement));
	if (!new_element)
		return false;

	new_element->data = data2_;

	if (element->prev == NULL)
		Push_Front(list_, data2_);
	else
	{
		new_element->next = element;
		new_element->prev = element->prev;

		element->prev->next = new_element;
		element->prev = new_element;
	}

	return true;
}

void List_Print(List* list_)
{
	if (!list_ || list_->size == 0)
		return;

	ListElement* element = list_->top;

	while (element != NULL)
	{
		int data = *((int*)element->data);
		printf("%d", data);

		element = element->next;
	}
	printf("\n");
}
