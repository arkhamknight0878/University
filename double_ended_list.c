#include <stdio.h>
#include "double_ended_list.h"

void Push_back(List* list_, void* data)
{
   if (list_ == NULL)
      return;

   ListEl* element = malloc(sizeof(ListEl));

   if (element == NULL)
      return;

   element->next = NULL;
   element->data = data;

   if (list_->size == 0)
   {
      element->prev = NULL;
      list_->front = element;
   }
   else
   {
      element->prev = list_->back;
      list_->back->next = element;
   }

   list_->back = element;
   list_->size++;
};

void Push_front(List* list_, void* data)
{
   if (list_ == NULL)
      return;

   ListEl* element = malloc(sizeof(ListEl));

   if (element == NULL)
      return;

   element->prev = NULL;
   element->data = data;

   if (list_->size == 0)
   {
      element->next = NULL;
      list_->back = element;
   }
   else
   {
      element->next = list_->front;
      list_->front->prev = element;
   }

   list_->front = element;
   list_->size++;
};

void* Pop_back(List* list_)
{
   if (list_ == NULL || list_->size == 0)
      return NULL;

   void* data = list_->back->data;
   ListEl* temp = list_->back;
   if (list_->back->prev == NULL)
   {
      list_->back = NULL;
      list_->front = NULL;
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