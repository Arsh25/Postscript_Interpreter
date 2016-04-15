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

	int llx = x - (width_ / 2);
	int lly = y - (height_ / 2);

	ss << "newpath\n";
	ss << llx << " " << lly << " moveto\n";
	ss << (llx + width_) << " " << (lly) << " lineto\n";
	ss << (llx + width_) << " " << (lly + height_) << " lineto\n";
	ss << (llx) << " " << (lly + height_) << " lineto\n";
	ss << "closepath\n";
	ss << "stroke\n";

	return ss.str();
}