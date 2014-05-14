/*
 * HashtableTest.cpp
 *
 *  Created on: Jul 24, 2013
 *      Author: eweil
 */
#include "Hashtable.cpp"
#include <string>
#include <iostream>

int main(){
	Hashtable hash(10);
	hash.insert("Hello", "wierd");
	hash.insert("Hash", "thekeysaresoclose");
	hash.insert("table", "buttheyshouldnot");
	hash.insert("craziness", "pushittothelimits");
	hash.insert("COLLISION!!!!!!", "bethissuperclose");
	hash.insert("addingmore", "123092119213");
	hash.insert("pushittothelimit!","95sadjl324lkads");
	hash.insert("ads1", "sakdhj");
	hash.insert("allthewaytothelimit", "sak5442j");
	std::cout<<"the value is "+ hash.getValue("thekeysaresoclose")<<std::endl;
  	hash.remove("buttheyshouldnot");
	std::cout<<"The full hashtable is below"<<std::endl;
	hash.printAll();
	return 0;
}



