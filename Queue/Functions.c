#include "Functions.h"

#include <stdlib.h>

void Queue_Push(Queue* queue_, void* data_)
{
	QueueElement* element = malloc(sizeof(QueueElement));
	if (!element)
		return;

	element->data = data_;
	element->next = NULL;

	if (queue_->size == 0)
		queue_->top = element;
	else
		queue_->back->next = element;

	queue_->back = element;
	queue_->size++;
}

void* Queue_Pop(Queue* queue_)
{
	if (!queue_)
		return NULL;

	void* data = queue_->top->data;

	QueueElement* temp = queue_->top;

	queue_->top = queue_->top->next;

	free(temp);
	queue_->size--;

	return data;
}
