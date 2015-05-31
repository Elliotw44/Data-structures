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

bool BinSearchTree::lookupTraverse(const Node* subtreeRoot, const int anItem)
{
    if (subtreeRoot == NULL)
        return false;
    else if (anItem == subtreeRoot->item)
        return true;
    else
        return(lookupTraverse(subtreeRoot->rightChild, anItem) || lookupTraverse(subtreeRoot->leftChild, anItem));
}

void BinSearchTree::insertTraverse(Node*& subtreeRoot, const int anItem)
{

    if (subtreeRoot == NULL)
    {
        subtreeRoot = new Node;
        subtreeRoot->item = anItem;
        subtreeRoot->leftChild = NULL;
        subtreeRoot->rightChild = NULL;
        nodeCount++;
    } else if (subtreeRoot->item == anItem) {
        cout << "Item exists\n";
        return;
    } else if (anItem < subtreeRoot->item) {
        insertTraverse((subtreeRoot->leftChild), anItem);
    } else {
        insertTraverse((subtreeRoot->rightChild), anItem);
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

void BinSearchTree::removeItem(const int anItem)
{
    if (root == NULL)
        cout << " The tree is empty." << endl;
    else if (root != NULL)
    {
        if (!lookup(anItem))
            cout << "The item isn't in the tree." << endl;
        else
            deleteNode(anItem);
        nodeCount--;
    }
}

void BinSearchTree::deleteNode(const int anItem) {
    root = deleteNode(root, anItem);
}

BinSearchTree::Node* BinSearchTree::deleteNode(BinSearchTree::Node* x, const int anItem) {
    if (x == NULL) return NULL;
    if (anItem < x->item) {
        x->leftChild = deleteNode(x->leftChild, anItem);
    } else if (anItem > x->item) {
        x->rightChild = deleteNode(x->rightChild, anItem);
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

BinSearchTree::Node* BinSearchTree::inOrderSuc(Node* subtreeRoot)
{
    Node* finder = subtreeRoot;
    finder = subtreeRoot->rightChild;
    while (finder->leftChild != NULL && finder->leftChild->leftChild != NULL)
        finder = finder->leftChild;
    return finder;
}

int BinSearchTree::LCA(int NodeA, int NodeB)
{
    Node* LCA = LCAHelp(NodeA, NodeB, root);
    if (LCA != NULL)
        return LCA->item;
    else
        return -1;
}

BinSearchTree::Node*  BinSearchTree::LCAHelp(int NodeAValue, int NodeBValue, Node* subRoot)
{
    if (subRoot == NULL)
        return NULL;
    bool AOnRight = covers(NodeAValue, subRoot->rightChild);
    bool BOnRight = covers(NodeBValue, subRoot->rightChild);
    if (AOnRight != BOnRight)
        return subRoot;
    else if (AOnRight && BOnRight)
        return(LCAHelp(NodeAValue, NodeBValue, subRoot->rightChild));
    else
        return(LCAHelp(NodeAValue, NodeBValue, subRoot->leftChild));


}
bool BinSearchTree::covers(int PchildValue, Node* startNode)
{
    if (startNode == NULL)
        return false;
    else if (startNode->item == PchildValue)
        return true;

    return(covers(PchildValue, startNode->leftChild) || covers(PchildValue, startNode->rightChild));
}
