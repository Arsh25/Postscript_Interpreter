/*
 * circle.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "circle.h"

string Circle::draw(int x, int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << "newpath\n";
	ss << x << " " << y << " translate\n";

	ss << psArc(0,0,radius_,0,360) << "\n";

	ss << "closepath\n";
	ss << "stroke\n";
	ss << "grestore\n";

	return ss.str();
}