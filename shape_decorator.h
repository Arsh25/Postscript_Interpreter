/*
 * shape_decorator.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SHAPE_DECORATOR_H_INCLUDED
#define SHAPE_DECORATOR_H_INCLUDED

#include <initializer_list>
using std::initializer_list;

#include "shape.h"

class ShapeDecorator
{
public:

	virtual string draw() const;
	virtual string draw(int x,int y) const;

	virtual void print(ostream & os = std::cout) const;
	

protected:
	int x_;
	int y_;

}; //end of class ShapeDecorator

ostream & operator<<(ostream &os, const ShapeDecorator & shape);


#endif