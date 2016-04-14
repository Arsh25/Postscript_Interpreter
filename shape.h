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
#include <sstream>
using std::stringstream;
#include <cmath>

#include "utils.h"

class Shape
{
public:

	Shape() {};

	virtual ~Shape() {};
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