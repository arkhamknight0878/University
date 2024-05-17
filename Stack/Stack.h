#pragma once

#include <stdlib.h>

typedef struct StackElement
{
	void* data;
	struct StackElement* next;
}StackElement;

typedef struct Stack
{
	StackElement* top;
	size_t size;
}Stack;

void Stack_Push(Stack* stack_, void* data_);

void* Stack_Pop(Stack* stack_);