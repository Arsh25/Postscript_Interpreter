/*
 * layered.cpp
 * 4/15/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "layered.h"

string Layered::draw(int x, int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << x << " " << y << " translate\n";

	for(auto shape: shapes_){
		ss << shape->draw(0,0) << "\n";
	}

	ss << "grestore\n"; 
	return ss.str();
}

string Horizontal::draw(int x, int y) const{
	stringstream ss;


	return ss.str();
}

string Vertical::draw(int x, int y) const{
	stringstream ss;


	return ss.str();
}