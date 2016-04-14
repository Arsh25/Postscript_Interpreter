/*
 * polygon.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "polygon.h"

string Polygon::draw(int x,int y){
	return "";
}

string Triangle::draw(int x,int y){
	return "";
}

string Square::draw(int x,int y){
	stringstream ss;

	int llx = x - (sideLength_ / 2);
	int lly = y - (sideLength_ / 2);

	ss << "newpath\n";
	ss << llx << " " << lly << " moveto\n";
	ss << (llx + sideLength_) << " " << (lly) << " lineto\n";
	ss << (llx + sideLength_) << " " << (lly + sideLength_) << " lineto\n";
	ss << (llx) << " " << (lly + sideLength_) << " lineto\n";
	ss << "closepath\n";
	ss << "stroke\n";

	return ss.str();
}

