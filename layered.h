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

#include "shape.h"

class Layered : public Shape
{
public:
	Layered() : Shape() {};
	Layered(int x, int y, initializer_list<Shape*> shapes) : Shape(x,y), shapes_(shapes) {};
	Layered(initializer_list<Shape*> shapes) : Layered(0,0,shapes) {};

	string draw(int x, int y) const;

protected:
	initializer_list<Shape*> shapes_;
};


class Horizontal: public Layered
{
public:
	Horizontal() : Layered() {};
	Horizontal(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes) {};
	Horizontal(initializer_list<Shape*> shapes) : Horizontal(0,0,shapes) {};

	string draw(int x, int y) const;

private:

};

class Vertical : public Layered
{
public:
	Vertical() : Layered() {};
	Vertical(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes) {};
	Vertical(initializer_list<Shape*> shapes) : Vertical(0,0,shapes) {};

	string draw(int x, int y) const;

private:

};



#endif