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
	Circle(double radius) : Shape(), radius_(radius) {};
	Circle(int x, int y, double radius) : Shape(x,y), radius_(radius) {};
	Circle(pair<int,int> center, double radius) : Shape(center), radius_(radius) {};

protected:
	double radius_;

}; //end of class Circle

#endif