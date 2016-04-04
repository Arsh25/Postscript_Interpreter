/*
 * polygon.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "shape.h"

class Polygon: public Shape
{
public:
	Polygon() : Shape(), sides_(0), length_(0) {};
	Polygon(int sides, double length) : Shape(), sides_(sides), length_(length) {};
	Polygon(int x, int y, int sides, double length) : Shape(x,y), sides_(sides), length_(length) {};
	Polygon(pair<int,int> center, int sides, double length) : Shape(center), sides_(sides), length_(length) {};

private:
	int sides_;
	double length_;

}; //end of class Polygon

#endif