#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include "Graph.h"

Graph* CreateGraph(){
	Vertex V1(1);
	Vertex V2(2);
	Vertex V3(3);
	Vertex V4(4);
	Vertex V5(5);
	Vertex V6(6);
	Vertex V7(7);
	Vertex V8(8);
	Vertex V9(9);
	Vertex V10(10);

	vector<Vertex> V1child{ V3, V6, V7};
	vector<Vertex> V2child{ V1, V10};
	vector<Vertex> V3child{ V8 };
	vector<Vertex> V4child{ V6, V7, V8, V9};
	vector<Vertex> V5child{};
	vector<Vertex> V6child{ V3, V9};
	vector<Vertex> V7child{ V2};
	vector<Vertex> V8child{};
	vector<Vertex> V9child{ V1, V2};
	vector<Vertex> V10child{V4};

	V1.addChildren(V1child);
	V2.addChildren(V2child);
	V3.addChildren(V3child);
	V4.addChildren(V4child);
	V5.addChildren(V5child);
	V6.addChildren(V6child);
	V7.addChildren(V7child);
	V8.addChildren(V8child);
	V9.addChildren(V9child);
	V10.addChildren(V10child);

	vector<Vertex> vertices{V1, V2, V3, V4, V5, V6, V7, V8, V9, V10};
	Graph* g1 = new Graph(vertices);
	return g1;
};

using namespace std;
int main(){
	Graph* gPtr = CreateGraph();

	return 0;
}
