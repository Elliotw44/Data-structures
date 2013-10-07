  /**
*Zillow Coding Questions
* @author Elliot weil
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;

void FourColoredBallsGame(string guess, string answer);

void LongestSum(vector<int> theArray);
int main()
{
	//4 location score
	FourColoredBallsGame("RGRY", "RGRY");
	//zero scores
	FourColoredBallsGame("RGGR", "YBYB");
	//4 color score
	FourColoredBallsGame("BYRG", "GRBY");
	//2 color and 2 location
	FourColoredBallsGame("BGRY", "YGRB");
	int testArr[] = {5,10,-8,-8,4,11};
	vector<int> testV (testArr, testArr + sizeof(testArr) / sizeof(int));
	LongestSum(testV);
}
//Longest continuous sum code. Basically I go through the Array(vector) keeping track of my max sum and it length, and ending index. 
//Then after going through the whole array I go back and print out the longest continuous sum using the index and length.
//Used vectors for the .size mehtod
//Big O(N) time complexity because we go through only one pass of theArray at a given time.
void LongestSum(vector<int> theArray){
  int max = 0;
  int maxLen = 0;
  int maxInd = 0;
  int len = 0;
  int sum = 0;
  for(int i = 0; i < theArray.size(); i++){
     sum += theArray[i];
	 len++;
	 //the sum is less then zero and it is better to restart the sum and length because 0 is a greater number.
	 if(sum < 0){
		sum = 0;
		len = 0;
	}
	 //new max so set the variables
	if(sum > max){
		max = sum;
		maxLen = len;
		maxInd = i;
		}
  }
  cout<<"The Longest continuous sum is: ";
  for(int i = (maxInd-(maxLen-1)); i <= maxInd; i++)
  	cout<<theArray[i]<< ", ";
 cout<< " with a value of: " <<max<<endl;
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
