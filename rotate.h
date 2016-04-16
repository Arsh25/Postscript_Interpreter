/*
 * rotate.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef ROTATE_H_INCLUDED
#define ROTATE_H_INCLUDED

#include "shape.h"

class Rotated: public Shape 
{
public:
	Rotated() : Shape() {};
	Rotated(Shape * shape, int angle): Shape(), shape_(shape), angle_(angle) {};

	string draw() const;
	string draw(int x, int y) const;

private:
	Shape * shape_;
	int angle_;

};

#endif