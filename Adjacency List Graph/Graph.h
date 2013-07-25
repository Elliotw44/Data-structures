//@file Graph.h
//class for a graph

#include <vector>
#include <list>
#include <map>
#include <iostream>
#include "Edge.h"
using namespace std;
class Graph
{
public:
	int numVert;
	int numEdge;
    //vector that holds a map of all adjacent vertices
	vector<map<int, int> > adjList;

	Graph(int n);

	int getNumVert() const;

	int getNumEdge() const;

	int getWeight(Edge e);

	void add(Edge e);

	void remove(Edge e);
	//Finds the edge connecting verticies v and w
	//returns an iterator to map key w in vector[v]
	map<int, int>::iterator findEdge(int v1, int v2);

	void print();
};