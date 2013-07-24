/*
 * stack.h
 * A stack that stores integers that uses a struct node with a item value and a pointer to another node called next
 * The stack has a head which points to the top of the stack
 *  Created on: May 27, 2013
 *      Author: Elliot Weil
 *
 */

#ifndef STACK_H_
#define STACK_H_

class Stack {
public:
	Stack();
	~Stack();
	void push(int value); //add a value onto the stack
	int peek(); //look at the top value of the stack
	int pop(); //return the top value from the stack and then remove the item from the stack
	bool isEmpty(); //checks if the stack is empty, if it is return true

private:
	int size; //size of stack
	struct node{
		int item;
		node* next;
	};
	node* head;
};


#endif /* STACK_H_ */
