#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include "conio.h"
#include "Graph.h"

using namespace std;
int main(){
	/*vector<int> myvec;
	cout<< myvec.size() <<endl;
	for(int i = 0; i < 10; i++){
		myvec.push_back(i);
	}
	cout<< myvec.size() <<endl;
	for(vector<int>::iterator it = myvec.begin(); it != myvec.end(); it++){
		cout << *it << endl;
	}*/
	Graph Elz(5);
	cout<< Elz.getNumVert() <<endl;
	Edge e1(0,1,5);
	Edge e2(1,3,3);
	Edge e3(3,2,1);
	Edge e4(2,0,6);
	Edge e5(3,4,4);
	cout<<e5.v1<< " " << e5.v2 << " " << e5.weight <<endl;
	Elz.add(e1);
	Elz.add(e2);
	Elz.add(e3);
	Elz.add(e4);
	Elz.add(e5);
	Elz.print();
	
	_getch();
	return 0;
}