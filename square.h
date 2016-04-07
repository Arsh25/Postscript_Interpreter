/*
 * square.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "rectangle.h"

class Square: public Polygon
{
public:
	Square(): Polygon() {};
	Square(double side): Polygon(4,side) {};
	Square(int x, int y, double side): Polygon(x,y,4,side) {};
	Square(pair<int,int> center, double side): Polygon(center,4,side) {};

private:


};


#endif