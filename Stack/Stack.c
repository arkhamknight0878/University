#include "Stack.h"

void Stack_Push(Stack* stack_, void* data_)
{
	if (!stack_)
		return;

	StackElement* element = malloc(sizeof(StackElement));
	if (!element)
		return;

	element->data = data_;
	element->next = stack_->top;

	stack_->size++;
	stack_->top = element;
}

void* Stack_Pop(Stack* stack_)
{
	if (stack_->size == 0)
		return;

	void* data = stack_->top->data;

	StackElement* element = stack_->top->next;

	free(stack_->top);

	stack_->size--;
	stack_->top = element;

	return data;
}
