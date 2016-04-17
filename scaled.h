/*
 * scaled.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SCALED_H_INCLUDED
#define SCALED_H_INCLUDED

#include "shape.h"

class Scaled : public Shape
{
public:
	Scaled() : Shape() {};
	Scaled(Shape* shape, double sx, double sy) 
		: Shape(0,0,shape->width()*sx,shape->height()*sy), 
			shape_(shape), 
			sx_(sx), 
			sy_(sy) 
			{};

	string draw() const;
	string draw(int x, int y) const;

private:
	Shape * shape_;
	double sx_;
	double sy_;

};



#endif