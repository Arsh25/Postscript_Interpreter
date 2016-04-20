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
	Rotated(Shape * shape, int angle);

	string draw() const;
	string draw(int x, int y) const;

private:
	/**
	 * pointer to Shape object
	 */
	Shape * shape_;
	/**
	 * angle of rotation
	 */
	int angle_;

};

#endif