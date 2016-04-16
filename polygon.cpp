/*
 * polygon.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "polygon.h"


/**
 * @brief generates ps code for drawing a polygon
 * @details returns a string containing the ps code for drawing any equilateral polygon
 * 
 * @param x x position of center
 * @param y y position of center
 * 
 * @return string containing ps code
 */
string Polygon::draw(int x,int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << "newpath\n";
	ss << x << " " << y << " translate\n";

	pair<double,double> vertex = getPoint(0,numOfSides_,sideLength_);
	ss << vertex.first << " " << vertex.second << " moveto\n";

	for(int i = 1; i < numOfSides_; i++){
		vertex = getPoint(i,numOfSides_,sideLength_);
		ss << vertex.first << " " << vertex.second << " lineto\n";
	}

	ss << "closepath\n";
	ss << "stroke\n";
	ss << "grestore\n";

	return ss.str();
}

int Polygon::numOfSides(){
	return numOfSides_;
}
void Polygon::numOfSides(int n){
	numOfSides_ = n;
}
double Polygon::sideLength(){
	return sideLength_;
}
void Polygon::sideLength(double l){
	sideLength_ = l;
}
double Polygon::radius(){
	return radius_;
}
