/*
 * scaled.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "scaled.h"

string Scaled::draw() const{
	return draw(shape_->x(),shape_->y());
}

string Scaled::draw(int x, int y) const{

	stringstream ss;
	ss << "gsave\n";
	ss << x << " " << y << " translate\n";
	ss << sx_ << " " << sy_ << " scale\n";
	ss << shape_->draw(0,0);
	ss << "grestore\n";

	return ss.str();
}