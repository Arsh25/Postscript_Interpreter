/*
 * rectangle.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

 #include "rectangle.h"

string Rectangle::draw(int x, int y) const
{
	stringstream ss;

	ss << psHeader(x,y);

	ss << psMove(width_/2,height_/2);
	ss << psLine(-width_/2,height_/2);
	ss << psLine(-width_/2,-height_/2);
	ss << psLine(width_/2,-height_/2);

	ss << psFooter();

	return ss.str();
}