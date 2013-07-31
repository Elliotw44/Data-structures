/**
* The BinSearchTree class uses a node struct with a left and right child.
* The BinSearchTree takes in int to insert. implenting both BFS abd DFS.
*
* @author Elliot weil
* @file binsearchtree.h
*/


#include "binSearchTree.h"
using namespace std;

BinSearchTree::BinSearchTree()
{
	root = NULL;
	nodeCount = 0;
	
}

BinSearchTree::~BinSearchTree()
{
	destructTraverse(root);
	root = NULL;
	nodeCount = 0;
}

BinSearchTree::BinSearchTree(const BinSearchTree& rhsTree)
{
	nodeCount = rhsTree.nodeCount;
	copyTraverse(rhsTree.root, root);
}

BinSearchTree& BinSearchTree::operator=(const BinSearchTree& rhsTree)
{
 if(root == rhsTree.root)
 	return *this;
 else
 {
   copyTraverse(rhsTree.root, root);
   return* this;
 }
}


bool BinSearchTree::isEmpty() const
{
	return(root == NULL);
}

int BinSearchTree::getNodeCount() const
{
	return nodeCount;
}

void BinSearchTree::insert(const int anItem)
{
 insertTraverse(root, anItem);		
}
bool BinSearchTree::lookup(const int anItem)
{
	bool found = false;
	lookupTraverse(root, anItem, found);
	return found;
}
void BinSearchTree::preOrderPrint(ostream& out) const
{
	preTraverse(root, out);
}

void BinSearchTree::inOrderPrint(ostream& out) const
{
	inTraverse(root, out);
	
}

void BinSearchTree::postOrderPrint(ostream& out) const
{
	postTraverse(root, out);
}

void BinSearchTree::BFSPrint(ostream& out) const
{
    if(root == NULL)
	{
		cout << "The Tree is empty!"<<endl;
		return;
	}
	int curLevel = 1;
	int nextLevel = 0;
	queue<Node*> que;
	que.push(root);
	while(!que.empty())
	{
		Node* tmp = que.front();
		que.pop();
		curLevel--;
		out << tmp->item << " ";
		if(tmp-> leftChild != NULL)
		{
			que.push(tmp->leftChild);
			nextLevel += 1;
		}
		if(tmp->rightChild != NULL)
		{
			que.push(tmp->rightChild);
			nextLevel += 1;
		}
		if(curLevel == 0 )
		{
			out << endl;
			curLevel = nextLevel;
			nextLevel = 0;
		}

	}
}

void BinSearchTree::preTraverse(const Node* subtreeRoot, ostream& out) const
{ 
  if(subtreeRoot == NULL) 
    return; 
  out << subtreeRoot->item << "\n";
  preTraverse(subtreeRoot->leftChild, out); 
  preTraverse(subtreeRoot->rightChild, out); 
} 

void BinSearchTree::inTraverse(const Node* subtreeRoot, ostream& out) const
{

  if(subtreeRoot == NULL)
    return; 
  inTraverse(subtreeRoot->leftChild, out);
  out << subtreeRoot->item << "\n"; 
  inTraverse(subtreeRoot->rightChild, out); 
} 
void BinSearchTree::postTraverse(const Node* subtreeRoot, ostream& out) const
{
 if(subtreeRoot == NULL) 
    return; 
  postTraverse(subtreeRoot->leftChild, out); 
  postTraverse(subtreeRoot->rightChild, out); 
  out << subtreeRoot->item << "\n"; 
}

void BinSearchTree::destructTraverse(Node* subtreeRoot)
{
 if(subtreeRoot == NULL) 
    return; 
  destructTraverse(subtreeRoot->leftChild); 
  destructTraverse(subtreeRoot->rightChild);
  delete(subtreeRoot);
}

void BinSearchTree::copyTraverse(const Node* subtreeRoot, Node*& newRoot)
{ 	
  if(subtreeRoot == NULL) 
    newRoot = NULL;
  else
   {
	newRoot = new Node; 
    newRoot->item = subtreeRoot->item;
    copyTraverse(subtreeRoot->leftChild, newRoot->leftChild); 
    copyTraverse(subtreeRoot->rightChild, newRoot->rightChild);
   } 
}

bool BinSearchTree::lookupTraverse(const Node* subtreeRoot,const int anItem, bool& Found)
{
 if(Found != true && subtreeRoot != NULL)
 { 
   if(anItem == subtreeRoot->item)
  	 Found = true;
  else if (anItem < subtreeRoot->item)
   lookupTraverse(subtreeRoot->leftChild, anItem, Found); 
  else
   lookupTraverse(subtreeRoot->rightChild, anItem, Found);
  }
 else
 	return Found;
}
	

