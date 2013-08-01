/*
 * verSort.cpp
 *
 *  Created on: Aug 1, 2013
 *      Author: eweil
 */
//returns true if S1 is smaller then S2
//returns false if S1 is bigger then S2
#include <iostream>
#include <list>
using namespace std;

bool VersNumComp(string s1, string s2);
list<string> sortVersionNums(list<string>);

int main()
{
    string uns[8] = {"10.542","1.10","1.5","1.75","2.0","1.15","1.55","2.1"};
	list<string> unsortedVs(uns, uns + 8);
	cout<<"The original unsorted list is below" << endl;
	for(list<string>::iterator it = unsortedVs.begin(); it != unsortedVs.end(); it++)
		cout<<" "<< *it;
	cout<<endl;
	list<string> sortedVs = sortVersionNums(unsortedVs);
	cout << endl << " The sorted list is below" << endl;
	for(list<string>::iterator its = sortedVs.begin(); its != sortedVs.end(); its++)
			cout<<" "<< *its;
    cout<<endl;
	return 0;
}
bool VersNumComp(string s1, string s2){
	int decIndex1 = s1.find('.');
 	int decIndex2 = s2.find('.');
    string beforeDec1 = s1.substr(0, decIndex1);
    string beforeDec2 = s2.substr(0, decIndex2);
	int bD1 = atoi(beforeDec1.c_str());
	int bD2 = atoi(beforeDec2.c_str());
    if(bD1 > bD2)
    	return true;
    else if(beforeDec1 == beforeDec2){
    	string afterDec1 =s1.substr(decIndex1+1, s1.length()-1);
    	string afterDec2 =s2.substr(decIndex2+1, s2.length()-1);
		int aD1 = atoi(afterDec1.c_str());
		int aD2 = atoi(afterDec2.c_str());
    	if(aD1 > aD2)
    		return true;
    	else
    		return false;
    }
    else
    	return false;

}

list<string> sortVersionNums(list<string> unsorted){

	list<string> sorted;
	while(!unsorted.empty()){
     string itemToSort = unsorted.front();
	 unsorted.pop_front();
	 if(sorted.empty()){
	 	sorted.push_front(itemToSort);
		continue;
	 }
     list<string>::iterator sortedIt = sorted.begin();
     while(sortedIt != sorted.end()){
    	 if(!VersNumComp(itemToSort, *sortedIt )){
    		 sorted.insert(sortedIt, itemToSort);
			 break;
    	 }
    	 sortedIt++;
     }
	 if(sortedIt == sorted.end())
	 	sorted.push_back(itemToSort);
    }
	return sorted;
}



