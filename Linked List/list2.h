#ifndef LIST_H
#define LIST_H
#include "types.h"


class List
{
 public:
   List();
   List(const List* list);
   ~List();
   
   void Reverse();
   
   void RecursiveRev(node* head, node* cur);
   
   bool isEmpty() const;
   int getLength() const;
   bool insert(int pos, itemType newitem); //inserts anywhere
   bool remove(int pos);
   /*
   Task: Retrieves the last item in the list
   Pre: An instance of the list has been created
   Post: Returns true and places item in the parameter item, if the list is not empty, false otherwise
   */
   bool GetLast(int pos, itemType& item);
   /*
   Task: Retrieves a specified item from a list
   Pre: An instance of the list has been created
   Post: Returns true and places item in the parameter item, if the specified node exists, false otherswise
   */
   bool get(int pos, itemType& item);
   /*
   Task: Determines if an item is in a list
    Pre: An instance of the list has been created
   Post: Returns true if the item is in the list, false otherwise
   */
   bool find(itemType item);
   void display();
   
   
   
   
 private:
   node* ptrTo(int pos); //used for inserting items past postion 1
   bool insert(itemType newItem); //inserts at the head of the list
   

   node* head;
   itemType* items;
   int size;
   
};
#endif
