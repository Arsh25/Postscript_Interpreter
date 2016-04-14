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
#include <string>
using std::string;

#include "utils.h"

class Shape
{
public:
	//moved Shape constructor declarations to shape.cpp 
	//because derived classes couldn't find them otherwise
	Shape();

	virtual ~Shape(){};
	Shape (const Shape & other){};

	virtual string draw(int,int) = 0;


protected:

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