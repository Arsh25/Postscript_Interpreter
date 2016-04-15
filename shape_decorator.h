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
	ShapeDecorator(): x_(0), y_(0) {};
	ShapeDecorator(int x, int y): x_(x), y_(y) {};

	virtual string draw() const;
	virtual string draw(int x,int y) const;

	virtual void print(ostream & os = std::cout) const;
	

protected:
	int x_;
	int y_;

}; //end of class ShapeDecorator

ostream & operator<<(ostream &os, const ShapeDecorator & shape);


#endif