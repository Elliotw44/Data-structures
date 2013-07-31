#include "binSearchTree.h"
using namespace std;

int main() 
{

  BinSearchTree tree;
  tree.insert(10);
  tree.insert(5);
  tree.insert(8);
  tree.insert(6);
  tree.insert(7);
  tree.insert(16);
  tree.insert(20);
  tree.insert(14);
  tree.insert(15);
  tree.insert(5);
  tree.insert(2);
  tree.insert(4);
  tree.insert(1);
  tree.insert(12);
  tree.insert(13);
  cout << "printing the whole tree below" << endl;
  tree.BFSPrint(cout);

  cout<< "testing remove cases below" << endl;
  tree.removeItem(10);
  cout <<endl << "10 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  tree.removeItem(16); 
  cout << endl<<"16 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  tree.removeItem(6); 
  cout << endl<<"6 removed from the tree" << endl << endl;
  tree.BFSPrint(cout); 
  tree.removeItem(15); 
  cout << endl<<"15 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  cout<< "printing the whole tree after values being removed"<<endl;
  //tree.BFSPrint(cout);
  


}

