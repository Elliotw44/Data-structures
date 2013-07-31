#include "binsearchtree.h"
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
  t1.BFSPrint(cout);

  cout<< "testing remove cases below" << endl;
  // t1.remove(10);
  // t1.remove(20);
  // t1.remove(7);
  // t1.remove(4);
  cout<< "printing the whole tree after values being removed"<<endl;
  t1.BFSPrint(cout);
  


}

