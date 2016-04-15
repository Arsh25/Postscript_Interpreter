/*
 * scaled.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "scaled.h"

string Scaled::draw(int x, int y) const{

	stringstream ss;
	ss << "gsave\n";
	ss << sx_ << " " << sy_ << " scale\n";
	ss << shape_->draw(x,y);
	ss << "grestore\n";

	return ss.str();
}