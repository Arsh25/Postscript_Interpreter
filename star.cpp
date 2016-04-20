/*
 * star.cpp
 * 4/19/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "star.h"


string Star::draw(int x, int y) const{
	stringstream ss;

	ss << psHeader(x,y);

	double oVertX = getConvexX(0,numOfPoints_,outerRadius_);
	double oVertY = getConvexY(0,numOfPoints_,outerRadius_);
	ss << psMove(oVertX,oVertY);

	double iVertX = getConcaveX(0,numOfPoints_,innerRadius_);
	double iVertY = getConcaveY(0,numOfPoints_,innerRadius_);
	ss << psLine(iVertX,iVertY);

	for(int i = 1; i < numOfPoints_; i++){
		double oVertX = getConvexX(i,numOfPoints_,outerRadius_);
		double oVertY = getConvexY(i,numOfPoints_,outerRadius_);
		ss << psLine(oVertX,oVertY);

		double iVertX = getConcaveX(i,numOfPoints_,innerRadius_);
		double iVertY = getConcaveY(i,numOfPoints_,innerRadius_);
		ss << psLine(iVertX,iVertY);
	}

	ss << psFooter();

	return ss.str();
}