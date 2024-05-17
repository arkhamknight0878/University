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
		return;

	void* data = queue_->top->data;

	QueueElement* element = queue_->top->next;

	free(queue_->top);

	queue_->size--;
	queue_->top = element;

	return data;
}
