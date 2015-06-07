#include "binSearchTree.h"
using namespace std;

int main() 
{
  bool treeFormed = false;
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
  cout<<"LCA of 13 7: " << tree.LCA(13,7) << endl;
  cout << "printing the whole tree below" << endl;
  tree.BFSPrint(cout);
  treeFormed = tree.WellFormed();
  cout<<"is the tree well formed? : "<<treeFormed<<endl;
  cout<< "testing remove cases below" << endl;
  tree.remove(10);
  cout <<endl << "10 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  tree.remove(16); 
  cout << endl<<"16 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  tree.remove(6); 
  cout << endl<<"6 removed from the tree" << endl << endl;
  tree.BFSPrint(cout); 
  tree.remove(15); 
  cout << endl<<"15 removed from the tree" << endl << endl;
  tree.BFSPrint(cout);
  tree.remove(8);
  tree.remove(5);
  cout << endl << "8 then 5 have been removed from the tree" <<endl << endl;
  treeFormed = tree.WellFormed();
  cout<<"is the tree well formed? : "<<treeFormed<<endl;
  tree.BFSPrint(cout);
  tree.remove(12);
  tree.remove(20);
  cout<< endl<< "12 then 20 have been removed from the tree"<<endl << endl;
  tree.BFSPrint(cout);
  tree.remove(2);
  tree.remove(1);
  tree.remove(7);
  tree.remove(4);
  tree.BFSPrint(cout);
  tree.remove(13);
  tree.BFSPrint(cout);
  tree.remove(14);
  cout<< "printing the whole tree after values being removed"<<endl;
  tree.BFSPrint(cout);
  


}

