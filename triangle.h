/*
 * triangle.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "polygon.h"

class Triangle : public Polygon
{
public:
	Triangle() : Polygon() {};
	Triangle(double side) : Polygon(3,side) {};

private:

};

#endif