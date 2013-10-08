#include <iostream>
#include <string>
#include <unordered_map>
#include<queue>
#include<array>
#include<vector>
using namespace std;
//finds the first unique char in a string then returns it. If not unique char exist returns '#'
char findUnq(string input);
vector<int> PosNegArray(array<int,10> array);
// using most common datastructures with the c++ librarys(warning c++ 11 required)
int main() 
{
  unordered_map<string, int> hash1;
  hash1["E30"] = 1;
  hash1["E36"] = 2;
  hash1["E46"] = 3;
  hash1["E9X"] = 4;
  hash1["F30"] = 5;
  hash1["E30"] = 7; //overrides the original value of 1
  cout<< "The E30 is the " <<hash1["E30"]<< " generation of 3 series." << endl;
  cout<< hash1.count("F30") << endl;
  cout<< hash1.count("E60") <<endl;
  hash1.erase("E30");
  for( auto it = hash1.begin(); it != hash1.end(); ++it){
  		cout<<it->first<< ":"<<it->second<<", ";
  }
 cout<< endl;
 array<int,10> arr1 = {3,-5,-3,7,1,-10,12,-15,-4, 2};
unordered_map<int, int> Sums;
cout<<"The ordered Array is: "<<endl;
vector<int> ordered = PosNegArray(arr1);
for(int i = 0; i < ordered.size(); i++){
  cout<<ordered[i]<< ", ";
 }
 cout<< endl;
int index1 = 0;
int index2 = 0;
int sum = 0;
 for(int j = 0; j < 10; j++){
    sum += arr1[j];
	if(Sums.count(sum) == 1){
	  index1 = Sums[sum];
	  index2 = j;
	}
	else if(sum == 0){
		index1 = 0;
		index2 = j;
		Sums[sum] = j;
	}
	else
		Sums[sum] = j;
}

for (++index1; index1 <= index2; index1++){
	cout<< arr1[index1] << ", ";
}
cout <<endl;

cout<<findUnq("SBSBEfefe")<<endl;
cout<<findUnq("SSSBBSAaaAERER")<<endl;

  return 0;
}


char findUnq(string input){
unordered_map<char, int> CharCount;
for(int i = 0; i < input.length(); i++){
 if(CharCount.count(input[i]) >= 1){
   unordered_map<char,int>::iterator iter = CharCount.find(input[i]);
   CharCount[input[i]] = iter->second + 1;
 }
 else{
   CharCount[input[i]] = 1;
  }
 }
for( auto iter2 = CharCount.begin(); iter2 != CharCount.end(); iter2++){
  if(iter2->second == 1) {
  	return iter2->first;
  }
}

return '#';
}

vector<int> PosNegArray(array<int, 10> array){
 queue<int> Nque;
 queue<int> Pque;
 vector<int> final;
 for(int i = 0; i < array.size() ; i++){
     if(array[i] < 0)
	     Nque.push(array[i]);
	 else
	 	Pque.push(array[i]);
 }
 while(!Nque.empty() || !Pque.empty()){
   if(!Nque.empty()){
     final.push_back(Nque.front());
	 Nque.pop();
   }
   if(!Pque.empty()){
    final.push_back(Pque.front());
    Pque.pop();
   }
 }
 return final;
}
