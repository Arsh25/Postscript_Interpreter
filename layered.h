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
	Layered(int x, int y, initializer_list<Shape*> shapes) : shapes_(shapes) {};

protected:
	initializer_list<Shape*> shapes_;
};


class Horizontal: public Layered
{
public:


private:
	

};

class Vertical : public Layered
{
public:


private:


};



#endif