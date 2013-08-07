  /**
* String to Long
*
* @author Elliot weil
* @file StringtoLong.cpp
*/
#include <iostream>
#include <assert.h> 
using namespace std;

long StringToLong(string s);

int main()
{
	//normal case
    string test = "39156742790";
    //letters inbetween
    string test1 = "93814asd34";
    //letters before, inbetween, and after
    string test2 = "dklj;fjl:5300sdfsfrsa1208wqegdseqwqe6sad";
    //normal negative case
    string test3 = "-23424562";
    //testing to make sure the bool first gets set properly
    string test4 ="3-243234234";
    //testing negative with letters before, inbetween, and after
    string test5 ="-asdsadsadsa342asdasd43asdsad344sadsalkjl)(*";
    //testing negative symbol midway in the string but before any number
    string test6 ="asdlkjesl;dj;sk;ldjelalj-7834-asdsf32wqwe--324-ewqeq";
    //test overload prevention
    string test7 = "12345678901234567890213456785432456786543";
	//testing overload prevention for negative numbers
	string test8 = "-12345678901234567890123";
	//testing for floats
	string test9 = "21343.324";
    long itest = StringToLong(test);
    long itest1 = StringToLong(test1);
    long itest2 = StringToLong(test2);
    long itest3 = StringToLong(test3);
    long itest4 = StringToLong(test4);
    long itest5 = StringToLong(test5);
    long itest6 = StringToLong(test6);
    long itest7 = StringToLong(test7);
	long itest8 = StringToLong(test8);
	long itest9 = StringToLong(test9);
	assert(itest == 39156742790);
	assert(itest1 == 9381434);
	assert(itest2 == 530012086);
	assert(itest3 == -23424562);
	assert(itest4 == 3243234234);
	assert(itest5 == -34243344);
	assert(itest6 == -783432324);
	assert(itest7 == 1234567890123456789);
	assert(itest8 == -1234567890123456789);
	assert(itest9 == 21343324);
	cout<<"All asserts passed!!!! :)"<<endl;

}

long StringToLong(string s)
{
	//bool for checking if you have found the first number in the string
	bool first = false;
	//bool that gets set if the long is negative
	bool negative = false;
	//check if string is too long for long
	bool overloaded = false;
    int i = 0;
    long numlong = 0;
    int digitcount = 0;
    //while condition is till end of string in this case checking for null terminating symbol. could also use the size of the string
    while (s[i] != '\0') {
        // checks if the ascii value of the character is between 48 and 57 which are the ascii values of 0 through 9
        if ((int)s[i] < 58 && (int)s[i] > 47) {
            //if the characters is then append the digit on to the long;
        	if(digitcount <= 18){
        		numlong = ((numlong * 10) + ((long)s[i] - 48));
        		first = true;
        		digitcount++;
        	}
        	//If number is too large
        	else if(digitcount > 18){
				overloaded = true;
        		break;
        	}
        }
        else if( (first == false && (int)s[i] == 45 )){
        	negative = true;
        }
        //move forward in the string
        i++;
    }
    //if the number is negative return the negative value
    if (negative == true){
    	return numlong * -1;
    }
    //else return the positive
    else{
     return numlong;
    }
}
