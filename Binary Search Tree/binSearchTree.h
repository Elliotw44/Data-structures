/**
* The BinSearchTree class uses a node struct with a left and right child.
* The BinSearchTree takes in int to insert. implenting both BFS abd DFS.
*
* @author Elliot Weil
* @file binsearchtree.h
*/

#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <queue>
#include <iostream>
using namespace std;

class BinSearchTree {
public:
/**
* default constructor to create an empty tree
*/
BinSearchTree();


/**
* default destructor to create an empty tree
*/
~BinSearchTree();

/**
* this is a copy constructor for tree
* @param rhsTree
*/
BinSearchTree(const BinSearchTree& rhsTree);

/**
* Overloaded assignment operator for the class BinSearchTree
* @param rhsTree
*/
BinSearchTree& operator=(const BinSearchTree& rhsTree);

/**
* tests if the tree is empty
* @return true or false
*/
bool isEmpty() const;

/**
* returns the number of nodes in a tree
* @return  nodeCount
*/
int getNodeCount() const;

/**
* inserts a entry into the the tree.
* @param anItem
*/
void insert(const int anItem);

bool delete(const int anItem);

/**
* This looks up a key in the and then returns true if it finds it, otherwise false
* @param searchKey
*/ 
bool lookup(const int anItem);

/*
* Visit the node the first then traverse
* @param out
*/
void preOrderPrint(ostream& out) const;

/*
* Traverse left then visit the node then traverse right
* @param out
*/
void inOrderPrint(ostream& out) const;

/*
* Traverse left and right then visit the node
* @param out
*/
void postOrderPrint(ostream& out) const;

void BFSPrint(ostream& out) const;

void remove(const int anItem);

protected:

struct Node {
int item;
Node* leftChild;
Node* rightChild;
};
Node* root;
// count of nodes
int nodeCount;

/**
* Traverses the tree in preorder
*@ param subtreeRoot
*@ param out
*/
void preTraverse(const Node* subtreeRoot, ostream& out) const;

/**
* Traverses the tree in inorder
*@ param subtreeRoot
*@ param out
*/
void inTraverse(const Node* subtreeRoot, ostream& out)const;

/**
* Traverses the tree in postorder
*@ param subtreeRoot
*@ param out
*/
void postTraverse(const Node* subtreeRoot, ostream& out)const;

/**
* Traverses the tree in preorder and copies the tree into a new tree
*@ param subtreeRoot
*@ param newRoot
*/
void copyTraverse(const Node* subtreeRoot, Node*& newRoot);

/**
* Traverses the tree in postorder and deletes the nodes
*@ param subtreeRoot
*
*/
void destructTraverse(Node* subtreeRoot);

/**
* Traverses the tree in inorder and inserts the nodes at leaf positions
*@ param subtreeRoot
*@ param Item
*/
void insertTraverse(Node*& subtreeRoot, const int anItem);

/**
* Traverses the tree in preorder and checks the item it if matchs the key
*@ param subtreeRoot
*@ param Found
*@ param Key
*/
bool lookupTraverse(const Node* subtreeRoot,int anItem, bool& Found);

void deleteTraverse(Node*& subtreeRoot, Node*& parent, const int anItem);

void adopt1(Node* subtreeRoot, Node*& parent);

void adopt2(Node* subtreeRoot);

Node* inOrderSuc(Node* subtreeRoot);
};
#endif
