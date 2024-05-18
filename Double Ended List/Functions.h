#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement
{
	void* data;
	struct ListElement* next;
	struct ListElement* prev;
}ListElement;

typedef struct List
{
	ListElement* top;
	ListElement* back;
	size_t size;
}List;

void Push_Back(List* list_, void* data_);

void Push_Front(List* list_, void* data_);

void* Pop_Back(List* list_);

void* Pop_Front(List* list_);

ListElement* Find(List* list_, void* data_);

bool Erase(List* list_, void* data_);

bool Insert(List* list_, void* data1_, void* data2_);

void List_Print(List* list_);