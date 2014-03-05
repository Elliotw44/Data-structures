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
#include <assert.h>

using namespace std;


bool VersNumComp(string s1, string s2);

void FourColoredBallsGame(string guess, string answer);

list<string> sortVersionNums(list<string> unsorted);

void perfectStringShuffle(string& s1);

string TicTacToeAnaly(vector< vector<string> > board);


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
    
    //set up some tic tac toe boards!
	int numOfCols = 3;
	int numOfRows = 3;
    
    // all 8 different tic tac toe wins + empty board + random board
	vector<vector<string> > board1;
	board1.resize(numOfCols, vector<string>( numOfRows, ":e"));//empty board
    
	vector<vector<string> > board2;
	board2.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board2[0][0] = ":x"; //:x :x :x
	board2[0][1] = ":x"; //:e :e :e
	board2[0][2] = ":x"; //:e :e :e
    
	vector<vector<string> > board3;
	board3.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board3[1][0] = ":o"; //:e :e :e
	board3[1][1] = ":o"; //:o :o :o
	board3[1][2] = ":o"; //:e :e :e
    
	vector<vector<string> > board4;
	board4.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board4[2][0] = ":x"; //:e :e :e
	board4[2][1] = ":x"; //:e :e :e
	board4[2][2] = ":x"; //:x :x :x
    
	vector<vector<string> > board5;
	board5.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board5[0][0] = ":o"; //:o :e :e
	board5[1][0] = ":o"; //:o :e :e
	board5[2][0] = ":o"; //:o :e :e
    
	vector<vector<string> > board6;
	board6.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board6[0][1] = ":x"; //:e :x :e
	board6[1][1] = ":x"; //:e :x :e
	board6[2][1] = ":x"; //:e :x :e
    
	vector<vector<string> > board7;
	board7.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board7[0][2] = ":o"; //:e :e :o
	board7[1][2] = ":o"; //:e :e :o
	board7[2][2] = ":o"; //:e :e :o
    
	vector<vector<string> > board8;
	board8.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board8[0][0] = ":x"; //:x :e :e
	board8[1][1] = ":x"; //:e :x :e
	board8[2][2] = ":x"; //:e :e :x
    
	vector<vector<string> > board9;
	board9.resize(numOfCols, vector<string>( numOfRows, ":e"));
	board9[0][2] = ":o"; //:e :e :o
	board9[1][1] = ":o"; //:e :o :e
	board9[2][0] = ":o"; //:o :e :e
    
	vector<vector<string> > board10;
	board10.resize(numOfCols, vector<string>( numOfRows, ":o"));
	board10[1][0] = ":x";
    
	board10[0][2] = ":x"; //:o :o :x
	board10[1][1] = ":x"; //:x :x :o
	board10[2][0] = ":x"; //:x :o :o
    
    
	assert("nil" == TicTacToeAnaly(board1));
	assert(":x" == TicTacToeAnaly(board2));
	assert(":o" == TicTacToeAnaly(board3));
	assert(":x" == TicTacToeAnaly(board4));
	assert(":o" == TicTacToeAnaly(board5));
	assert(":x" == TicTacToeAnaly(board6));
	assert(":o" == TicTacToeAnaly(board7));
	assert(":x" == TicTacToeAnaly(board8));
	assert(":o" == TicTacToeAnaly(board9));
	assert(":x" == TicTacToeAnaly(board10));
  cout<<"all Tic Tac Toe Asserts Passed."<<endl;   
    
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


//Find out if and who won the game of Tic Tac Toe
//There are eight possible Tic Tac Toe wins and this code checks for all 8
//if none of the 8 wins where found then we know no one won
//O(n * m) time could be done more efficiently but this is very readable
string TicTacToeAnaly(vector< vector<string> > board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ":x" || board[i][j] == ":o"){
                //check for diagonal win from 0,0
                if(i == 0 && j == 0){
                    if(board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2])
                        return board[i][j];
                }
                //from any i == 0 check for straight line win
                if(i == 0){
                    if(board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j])
                        return board[i][j];
                }
                //from any j = 0 check for straight line win
                if(j == 0){
                    if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2])
                        return board[i][j];
                }
                //from 2,0 check for a diagonal win
                if(j == 0 && i == 2){
                    if(board[i][j] == board[i-1][j+1] && board[i][j] == board[i-2][j+2])
                        return board[i][j];
                }
            }
        }
    }
    return "nil";
}

