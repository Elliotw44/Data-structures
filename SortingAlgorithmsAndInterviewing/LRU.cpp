//
//  LRU.cpp
//  lineQ
//
//  Created by Elliot Weil on 8/15/14.
//  Copyright (c) 2014 Elliot Weil. All rights reserved.
//
#include <iostream>
#include <unordered_map>

using namespace std;

class LRU {
public:
    
    LRU(int n){
        try{
            if(n<= 0)
                throw 1;
            size = n;
            head = NULL;
            tail = NULL;
            curSize = 0;
        }
        catch(int e){
            if(e == 1)
                cout<<"please enter a size above 0"<<endl;
            exit(e);
        }
    }
    ~LRU(){};
    //Check if the cache is full
    bool isCacheFull(){
        return(curSize == size);
    }
    //add an entry to the cache
    //input is the memory address of the item
    void addToCache(int address){
        if(hashMap.count(address) > 0){ //if its in the queue then delete it
            node* ptr = hashMap[address];
            deleteNode(ptr);
        }
        else if(isCacheFull()){ //the cache is full so remove the oldest item
            hashMap.erase(head->item);
            deleteNode(head);
        }
        addNode(address); //add the new item
        hashMap[address] = tail; //save its location in the hash
    }
    //print out the complete cache
    void printCache(){
        if(head == NULL){
            cout<<"Empty Cache"<<endl;
            return;
        }
        node* ptr = head;
        while(ptr != NULL){
            cout<<ptr->item<<' ';
            ptr = ptr->next;
        }
        cout<<endl;
    }
private:
    //struct for an entry in the LRU. Similary to a doublely LL
    struct node{
        int item;
        node* next;
        node* prev;
    };
    unordered_map<int, node*> hashMap;
    node *head; //head pointer of doublely LL
    node *tail; //tail pointer of doublely LL
    int curSize; //current number of items in the list
    int size; //max items
    
    
    //Doublely LL functions below
    //delete a node from the LL structure within the hash
    void deleteNode(node* nodeToDelete){
        if(curSize == 1){ //deleteing the last item in the queue
            head = NULL;
            tail = NULL;
        }
        else if(nodeToDelete == head){ //delete the head
            head = head->next;
            head->prev = NULL;
        }
        else if(nodeToDelete == tail){ //delete the tail
            tail = tail->prev;
            tail->next = NULL;
        }
        else{ //delete a middle node
            node* prevNode = nodeToDelete->prev;
            node* nextNode = nodeToDelete->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        
        delete nodeToDelete;
        nodeToDelete = NULL;
        curSize--;
    }
    //push a node onto the end of the LL structure similary to a queue
    void addNode(int address){
        node* newPtr = new node;
        newPtr->item = address;
        newPtr->next = NULL;
        newPtr->prev = NULL;
        if(curSize == 0){//empty LL structure
            head = newPtr;
            tail = newPtr;
        }
        else{//normal case
            tail->next = newPtr;
            newPtr->prev = tail;
            tail = tail->next;
        }
        newPtr = NULL;
        curSize++;
    }
};