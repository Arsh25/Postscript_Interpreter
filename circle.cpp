/*
 * circle.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "circle.h"

double Circle::radius(){
	return radius_;
}

string Circle::draw(int x, int y) const{
	stringstream ss;

	ss << psHeader(x,y);

	ss << psArc(0,0,radius_,0,360);

	ss << psFooter();

	return ss.str();
}