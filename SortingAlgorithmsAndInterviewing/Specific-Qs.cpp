/*
 * Specific-Qs.cpp
 *
 *  Elliot Weil
 *  contains randomish questions I've been asked
 */

#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


bool VersNumComp(string s1, string s2);

void FourColoredBallsGame(string guess, string answer);

list<string> sortVersionNums(list<string> unsorted);

void perfectStringShuffle(string& s1);

int main()
{
  srand (time(NULL));
  //Question is to sort a list of version numbers.
  string uns[8] = {"10.542","1.10","1.5","1.75","2.0","1.15","1.55","2.1"};
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
    
    
    //4 location score
	FourColoredBallsGame("RGRY", "RGRY");
	//zero scores
	FourColoredBallsGame("RGGR", "YBYB");
	//4 color score
	FourColoredBallsGame("BYRG", "GRBY");
	//2 color and 2 location
	FourColoredBallsGame("BGRY", "YGRB");


  string maS = "randomThis";
  perfectStringShuffle(maS);
  cout <<"The randomly shuffled verions of randomThis is: "<<  maS << endl;
    
    
  	return 0;
}

void perfectStringShuffle(string& s1) {
  int index = s1.length() - 1;
  for(int i =0; i < s1.length(); i++){
       int randomPos = rand() % index-i + i;
       char temp = s1[i];
       s1[i] = s1[randomPos];
       s1[randomPos] = temp;
  }
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
// in the sorted list. O(n^2)
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

//please note that I had to make a fair amount of assumptions because of the lack of clarity for this question. examples below
//color scores can be used only once so example BRYY(g) and GBBB(a) is a color score 1
//location scores cannot also be used for color scores example BRYY(g) BBGG(a) is a location score of 1
//I felt that these were not defined well in the questions
//Big O(N^2) time complexity because for each value you tmpGuess we go through all of tmpAnswer. But since N is always 4 its not that bad.
void FourColoredBallsGame(string guess, string answer){
	if(guess.length() != 4){
		cout<<"please give a valid guess. ex:'BGYR'"<<endl;
		return;
	}
	//force to uppercase
	for(int i = 0; i < 4; i++){
		if(guess[i] == 'b')
        guess[i] = 'B';
		if(guess[i] == 'g')
        guess[i] = 'G';
		if(guess[i] == 'r')
        guess[i] = 'R';
		if(guess[i] == 'y')
        guess[i] = 'Y';
	}
	int locationScore = 0;
	int colorScore = 0;
	//create temp variables as I will _ chars out as they get counted towards score
	string tmpGuess = guess;
	string tmpAnswer = answer;
	//first for loop calc location score and replace any scored varaibles with _
	for(int i = 0; i < 4; i++){
		if(tmpGuess[i] == tmpAnswer[i]){
			locationScore++;
			tmpGuess[i] = '_';
			tmpAnswer[i] = '_';
		}
	}
	//now second foor loop will calc the color score using the tmp variables which have had all previous scoring values removed from the string
	for(int i =0; i < 4; i++){
		if(tmpGuess[i] == '_')
        continue;
		for(int j = 0; j < 4; j++){
			if(tmpAnswer[j] == '_')
            continue;
			if(tmpAnswer[j] == tmpGuess[i]){
				colorScore++;
				tmpAnswer[j] = '_';
				break;
			}
		}
	}
	//now just print the results
	cout<<"Your guess was: "<< guess<< " The answer was: "<<answer<<" your location score= "<<locationScore<<" and your color score= "<<colorScore<<endl;
}
