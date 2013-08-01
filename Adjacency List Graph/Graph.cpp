
#include "Graph.h"
#include <queue>

Graph::Graph(int n){
	map<int, int> element;
	Vertex V(std::numeric_limits<int>::max());
	adjList.assign(n, element);
	vInfo.assign(n, v);
	numVert = n;
	numEdge = 0;
}

bool Graph::dfsFind(string value){

}

int Graph::getNumVert() const {
	return numVert;
}

int Graph::getNumEdge() const {
	return numEdge;
}

int Graph::getWeight(Edge e) {
	return e.weight;
}

void Graph::add(Edge e) {
	int v1 = e.v1;
	int v2 = e.v2;
	int weight = e.weight;
	//add the first vertix the edge connects to intto the adjList
	adjList[v2].insert(make_pair(v1, weight));
	//add the second vertix the edge connects to into the adjList
	adjList[v1].insert(make_pair(v2, weight));
	numEdge++;
}

void Graph::remove(Edge e) {
	int v1 = e.v1;
	int v2 = e.v2;
	int weight = e.weight;
	adjList[e.v1].erase(v2);
	adjList[e.v2].erase(v1);
	numEdge--;
}

map< int, int>::iterator Graph::findEdge(int v1, int v2){
	map<int, int> myMap = adjList[v1];
	map<int, int>::iterator it = myMap.find(v2);
	return it;
}

void Graph::print() {
	for (int i = 0; i < numVert; i++){
		map<int, int> VertMap = adjList[i];
        cout<<"Vertex "<< i << " has these edges: ";
		for(map<int, int>::iterator it  = VertMap.begin(); it != VertMap.end(); it++)
			cout<< "Edge connecting vertex " << i << " to vertex " << it->first << " with weight " << it->second <<endl;
		cout << endl << endl << endl;
	}
/*
void BST::printTreeBfs(Node* root){
	int curLevel = 1;
	int nextLevel = 0;
	bool lastLeft = true;
	bool lastRight = true;
	queue<Node> que;
	q.push(root);
	while(!que.empty()){
		Node* tmp=	que.front();
		que.pop();
		cout<< tmp->item << " ";
		curLevel --;
		if(tmp->left != 0){
			nextLevel += 1;
		}
		if (tmp->right != 0){
			nextLevel += 1;
		}
		if(curLevel == 0){
			cout << endl;
			curLevel = nextLevel;
			nextLevel = 0;
		}
   }
  }*/

}

