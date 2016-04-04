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

class Square: public Rectangle
{
public:
	Square(): Rectangle() {};
	Square(double side): Rectangle(side,side) {};
	Square(int x, int y, double side): Rectangle(x,y,side,side) {};
	Square(pair<int,int> center, double side): Rectangle(center,side,side) {};

private:

};


#endif