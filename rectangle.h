/*
 * rectangle.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "shape.h"

#include <sstream>
using std::stringstream;

class Rectangle: public Shape
{
public:
	Rectangle(): Shape(), width_(0), height_(0) {};
	Rectangle(int x, int y, double w, double h): Shape(x,y,w,h), width_(w), height_(h) {};
	Rectangle(double w, double h) : Rectangle(0,0,w,h) {};

	string draw() const;
	string draw(int x, int y) const;

protected:
	/**
	 * width of rectangle
	 */
	double width_;
	/**
	 * height of rectangle
	 */
	double height_;

}; //end of class Rectangle

#endif