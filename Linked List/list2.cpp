#include <iostream>
#include <fstream>
#include <queue>
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
//Reverses every N items in a linked listed
//I use two queues to keep track of the temporary Heads and Tails of the sub lists
//Each sub list is then reversed independantly and then re attached together
//Time: O(n)
void List::ReverseBySection(int n){
        if (n >= size) {
            this->Reverse();
            return;
        }
        if (n == 1) {
            return;
        }
        queue<node*> SubHeads; //queue to keep track of sub heads
        queue<node*> SubTails; //queue to keep track of sub tails
        node* runner = head;
        SubHeads.push(runner);
        runner = runner->next;
        int numGroups = size / n;
        int groups = 0;
        int i = 2;
        // go through the LL and push all subheads onto the queue and break apart the LL.
        // also note that the runner is also pointing to the start of any "extra" items
        while(groups < numGroups) {
            if(i % n == 0){
                node* tmp = runner->next;
                SubHeads.push(tmp);
                runner->next = NULL;
                runner=tmp;
                groups++;
                i++;
                continue;
                
            }
            runner = runner->next;
            i++;
        }
        //Go through the subHeads queue and remove each head one at a time and reverse that subsection.
        //After its reverse push the new head onto the back of the queue
        for (int i =0; i < SubHeads.size() - 1; i++) {
            node* tmpHead = SubHeads.front();
            node* middlePtr = tmpHead -> next;
            node* forwardPtr = middlePtr -> next;
            tmpHead->next = NULL;
            node* tmp = tmpHead;
            SubTails.push(tmp);
            //standard LL reverse code
            while(forwardPtr != NULL) {
                forwardPtr = middlePtr -> next;
                middlePtr -> next = tmpHead;
                tmpHead = middlePtr;
                middlePtr = forwardPtr;
                forwardPtr = forwardPtr->next;
            }
            middlePtr->next = tmpHead;
            tmpHead = middlePtr;
            SubHeads.push(tmpHead);
            SubHeads.pop();
        }
        //with everything reversed now we just have to reattach the sub LLs to reform the bigger LL
        SubHeads.pop();
        head = SubHeads.front();
        SubHeads.pop();
        while (SubTails.size() > 1) {
            node* tmp = SubTails.front();
            tmp->next = SubHeads.front();
            SubTails.pop();
            SubHeads.pop();
        }
        node* tmp = SubTails.front();
        tmp->next = runner;
        SubTails.pop();
}

//Reverses every N items in a linked listed
//This methond doesn't use any extra additional data-structures
//this moves through the LL and reverse each sub section while keeping track of the previous tail
//Time: O(n)
void List::ReverseBySectionNoExtraDS(int n){
    if (n >= size) {
        this->Reverse();
        return;
    }
    if (n == 1) {
        return;
    }
    node* prevTail;
    node* curTail;
    node* prev;
    node* curr;
    node* front;
    int numGroups = size / n;
    int curGroup = 0;
    curTail = head;
    prev = head;
    curr = prev->next;
    //while group one pass through for each group
    while (curGroup < numGroups) {
        curr = prev->next;
        for (int i= 1; i < n; i++) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        //if this is the first pass through set the head to new start of the list
        if(curGroup == 0)
        head = prev;
        else
        prevTail->next = prev; //else just set the prevTail->next to prev
        //move up the tail
        prevTail = curTail;
        //setup for next section
        prev = curr;
        //ending conidtion to see if I need to change the tail
        if((size % n == 0) && (curGroup == numGroups-1)) //I am the last group and there is no "extra" items so null out
        curTail->next = NULL;
        else if(curGroup == numGroups-1) // I am the last group and there are extra items so point my tail at them
        curTail->next = front;
        else
        curTail = prev;
        curGroup++;
    }
    
}

//standard LL reverse
void List::Reverse()
{
	node* middlePtr;
	node* forwardPtr;
	
	if(size <= 1)
		return;
	else
		{
		  middlePtr = head -> next;
          forwardPtr = middlePtr -> next;
		  head -> next = NULL;
		  while(forwardPtr != NULL)
		   {
		     forwardPtr = middlePtr -> next;
		     middlePtr -> next = head;
		     head = middlePtr;
		     middlePtr = forwardPtr;
		     forwardPtr = forwardPtr->next;
         }
		middlePtr->next = head;
		head = middlePtr;
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

