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
	Polygon() : Shape(), numOfSides_(0), sideLength_(0) {};
	Polygon(int sides, double length) : Shape(), numOfSides_(sides), sideLength_(length) {};
	Polygon(int x, int y, int sides, double length) : Shape(x,y), numOfSides_(sides), sideLength_(length) {};
	Polygon(pair<int,int> center, int sides, double length) : Shape(center), numOfSides_(sides), sideLength_(length) {};

private:
	int numOfSides_;
	double sideLength_;

}; //end of class Polygon

#endif