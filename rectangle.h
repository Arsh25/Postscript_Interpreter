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

	string draw(int x, int y) const;

protected:
	double width_;
	double height_;

}; //end of class Rectangle

#endif