#pragma once


// Структура элементов двусвязного списка
typedef struct ListEl
{
   // Данные элемента списка
   void* data;

   // Указатель на следующий элемент списка
   ListEl* next;

   // Указатель на предыдущий элемент списка
   ListEl* prev;
}ListEl;

// Структура двусвязного списка
typedef struct List 
{
   // Указатель на первый элемент списока
   ListEl* front;

   // Указатель на последний элемент списка
   ListEl* back;

   // Размер списка
   unsigned int size;
}List;

void Push_back(List* list_, void* data);

void Push_front(List* list_, void* data);

void* Pop_back(List* list_);