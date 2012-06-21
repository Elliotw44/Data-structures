#include <iostream>
#include <fstream>
using namespace std;

#include "list2.h"

List::List()
{
 size = 0;
 head = NULL;
}

List::List(const List* list)
{
 size = list->size;
 if (list->head == NULL)
     head = NULL;
 else
    {
     head = new node;
     head->item = list->head->item;
     node* newPtr = head;
     for(node* origPtr = list->head->next; origPtr != NULL; origPtr = origPtr->next)
         {
	      newPtr->next = new node;
	      newPtr = newPtr->next;
	      newPtr->item = origPtr->item;
         }
     newPtr->next = NULL;
    }
}

void List::Reverse()
{
	node* middlePtr;
	node* forwardPtr;
	
	if(size <= 1)
		return;
	else if(size == 2)
		{
			forwardPtr = head -> next;
			head -> next = NULL;
			forwardPtr -> next = head;
			head = forwardPtr;
			forwardPtr = NULL;
			return;
		}
	else
		{
			middlePtr = head -> next;
			head -> next = NULL;
			for(int i = 1; i < size; i++)
			 {
				forwardPtr = middlePtr -> next;
				middlePtr -> next = head;
				head = middlePtr;
				middlePtr = forwardPtr;
			 }
			return;
	    }				
}

void List::RecursiveRev(node* oldHead, node* cur)
{
	node* forward;
	if (head != NULL)
		{
			oldHead = head;
			cur = oldHead -> next;
			oldHead -> next = NULL;
			head = NULL;
		}
	else if(cur-> next != NULL)
		{
			forward = cur -> next;
			cur -> next = oldHead;
			oldHead = cur;
			cur = forward;
		}
	else
		{	
			cur -> next = oldHead;
			oldHead = cur;
			head = oldHead;
			oldHead = NULL;
			cur = NULL;
			return;
		}
	RecursiveRev(oldHead, cur);
}
		
			
 
List::~List()
{
 while(size > 0)
   remove(1);
}

bool List::isEmpty() const
{
 if (size > 0)
    return false;
 else
    return true;
}


int List::getLength() const
{
 return size;
}

void List::display()
{
 node* newPtr = head;
 while (newPtr != NULL)
       {
        cout << newPtr->item << endl;
        newPtr = newPtr->next;
       }
}

bool List::insert(itemType newItem)
{ 

 node* newPtr = new node;
 if (newPtr == NULL)
     return false;

 newPtr->item = newItem;
 newPtr->next = head;
 head = newPtr;
 size++;
 return true;
}

bool List::insert(int pos, itemType newItem)
{
 
 if (pos < 1 || pos > (size + 1))
     return false;
 if (pos == 1)
     return(insert(newItem));
     
 node* newPtr = new node;
 if (newPtr == NULL)
     return false;
 node* prev = ptrTo(pos - 1);
 newPtr->next = prev->next;
 prev->next = newPtr;
 newPtr->item = newItem;
 size++;
 return true;
}


bool List::remove(int pos)
{
	node* cur;
	node* prev;
	
	if (pos < 1 || pos > size)
	    return false;
	if (pos == 1)
	    {
		 cur = head;
		 head = cur->next;
		}
	else
	    {
		 prev = ptrTo(pos - 1);
		 cur = prev->next;
		 prev->next = cur->next;
	    }
	
    cur->next = NULL;
    delete cur;
    cur = NULL;
    size--;
    return true;
}
bool List::get(int pos, itemType& item)
{

 node* cur;
 if (pos < 1 || pos > size)
	 return false;

 int i = 1;
 cur = head;
 while (i < pos)
 {
  cur = cur->next;
  i++;
 }
 item = cur->item;
 return true;
}	
node* List::ptrTo(int pos)
{
 node* prev = head;
 for (int i = 1; i < pos; i++)
     prev = prev->next;
 return prev;
}

bool List::find(itemType item)
{
 node* find;
 find = ptrTo(1);
 while(find->next != NULL)
  {   
   if(find->item == item)
     return true;
   find = find->next;
  } 
  return false;
}
bool List::GetLast(int pos, itemType& item)
{
 node* end;
 if (pos < 1 || pos > size)
	 return false;

 int i = 1;
 end = ptrTo(pos-1);
 end = end->next;
 item = end->item;
 return true;
}	

