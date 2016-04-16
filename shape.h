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
#include <iostream>
using std::ostream;

#include "utils.h"

class Shape
{
public:

	Shape(): x_(0), y_(0), boundsWidth_(0), boundsHeight_(0) {};
	Shape(int x, int y, double width, double height): x_(x), y_(y), boundsWidth_(width), boundsHeight_(height) {};
	Shape(double width,double height) : Shape(0,0,width,height) {};

	virtual ~Shape() {};
	Shape (const Shape & other){};

	virtual string draw() const;
	virtual string draw(int x,int y) const;
	virtual void place(int x, int y);
	string bounds();
	double width();
	double height();
	int x();
	void x(int x);
	int y();
	void y(int y);

protected:
	/**
	 * x coordinate of shape position
	 */
	int x_;

	/**
	 * y coordinate of shape position
	 */
	int y_;

	/**
	 * width of boundary box
	 */
	double boundsWidth_;	

	/**
	 * height of boundary box
	 */
	double boundsHeight_;

	

	


}; //end of class Shape


ostream & operator<<(ostream &os, const Shape & shape);

#endif