#include "list2.h"
#include <iostream>
using namespace std;



int main()
{
 int last;
 node* testHead;
 node* testPtr;
 
 List* lst3 = new List();
 lst3->insert(1,5);
 lst3->insert(2,6);
 
 List* lst2 = new List();
 lst2->insert(1,5);
 
 List* lst = new List();
 lst->insert(1,1);
 lst->insert(2,2);
 lst->insert(3,3);
 lst->insert(4,4);
 lst->insert(5,5);
 lst->insert(6,6);
 lst->insert(7,7);
 lst->display();
 lst->Reverse();
 cout << "after Reverse"<< endl;
 lst->display();
 cout << "lets try recursion"<< endl;
 lst->display();
 lst->RecursiveRev(testHead, testPtr);
 cout << "after Reverse"<< endl;
 lst->display();
 return 0;
}
