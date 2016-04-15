/*
 * scaled.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SCALED_H_INCLUDED
#define SCALED_H_INCLUDED

#include "shape_decorator.h"

class Scaled : public ShapeDecorator
{
public:
	Scaled() {};
	Scaled(Shape* shape, double sx, double sy): shape_(shape), sx_(sx), sy_(sy) {}

	string draw(int x, int y) const;

private:
	Shape * shape_;
	double sx_;
	double sy_;

};



#endif