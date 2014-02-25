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
    lst->insert(8,8);
    lst->display();
    List lst4 = List(lst);
    List lst5 = List(lst);
    cout<<"testing sections size of 4 reverse"<<endl;
    lst->ReverseBySection(4);
    lst->display();
    cout<<"testing sections size of 3 reverse with no extra data structures"<<endl;
    lst5.ReverseBySectionNoExtraDS(3);
    lst5.display();
    lst4.Reverse();
    cout << "after Reverse"<< endl;
    lst4.display();
    cout << "lets try recursion"<< endl;
    lst4.display();
    lst4.RecursiveRev(testHead, testPtr);
    cout << "after Reverse"<< endl;
    lst4.display();
    cout << "testing list of length 2" <<endl;
    lst3->display();
    lst3->Reverse();
    lst3->display();
 return 0;
}
