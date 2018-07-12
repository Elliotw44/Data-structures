// some shit
#pragma once
#include <vector>
#include "Vertex.h"
using namespace std;
class Graph
{
public:
	Graph()
	:m_vertices(vector<Vertex>())
	{}

	Graph(vector<Vertex> input)
	:m_vertices(input)
	{}

	void addVertex(Vertex V)
	{
		m_vertices.push_back(V);
	}

	int NumberOfVertices() const
	{
		return m_vertices.size();
	}

	vector<Vertex> getVertices()
	{
		return m_vertices;
	}

private:
	vector<Vertex> m_vertices;
};
