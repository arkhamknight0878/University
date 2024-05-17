#pragma once

typedef struct QueueElement
{
	void* data;
	struct QueueElement* next;
}QueueElement;

typedef struct Queue
{
	QueueElement* top;
	QueueElement* back;
	size_t size;
}Queue;

void Queue_Push(Queue* queue_, void* data_);

void* Queue_Pop(Queue* queue_);