/**
 * shape.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <utility>
using std::pair;


class Shape
{
public:
	//moved Shape constructor declarations to shape.cpp 
	//because derived classes couldn't find them otherwise
	Shape();
	Shape(int x, int y);
	Shape(pair<int,int> center);

	virtual ~Shape(){};
	Shape (const Shape & other){};

	virtual void draw() = 0;


protected:
	/**
	 * Point at center of bounds
	 */
	pair<int,int> center_;

	/**
	 * Point at top left corner of bounds
	 */
	pair<int,int> topL_;

	/**
	 * Point at bottom left corner of bounds
	 */
	pair<int,int> botL_;

	/**
	 * Point at top right corner of bounds
	 */
	pair<int,int> topR_;

	/**
	 * Point at bottom right corner of bounds
	 */
	pair<int,int> botR_;


}; //end of class Shape

#endif