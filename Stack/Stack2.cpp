
/*
 * stack2.cpp
 *
 *  Created on: May 27, 2013
 *      Author: Elliot Weil
 *      Implementation of stack.h
 */


#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(){
	size = 0;
	head = NULL;
}

Stack::~Stack(){
	while(!isEmpty()){
		int temp = this->pop();
	}
}

void Stack::push(int value){
	if(head == NULL){
		head = new node;
		head->next = NULL;
		head->item = value;
	}
	else{
		node* temp = new node;
		temp->item = value;
		temp->next = head;
		head = temp;
		temp = NULL;
	}
	size++;//increment size
}

int Stack::peek() {
	if(head != NULL){
		return head->item;
	}
	else{
	 return 0; // return 0 if the list is empty
	}
}

int Stack::pop(){
	int temp = head->item;
	node* ptr = head->next;
	delete head;//delete old head node
	head = ptr;
	ptr = NULL;//null pointer
	size --;//Decrement size
	return temp;
}

bool Stack:: isEmpty(){
	return(size == 0);
}





