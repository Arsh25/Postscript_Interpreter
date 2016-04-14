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

/**
 * @brief generates ps code for drawing a circle
 * @details returns a string containing the ps code for drawing a triangle
 * 
 * @param x x position of center
 * @param y y position of center
 * 
 * @return string containing ps code
 */
string Triangle::draw(int x,int y){
	stringstream ss;

	int llx = x - (sideLength_ / 2);
	int lly = y - (sideLength_ / 2);

	ss << "newpath\n";
	ss << llx << " " << lly << " moveto\n";
	ss << (llx + sideLength_) << " " << (lly) << " lineto\n";
	ss << x << " " << (y+(sideLength_/2)) << " lineto\n";
	ss << "closepath\n";
	ss << "stroke\n";

	return ss.str();
}

/**
 * @brief generates ps code for drawing circle
 * @details returns a string containing the ps code for drawing a square
 * 
 * @param x x position of center
 * @param y y position of center
 * 
 * @return string containing ps code
 */
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

