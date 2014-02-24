#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

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


  return 0;
}

