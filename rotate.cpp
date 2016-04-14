/*
 * rotate.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

 #include "rotate.h"

string Rotated::draw(int x, int y){
	stringstream ss;
	ss << "gsave\n";
	ss << x << " " << y << " translate\n";
	ss << angle_ << " rotate\n";
	ss << shape_->draw(0,0);
	ss << "grestore\n";

	return ss.str();
}