void BinSearchTree::insertTraverse(Node*& subtreeRoot, const int anItem)
{

  if(subtreeRoot == NULL)
  {
    subtreeRoot = new Node;
    subtreeRoot->item = anItem;
    subtreeRoot->leftChild = NULL;
    subtreeRoot->rightChild = NULL;
    nodeCount ++;
  } 
  else if(subtreeRoot->item  == anItem) {
        cout << "Item exists\n";
  	return;
  }
  else if(anItem < subtreeRoot->item) {
     insertTraverse((subtreeRoot->leftChild), anItem);
  }
  else {
     insertTraverse((subtreeRoot->rightChild), anItem);
  }
}
/*
int BinSearchTree::HeightDifference(const Node* subnode)
{

	if(node == NULL)
	{
		return 0;
	}
	int heightR = 1 + getHeight(node->rightChild);
	int heightL = 1 + getHeight(node->leftChild);
	return (heightL - heightR)
	
}

bool BinSearchTree::FormedTraverse(const Node* subtreeRoot, bool& Formed) const
{
 if(subtreeRoot == NULL) 
	 return Formed;
 else if(HeightDifference(subtreeRoot) > 1 || HeightDifference(subtreeRoot) < 0)
	Formed = false;
 Formed = FormedTraverse(subtreeRoot->leftChild, Formed); 
 Formed = FormedTraverse(subtreeRoot->rightChild, Formed);  
}*/
/*
bool BinSearchTree::WellFormed(const Node* subtreeRoot)
{
	bool Formed = true;
	Formed = FormedTraverse(subtreeRoot, Formed);
	return Formed;
}*/

void BinSearchTree::removeItem(const int anItem)
{	
  if(root == NULL)
	cout << " The tree is empty."<< endl;
  else if(root != NULL)
    {
      if(!lookup(anItem))
			cout<< "The item isn't in the tree."<< endl;
      else
			deleteTraverse(root, root, anItem);
      nodeCount --;
    }
}

void BinSearchTree::deleteTraverse(Node*& subtreeRoot, Node* parent, const int anItem)
{
  if(subtreeRoot == NULL)
      return;
  else 
    {
     if(anItem == subtreeRoot->item)
	 {
	  if((subtreeRoot->leftChild != NULL && 
	      subtreeRoot->rightChild == NULL) 
	     || (subtreeRoot->rightChild != NULL && 
		 subtreeRoot->leftChild == NULL)) 
	    {
		  if(parent == subtreeRoot){
			  if(parent->rightChild != NULL)
				  subtreeRoot = parent->rightChild;
			  else
				  subtreeRoot = parent->leftChild;
		  }
	      adopt1(subtreeRoot, parent);
	    }
	  else if(subtreeRoot->leftChild != NULL && 
		  subtreeRoot->rightChild != NULL)
	    {
	      adopt2(subtreeRoot);
	    }
	  else if(subtreeRoot->leftChild == NULL && 
		  subtreeRoot->rightChild == NULL)
	    {
		  if(subtreeRoot == root)
		  {
			root = NULL;
			delete subtreeRoot;
			subtreeRoot = NULL;
		  }
	      else if(parent->leftChild == subtreeRoot)
		  {	
		 	parent->leftChild = NULL;
		  	delete subtreeRoot;
		  }
	      else
		  {
		  	parent->rightChild = NULL;
		  	delete subtreeRoot;
		  }		
	    }
	 }
    else
	{
	  parent = subtreeRoot;
	  if(anItem < subtreeRoot->item)
	    deleteTraverse(subtreeRoot->leftChild, parent, anItem);
	  else
	    deleteTraverse(subtreeRoot->rightChild, parent, anItem);
	}	
  }		
}

void BinSearchTree::adopt1(Node* subtreeRoot, Node*& parent)
{
  if(parent->leftChild == subtreeRoot)
    {
      if(subtreeRoot->leftChild == NULL)
	  {
	  	parent->leftChild = subtreeRoot->rightChild;
	  	delete subtreeRoot;
	  	subtreeRoot = NULL;
	  }
      else
	  {
	  	parent->leftChild = subtreeRoot->leftChild;
	  	delete subtreeRoot;
	  	subtreeRoot = NULL;
	  }
    }
  else 
    {
      if(subtreeRoot->rightChild == NULL)
	  {			
	  	parent->rightChild = subtreeRoot->leftChild;
	  	delete subtreeRoot;
	  	subtreeRoot = NULL;
	  }
      else
	  {			
	  	parent->rightChild = subtreeRoot->rightChild;
	  	delete subtreeRoot;
	  	subtreeRoot = NULL;
	  }
    }
}

void BinSearchTree::adopt2(Node* subtreeRoot)
{
  if(subtreeRoot->rightChild->leftChild == NULL) 
    {
      Node* tmp = subtreeRoot->rightChild;
      subtreeRoot->item = tmp -> item;
      subtreeRoot->rightChild = tmp -> rightChild;
      delete tmp;
	  tmp = NULL;
    }
  else 
    {
      Node* tmp = inOrderSuc(subtreeRoot);
      subtreeRoot->item = tmp->leftChild->item;
      Node* tmp2 = tmp->leftChild;
      tmp->leftChild = tmp2->rightChild;
      delete tmp2;
	  tmp = NULL;
	  tmp2 = NULL;
  }
}

BinSearchTree::Node* BinSearchTree ::inOrderSuc(Node* subtreeRoot)
{
  Node* finder = subtreeRoot;
  finder = subtreeRoot->rightChild;
  while(finder->leftChild != NULL && finder->leftChild->leftChild != NULL)
    finder = finder->leftChild;
  return finder;
}


				
				 
