/*
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

//used by ShapeDecorator class
#include <initializer_list>
using std::initializer_list;

class Shape
{
public:
	//moved Shape constructor declarations to shape.cpp 
	//because derived classes couldn't find them otherwise
	Shape();
	Shape(int x, int y);
	Shape(pair<int,int> center);

	virtual void draw() = 0;

protected:
	//x,y coordinates tracking center of shape
	pair<int,int> center_;

	//x,y coordinates tracking corners of bounds
	pair<int,int> topL_;
	pair<int,int> botL_;
	pair<int,int> topR_;
	pair<int,int> botR_;

}; //end of class Shape

#endif