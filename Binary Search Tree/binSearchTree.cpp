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

// Initialize count of nodes that have been created
int BinSearchTree::Node::createdNodes = 0;

int BinSearchTree::numberOfCreatedNodes() {
    return Node::nodeCount();
}

BinSearchTree::BinSearchTree(const BinSearchTree& rhsTree)
{
    nodeCount = rhsTree.nodeCount;
    copyTraverse(rhsTree.root, root);
}

BinSearchTree& BinSearchTree::operator=(const BinSearchTree& rhsTree)
{
    if (root == rhsTree.root)
        return *this;
    else
    {
        copyTraverse(rhsTree.root, root);
        return*this;
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

void BinSearchTree::insert(const int anItem, LoopType type)
{
    if (type == LoopType::Recursive)
        recursiveInsert(root, anItem);
    else if (type == LoopType::Iterative)
        iterativeInsert(root, NULL, anItem);
}

void BinSearchTree::recursiveInsert(Node*& subtreeRoot, const int anItem)
{

    if (subtreeRoot == NULL)
    {
        subtreeRoot = new Node(anItem);
        nodeCount++;
    } else if (subtreeRoot->item == anItem) {
        cout << "Item exists\n";
        return;
    } else if (anItem < subtreeRoot->item) {
        recursiveInsert((subtreeRoot->leftChild), anItem);
    } else {
        recursiveInsert((subtreeRoot->rightChild), anItem);
    }
}

void BinSearchTree::iterativeInsert(Node*& subtreeRoot, Node* parentNode, const int anItem) {
    Node* helper = subtreeRoot;
    while (helper != NULL)
    {
        if (helper->item == anItem)
            return;
        parentNode = helper;
        helper = anItem > helper->item ? helper->rightChild : helper->leftChild;
    }
    if (parentNode){
        Node* node = new Node(anItem);
        if (anItem > parentNode->item) {
            parentNode->rightChild = node;
        } else {
            parentNode->leftChild = node;
        }
    }
    else
    {
        subtreeRoot = new Node(anItem);
    }
}

bool BinSearchTree::lookup(const int anItem, LoopType type)
{
    bool found;
    if (type == LoopType::Recursive)
        found = recursiveGet(root, anItem);
    else if (type == LoopType::Iterative)
        found = iterativeGet(root, anItem);
    return found;
}

bool BinSearchTree::recursiveGet(const Node* subtreeRoot, const int anItem)
{
    if (subtreeRoot == NULL)
        return false;
    else if (anItem == subtreeRoot->item)
        return true;
    else
        return(recursiveGet(subtreeRoot->rightChild, anItem) || recursiveGet(subtreeRoot->leftChild, anItem));
}

bool BinSearchTree::iterativeGet(const Node* subtreeRoot, const int anItem) {
    while (subtreeRoot != NULL)
    {
        if (subtreeRoot->item == anItem)
            return true;
        subtreeRoot = anItem > subtreeRoot->item ? subtreeRoot->rightChild : subtreeRoot->leftChild;
    }
    return false;
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
    if (root == NULL)
    {
        cout << "The Tree is empty!" << endl;
        return;
    }
    int curLevel = 1;
    int nextLevel = 0;
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node* tmp = que.front();
        que.pop();
        curLevel--;
        out << tmp->item << " ";
        if (tmp->leftChild != NULL)
        {
            que.push(tmp->leftChild);
            nextLevel += 1;
        }
        if (tmp->rightChild != NULL)
        {
            que.push(tmp->rightChild);
            nextLevel += 1;
        }
        if (curLevel == 0)
        {
            out << endl;
            curLevel = nextLevel;
            nextLevel = 0;
        }

    }
}

void BinSearchTree::preTraverse(const Node* subtreeRoot, ostream& out) const
{
    if (subtreeRoot == NULL)
        return;
    out << subtreeRoot->item << "\n";
    preTraverse(subtreeRoot->leftChild, out);
    preTraverse(subtreeRoot->rightChild, out);
}

void BinSearchTree::inTraverse(const Node* subtreeRoot, ostream& out) const
{

    if (subtreeRoot == NULL)
        return;
    inTraverse(subtreeRoot->leftChild, out);
    out << subtreeRoot->item << "\n";
    inTraverse(subtreeRoot->rightChild, out);
}

void BinSearchTree::postTraverse(const Node* subtreeRoot, ostream& out) const
{
    if (subtreeRoot == NULL)
        return;
    postTraverse(subtreeRoot->leftChild, out);
    postTraverse(subtreeRoot->rightChild, out);
    out << subtreeRoot->item << "\n";
}

void BinSearchTree::destructTraverse(Node* subtreeRoot)
{
    if (subtreeRoot == NULL)
        return;
    destructTraverse(subtreeRoot->leftChild);
    destructTraverse(subtreeRoot->rightChild);
    delete(subtreeRoot);
}

void BinSearchTree::copyTraverse(const Node* subtreeRoot, Node*& newRoot)
{
    if (subtreeRoot == NULL)
        newRoot = NULL;
    else
    {
        newRoot = new Node;
        newRoot->item = subtreeRoot->item;
        copyTraverse(subtreeRoot->leftChild, newRoot->leftChild);
        copyTraverse(subtreeRoot->rightChild, newRoot->rightChild);
    }
}

int BinSearchTree::getHeight(const Node* subnode) const
{

    if (subnode == NULL)
        return -1;
    int heightR = getHeight(subnode->rightChild);
    int heightL = getHeight(subnode->leftChild);
    if (heightR > heightL)
        return heightR + 1;
    else
        return heightL + 1;
}

bool BinSearchTree::FormedTraverse(const Node* subtreeRoot) const
{
    if (subtreeRoot == NULL)
        return true;

    else if (((getHeight(subtreeRoot->leftChild) - getHeight(subtreeRoot->rightChild)) > 1) ||
        ((getHeight(subtreeRoot->leftChild) - getHeight(subtreeRoot->rightChild)) < -1))
    {
        return false;
    }
    return(FormedTraverse(subtreeRoot->rightChild) && FormedTraverse(subtreeRoot->leftChild));
}

bool BinSearchTree::WellFormed()
{
    bool Formed = FormedTraverse(root);
    return Formed;
}

void BinSearchTree::remove(const int anItem, LoopType type)
{
    if (root == NULL)
        cout << " The tree is empty." << endl;
    else if (root != NULL)
    {
        if (!lookup(anItem))
            cout << "The item isn't in the tree." << endl;
        else
            if (type == LoopType::Recursive)
                recursiveDelete(anItem);
            else if (type == LoopType::Iterative)
                iterativeDelete(root, NULL, anItem);
            
        nodeCount--;
    }
}

void BinSearchTree::recursiveDelete(const int anItem) {
    root = recursiveDelete(root, anItem);
}

BinSearchTree::Node* BinSearchTree::recursiveDelete(BinSearchTree::Node* x, const int anItem) {
    if (x == NULL) return NULL;
    if (anItem < x->item) {
        x->leftChild = recursiveDelete(x->leftChild, anItem);
    } else if (anItem > x->item) {
        x->rightChild = recursiveDelete(x->rightChild, anItem);
    } else {
        if (x->rightChild == NULL) {
            Node* t = x->leftChild;
            delete x;
            return t;
        }
        if (x->leftChild == NULL) {
            Node* t = x->rightChild;
            delete x;
            return t;
        }
        int newValue;
        x->rightChild = twoChildDeleteHelper(x->rightChild, newValue);
        x->item = newValue;
    }

    return x;
}

BinSearchTree::Node* BinSearchTree::twoChildDeleteHelper(Node* x, int& value) {
    if (x->leftChild == NULL) {
        Node* t = x->rightChild;
        value = x->item;
        delete x;
        return t;
    }
    x->leftChild = twoChildDeleteHelper(x->leftChild, value);
    return x;
}

int BinSearchTree::min() {
    return min(root)->item;
}

BinSearchTree::Node* BinSearchTree::min(BinSearchTree::Node* x) {
    if (x->leftChild == NULL) return x;
    return min(x->leftChild);
}

void BinSearchTree::iterativeDelete(Node*& subtreeRoot, Node* parentNode, const int anItem) {
    Node* helper = subtreeRoot;
    while (helper->item != anItem) {
        if (helper == NULL)
            return;
        parentNode = helper;
        helper = anItem > helper->item ? helper->rightChild : helper->leftChild;
    }
    if (helper->item == root->item){
        if (helper->rightChild != NULL ^ helper->leftChild != NULL){
            subtreeRoot = helper->leftChild == NULL ? subtreeRoot = helper->rightChild : helper->leftChild;
            delete helper;
            return;
        }
        if (helper->rightChild == NULL && helper->leftChild == NULL){
            subtreeRoot = NULL;
            delete helper;
            return;
        }
    }
    if (helper->leftChild == NULL || helper->rightChild == NULL){
        iterativeNodeDelete(helper, parentNode);
        return;
    }
    
    Node* successor = helper->rightChild;
    Node* successorParent = helper;
    while (successor->leftChild != NULL) {
        successorParent = successor;
        successor = successor->leftChild;
    }

    helper->item = iterativeNodeDelete(successor, successorParent);
}

int BinSearchTree::iterativeNodeDelete(Node* toBeDeleted, Node* parentPointer) {
    bool onRight = toBeDeleted->item > parentPointer->item ? true : false;
    int successorValue = toBeDeleted->item;

    if (toBeDeleted->rightChild == NULL) {
        if (onRight){
            parentPointer->rightChild = toBeDeleted->leftChild;
        } else {
            parentPointer->leftChild = toBeDeleted->leftChild;
        }
        delete toBeDeleted;
    } else {
        if (onRight){
            parentPointer->rightChild = toBeDeleted->rightChild;
        } else {
            parentPointer->leftChild = toBeDeleted->rightChild;
        }
        delete toBeDeleted;
    }

    return successorValue;
}

int BinSearchTree::LCA(const int NodeA, const int NodeB)
{
    Node* LCA = LCAHelp(NodeA, NodeB, root);
    if (LCA != NULL)
        return LCA->item;
    else
        return -1;
}

BinSearchTree::Node*  BinSearchTree::LCAHelp(const int NodeAValue, const int NodeBValue, Node* subRoot)
{
    if (subRoot == NULL)
        return NULL;
    bool AOnRight = recursiveGet(subRoot->rightChild, NodeAValue);
    bool BOnRight = recursiveGet(subRoot->rightChild, NodeBValue);
    if (AOnRight != BOnRight)
        return subRoot;
    else if (AOnRight && BOnRight)
        return(LCAHelp(NodeAValue, NodeBValue, subRoot->rightChild));
    else
        return(LCAHelp(NodeAValue, NodeBValue, subRoot->leftChild));


}