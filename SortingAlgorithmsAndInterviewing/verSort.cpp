/*
 * verSort.cpp
 *
 *  Created on: Aug 1, 2013
 *  Elliot Weil
 *  Contains mergesort, insertion sort, binary Search, and a string compare for strings of version numbers
 */

#include <iostream>
#include <list>
#include <vector>
#include <math.h>
using namespace std;

void findTuples(vector<int> array);

bool VersNumComp(string s1, string s2);

list<string> sortVersionNums(list<string> unsorted);

vector<int> MergeSort(vector<int> unsorted);

vector<int> Merge(vector<int> sublist1, vector<int> sublist2);

bool binarySearch(vector<int> array, int item);

vector<int> selectSort(vector<int> array);

vector<int> quickSort(vector<int> array);
int main()
{
    string uns[8] = {"10.542","1.10","1.5","1.75","2.0","1.15","1.55","2.1"};
    int uns2[] = {5,8,7,2,10,1,3,4,6,9};
    vector<int> unsort;
    unsort.assign(uns2, uns2+10);
	list<string> unsortedVs(uns, uns + 8);
	cout<<"The original unsorted list of version numbers is below" << endl;
	for(list<string>::iterator it = unsortedVs.begin(); it != unsortedVs.end(); it++)
		cout<<" "<< *it;
	cout<<endl;
	list<string> sortedVs = sortVersionNums(unsortedVs);
	cout << endl << "The sorted list of version numbers is below" << endl;
	for(list<string>::iterator its = sortedVs.begin(); its != sortedVs.end(); its++)
			cout<<" "<< *its;
    cout<<endl<<endl;
    cout<<"The unsorted array of integers is below."<<endl;
    for(int i = 0;  i < unsort.size(); i++)
    	cout<< unsort[i] << ", ";
    cout<< endl << endl <<"The array sorted with mergesort is below." <<endl;
    vector<int> sortedA = selectSort(unsort);
    for(int i = 0; i < sortedA.size(); i++)
    	cout<< sortedA[i] << ", ";
    cout<<endl<<endl<<"The Tuples for the list above are below."<<endl;
    findTuples(unsort);
    cout<<endl;

    cout<<"The unsorted array of integers is below."<<endl;
        for(int i = 0;  i < unsort.size(); i++)
        	cout<< unsort[i] << ", ";
    cout<<endl<<"testing quicksort"<<endl;
    vector<int> quickSorted = quickSort(unsort);
    for(int i = 0; i < quickSorted.size(); i++)
        	cout<< sortedA[i] << ", ";
    cout<<endl;
	return 0;
}
//Function takes to strings s1, and s2 both strings contain version numbers ex(10.2, 1.92, 2.0)
//Returns true if s1 is higher version number then s2.
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
//implmenting insertion sort with two lists. Taking items from the unsorted list and adding them in the correct spot
// in the sorted list. The two While loops looks make it clear to the O(n^2) cost.
list<string> sortVersionNums(list<string> unsorted){

	list<string> sorted;
	while(!unsorted.empty()){
     string itemToSort = unsorted.front();
	 unsorted.pop_front();
	 if(sorted.empty()){
		 //if the sorted list is empty just push the first item n
	 	sorted.push_front(itemToSort);
		continue;
	 }
     list<string>::iterator sortedIt = sorted.begin();
     //adding the unsorted item into its correct spot in the sorted list
     while(sortedIt != sorted.end()){
    	 //if the itemToSort is less then the current item
    	 if(!VersNumComp(itemToSort, *sortedIt )){
    		 //insert here and break
    		 sorted.insert(sortedIt, itemToSort);
			 break;
    	 }
    	 sortedIt++;
     }
     //if nothing in the list is less then the current item add to the end
	 if(sortedIt == sorted.end())
	 	sorted.push_back(itemToSort);
    }
	return sorted;
}
//int vector MergeSort in c++
vector<int> MergeSort(vector<int> unsorted){
	//basecase if the array you passed in was of size one or smaller
	if(unsorted.size() <= 1)
			return unsorted;
	else{
		//find middle index of array unsorted
		int middle = unsorted.size() / 2;
		//make two smaller arrays half the size of unsorted. firstHalf, and secondHalf.
		vector<int> firstHalf;
		vector<int> secondHalf;
		firstHalf.resize(middle);
		if((unsorted.size() % 2) != 0)
			secondHalf.resize(middle+1);
		else
			secondHalf.resize(middle);

		//fill firstHalf with the first half of unsorted
		for(int i = 0; i < middle; i++){
			firstHalf[i] = unsorted[i];
		}
		//fill secondHalf with the second half of unsorted
		for(int j = 0; j < secondHalf.size(); j++){
			secondHalf[j] = unsorted[j+middle];
		}
		//recursives calls to keep spliting the array in half
		firstHalf = MergeSort(firstHalf);
		secondHalf = MergeSort(secondHalf);
		//Now do the sorting in the merge step
		return Merge(firstHalf, secondHalf);
	}

}
//Merge step in MergeStep
vector<int> Merge(vector<int> sublist1, vector<int> sublist2){
	//new sorted array
	vector<int> sorted;
	sorted.resize(sublist1.size() + sublist2.size());
	//two ints to keep track of where we are in each subarray
	int i = 0;
	int j = 0;
	//while both list aren't empty
	while(sublist1.size() != i || sublist2.size() != j){
		//if both list aren't empty
		if(sublist1.size() != i && sublist2.size() != j){
			//compare if sublist1's item is smaller then sublist2's.
			if(sublist1[i] <= sublist2[j]){
				sorted[i+j] = sublist1[i]; //if so add sublist1's item to sorted.
				i++;
			}
			else{
				sorted[i+j] = sublist2[j];//else add sublist2's item to sorted.
				j++;
			}
		}
		//if the first half of the list is empty
		else if(sublist1.size() == i){
			//add items from the sublist2 because sublist1 is empty.
			sorted[i+j] = sublist2[j];
			j++;
		}
		else{
			//add items from the sublist1 because sublist2 is empty.
			sorted[i+j] = sublist1[i];
			i++;
		}
	}
	return sorted;
}
//binarySearch for a vector(dynamic array) of ints
bool binarySearch(vector<int> array, int item){
	int middle;
	int searchStart = 0;
	int searchEnd = array.size() - 1;
	if(item < array[searchStart] || item > array[searchEnd]){
		return false;
	}
	middle = (searchStart + searchEnd) / 2;
	while(searchStart != middle && searchEnd != middle){
		if(item == array[middle] || item == array[middle+1])
			return true;
		else if(item > array[middle])
			searchStart = middle;
		else
			searchEnd = middle;
		middle = (searchStart + searchEnd) / 2;
	}
	return false;
}
//find all the a^2 + b^2 = c^2 combinations in a given array
void findTuples(vector<int> array){
	//sort the array
	vector<int> sorted = MergeSort(array);
	vector<int> sortedSq(sorted.size(), 0);
	vector<int> valuesToSearch;
	//square every value you in the sorted array and store it in a new array
	int possibleA;
	for(int i = 0; i < sorted.size(); i++){
		sortedSq[i] = sorted[i] * sorted[i];
	}
	//set the first possible C to the last item then work down to the 3rd spot in the list
	for(int c = sorted.size() - 1; c > 1; c--){
		//for each C check
		for(int b = (c-1); b > 0; b--){
			possibleA = sortedSq[c] - sortedSq[b];
			valuesToSearch = sortedSq;
			valuesToSearch.resize(b);
			if(binarySearch(valuesToSearch, possibleA)){
				//check to see if the sqrt is positive or negative
				if(binarySearch(sorted, sqrt(possibleA))){
					cout<< sqrt(possibleA) << "^2 + "<< sorted[b]<< "^2 = "<<sorted[c]<<"^2"<< endl;
				}
				else
				{
					cout<< sqrt(possibleA)*-1<<"^2 + "<< sorted[b]<<"^2 = "<< sorted[c]<<"^2" << endl;
				}

			}
		}
	}
}
//selection sort implmented for vectors(dynamic arrays)
vector<int> selectSort(vector<int> array){
	int tmp,minIndex;
	for(int i = 0; i < array.size(); i++){
		minIndex = i;
		for(int j = i; j < array.size(); j++ ){
			if(array[j] < array[minIndex])
				minIndex = j;
		}
		tmp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = tmp;
	}
	return array;
}
//quick sort implemented for vectors of int
vector<int> quickSort(vector<int> array){
	//base case
	if (array.size() <= 1)
		return array;
	//set the pivot as the last item in the array
	vector<int> pivot(1, array.back());
	//remove the pivot from the array
	array.pop_back();
	//create two sub vectors, one less then the pivot and one greater then the pivot
	vector<int> lesserThenPivot;
	vector<int> greaterThenPivot;
	//go through the array and insert items into the sub vectors where they belong
	for(int i = 0; i < array.size(); i++){
		if(array[i] <= pivot[0])
			lesserThenPivot.push_back(array[i]);
		else
			greaterThenPivot.push_back(array[i]);
	}
	//recurse through the vectors creating small and smaller sub vectors to sort
	lesserThenPivot = quickSort(lesserThenPivot);
	greaterThenPivot = quickSort(greaterThenPivot);
	//recreate the orginal vector passed in now knowing that everything is sorted correctly
	lesserThenPivot.push_back(pivot[0]);
	lesserThenPivot.insert(lesserThenPivot.end(), greaterThenPivot.begin(), greaterThenPivot.end());
	return lesserThenPivot;
}
