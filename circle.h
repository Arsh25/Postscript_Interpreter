/*
 * circle.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "shape.h"

class Circle : public Shape
{
public:
	Circle(): Shape(), radius_(0) {};
	Circle(int x, int y, double radius) : Shape(x, y, 2*radius, 2*radius), radius_(radius) {};
	Circle(double radius) : Circle(0,0,radius) {};

	string draw(int x, int y) const;

protected:
	double radius_;

}; //end of class Circle

#endif