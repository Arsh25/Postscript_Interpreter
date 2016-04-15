/*
 * rotate.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef ROTATE_H_INCLUDED
#define ROTATE_H_INCLUDED

#include "shape_decorator.h"

class Rotated: public ShapeDecorator 
{
public:
	Rotated(Shape * shape, int angle):shape_(shape), angle_(angle) {}

	string draw(int x, int y) const;

private:
	Shape * shape_;
	int angle_;

};

#endif