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
	bool found = lookupTraverse(root, anItem);
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

bool BinSearchTree::lookupTraverse(const Node* subtreeRoot,const int anItem)
{
  if(subtreeRoot == NULL)
  	return false;
  else if(anItem == subtreeRoot->item)
  	return true;
  else
   return(lookupTraverse(subtreeRoot->rightChild, anItem)||lookupTraverse(subtreeRoot->leftChild, anItem));
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

int BinSearchTree::getHeight(const Node* subnode) const
{

	if(subnode == NULL)
		return -1;
	int heightR = getHeight(subnode->rightChild);
	int heightL = getHeight(subnode->leftChild);
	if(heightR > heightL)
		return heightR + 1;
	else
		return heightL + 1;
}

bool BinSearchTree::FormedTraverse(const Node* subtreeRoot) const
{
 if(subtreeRoot == NULL) 
	 return true;
 else if(((getHeight(subtreeRoot->leftChild) - getHeight(subtreeRoot->rightChild)) > 1) ||
		 ((getHeight(subtreeRoot->leftChild) - getHeight(subtreeRoot->rightChild)) < -1)) 
		 {
			return false;
		 }
 return(FormedTraverse(subtreeRoot->rightChild) || FormedTraverse(subtreeRoot->leftChild));
}
bool BinSearchTree::WellFormed()
{
	bool Formed = FormedTraverse(root);
	return Formed;
}

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
	 //found the item to delete
     if(anItem == subtreeRoot->item)
	 {
    // check if the node to be delete has only one child
	  if((subtreeRoot->leftChild != NULL && 
	      subtreeRoot->rightChild == NULL) 
	     || (subtreeRoot->rightChild != NULL && 
		 subtreeRoot->leftChild == NULL)) 
	    {
		  //special case where you haven't recursed yet
		  if(parent == subtreeRoot){
			  if(parent->rightChild != NULL)
				  subtreeRoot = parent->rightChild;
			  else
				  subtreeRoot = parent->leftChild;
		  }
		  //adopt the one child of the node to be deleted.
	      adopt1(subtreeRoot, parent);
	    }
	  //check if node to be deleted has two children
	  else if(subtreeRoot->leftChild != NULL && 
		  subtreeRoot->rightChild != NULL)
	    {
		  //adopt both children.
	      adopt2(subtreeRoot);
	    }
	  //node to be deleted is a leaf node(a node with no children)
	  else if(subtreeRoot->leftChild == NULL && 
		  subtreeRoot->rightChild == NULL)
	    {
		  //check if its the root
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
     //if the item wasn't found recurse through the tree
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

int BinSearchTree::LCA(int NodeA, int NodeB)
{
	Node* LCA = LCAHelp(NodeA, NodeB, root);
	if(LCA != NULL)
		return LCA->item;
    else
		return -1;
}

BinSearchTree::Node*  BinSearchTree::LCAHelp(int NodeAValue, int NodeBValue, Node* subRoot)
{
	if(subRoot == NULL)
		return NULL;
	bool AOnRight = covers(NodeAValue,subRoot->rightChild);
	bool BOnRight = covers(NodeBValue,subRoot->rightChild);
	if(AOnRight !=  BOnRight)
		return subRoot;
	else if(AOnRight && BOnRight)
		return(LCAHelp(NodeAValue,NodeBValue,subRoot->rightChild));
	else
		return(LCAHelp(NodeAValue,NodeBValue,subRoot->leftChild));


}
bool BinSearchTree::covers(int PchildValue, Node* startNode)
{
	if(startNode == NULL)
		return false;
	else if(startNode->item == PchildValue)
		return true;

	return(covers(PchildValue,startNode->leftChild)||covers(PchildValue,startNode->rightChild));
}
