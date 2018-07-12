/*
 * Vertex.h
 *
 *  Created on: Jul 30, 2013
 *      Author: eweil
 */

#pragma once
#include <vector>

class Vertex
{
public:
	//Constructor
	Vertex()
	:m_value(0)
	,m_childList(vector<Vertex>())
	{}
	Vertex(int value)
	:m_value(value)
	{}
	Vertex(int value, vector<Vertex> children)
	:m_value(value)
	,m_childList(children)
	{}
	
	int getValue() const
	{ return m_value; }

	vector<Vertex> getChildren() const
	{ return m_childList; }

	void addChild(Vertex V)
	{
		m_childList.push_back(V);
	}

	void addChildren(vector<Vertex> input)
	{
		m_childList.insert(m_childList.end(), input.cbegin(), input.cend());
	}

private:
int m_value;
vector<Vertex> m_childList; 
};
