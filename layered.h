/*
 * layered.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef LAYERED_H_INCLUDED
#define LAYERED_H_INCLUDED

#include <initializer_list>
using std::initializer_list;

#include "shape_decorator.h"

class Layered : public ShapeDecorator
{
public:
	Layered() : ShapeDecorator() {};
	Layered(int x, int y, initializer_list<Shape*> shapes) : ShapeDecorator(x,y), shapes_(shapes) {};
	Layered(initializer_list<Shape*> shapes) : Layered(0,0,shapes) {};

protected:
	initializer_list<Shape*> shapes_;
};


class Horizontal: public Layered
{
public:
	Horizontal() : Layered() {};
	Horizontal(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes) {};
	Horizontal(initializer_list<Shape*> shapes) : Horizontal(0,0,shapes) {};

private:

};

class Vertical : public Layered
{
public:
	Vertical() : Layered() {};
	Vertical(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes) {};
	Vertical(initializer_list<Shape*> shapes) : Vertical(0,0,shapes) {};

private:

};



#endif