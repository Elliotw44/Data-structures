//@file Edge.h
//An edge class for a graph implmentation

class Edge
{
public:
	int v1, v2, weight;
	//contructor
	Edge(int firstVertex, int secondVertex, int edgeWeight){
		v1 = firstVertex;
		v2 = secondVertex;
		weight = edgeWeight;
	}
};
