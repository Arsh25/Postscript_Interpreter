/*
 * star.h
 * 4/19/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef STAR_H
#define STAR_H

#include "shape.h"

class Star : public Shape
{
public:
	Star(): Shape(), outerRadius_(0), innerRadius_(0) {};
	Star(int x, int y, int n, double oRadius, double iRadius) : Shape(x, y, 2*oRadius, 2*oRadius), numOfPoints_(n), outerRadius_(oRadius), innerRadius_(iRadius) {};
	Star(int n, double oRadius, double iRadius) : Star(0,0,n,oRadius,iRadius) {};

	string draw(int x, int y) const;

	double outerRadius();
	double innerRadius();

private:
	double numOfPoints_;
	double outerRadius_;
	double innerRadius_;
};


#endif // STAR_H
