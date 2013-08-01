/*
 * Vertex.h
 *
 *  Created on: Jul 30, 2013
 *      Author: eweil
 */

#ifndef VERTEX_H_
#define VERTEX_H_
class Vertex
{
public:
	int dist;
	string value;
	Vertex* prev;
	//Constructor
	Vertex(int d){
		dist = d;
		prev = 0; //set to NULL;
		value = "";
	}
};



#endif /* VERTEX_H_ */
