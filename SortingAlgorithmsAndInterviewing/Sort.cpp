/*
 * Sort.cpp
 * Sorting function libray
 *
 *  Elliot Weil
 *  Contains mergesort, selection sort, binary search, quick sort */

#include <vector>
using namespace std;


//Merge step in MergeStep
vector<int> Merge(vector<int> sublist1, vector<int> sublist2){
	//new sorted array
	vector<int> sorted;
	sorted.resize(sublist1.size() + sublist2.size());
	//two counters to keep track of where we are in each subarray
	int i = 0;
	int j = 0;
	//while both list aren't empty
	while(sublist1.size() != i || sublist2.size() != j){
		if(sublist1.size() == i) //add items from the sublist2 because sublist1 is empty.
			sorted[i+j] = sublist2[j++];
		if(sublist2.size() == j)//add items from the sublist1 because sublist2 is empty.
			sorted[i+j] = sublist1[i++];
		else //Compare the items in both sublists and attach the smaller one
		    sorted[i+j] = sublist1[i] < sublist2[j]? sublist1[i++] : sublist[j++];
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

//binarySearch for a vector(dynamic array) of ints
bool binarySearch(vector<int> array, int item){
	int middle;
	int searchStart = 0;
	int searchEnd = array.size()-1;
	while(searchStart <= searchEnd){
    		middle = (searchStart + searchEnd) / 2;
    		if(item == array[middle])
        		return true;
		else if(item > array[middle])
        		searchStart = middle + 1;
		else
        		searchEnd = middle - 1;
	 }
  	return false;
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
