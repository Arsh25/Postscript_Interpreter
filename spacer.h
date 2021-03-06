/*
 * spacer.h
 * 4/4/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SPACER_H_INCLUDED
#define SPACER_H_INCLUDED

#include "rectangle.h"

class Spacer : public Rectangle
{
public:
	Spacer(): Rectangle() {};
	Spacer(int x, int y, double w, double h): Rectangle(x,y,w,h) {};
	Spacer(double w, double h) : Rectangle(0,0,w,h) {};

	string draw() const;
	string draw(int x, int y) const;

}; //end of class Spacer



#endif