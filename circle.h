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

	draw()

protected:
	double radius_;

}; //end of class Circle

#endif