/*
 * Hashtable.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: eweil
 */
#include<string>
#include<iostream>
class Hashtable {
public:
	Hashtable(int size);
	virtual ~Hashtable();
	std::string getValue(const std::string key);
	void insert(std::string addMe, std::string);
	bool remove(const std::string key);
	void printAll();
private:
	int hash(const std::string key);
	int tablesize;
	int numofItems;
	struct Node {
	   std::string value;
	   std::string key;
	   Node* next;
   	};
   	Node** table;
};

Hashtable ::Hashtable(int size) {
	tablesize = size;
	numofItems = 0;
	table = new Node* [size];

}

Hashtable::~Hashtable() {
	Node* cur;
	for (int i = 0; i < tablesize; i++){
            cur = table[i];
            while(cur != 0){
            	Node* next = cur->next;
            	delete cur;
            	cur = next;
            }
            table[i] = 0;
	}
   cur = 0;
}

int Hashtable:: hash(const std::string key){
      unsigned int hash = 5381;
      for(unsigned int i =0; i < key.length(); i++)
    	  hash = ((hash << 5) + hash) + (unsigned int)key[i];
      return hash % tablesize;
}

std::string Hashtable::getValue(const std::string key){
	int index = hash(key);
    	if(table[index] == 0){
        	return "not Found";
    	}
	else{
    		Node* ptr = table[index];
       		while(ptr != 0){
    	   		if(ptr->key == key)
    		   		return ptr->value;
    	   		ptr = ptr->next;
       		}
       		return "not Found";
    	}
}

void Hashtable::insert(std::string addme, std::string key){
	int index = hash(key);
	Node* ptr = new Node;
	ptr->value = addme;
	ptr->key = key;
	ptr->next = table[index];
	table[index] = ptr;
	ptr = 0;
	numofItems++;
}

bool Hashtable::remove(const std::string key){
	int index = hash(key);
    	if(table[index] == 0){
        	return false;
    	}
    	else{
    		if(table[index]->key == key){
    			delete table[index];
    			table[index] = 0;
    		}
    		else{
    			Node* ptr = table[index];
    			Node* prev = ptr;
        		while(ptr != 0){
    	   			if(ptr->key == key){
    		   			prev->next = ptr-> next;
    		   			delete ptr;
    		   			break;
    	    			}
    	    			prev = ptr;
    	    			ptr = ptr->next;
        		}
        		ptr = 0;
        		prev = 0;
		}
    	}
    return true;
}

void Hashtable::printAll(){
	Node* cur;
	for (int i = 0; i < tablesize; i++){
		std::cout<<i<<std::endl;
            	cur = table[i];
            	while(cur != 0){
            		Node* next = cur->next;
                	std::cout <<cur->value<<std::endl;
            		cur = next;
            	}
	}
}

