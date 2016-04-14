/*
 * utils.cpp
 * 4/4/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "utils.h"

/**
 * @brief generates ps code for drawing a line
 * @details returns a string containing the ps code for drawing a line, in the form 'x0 y0 move x1 y1 rlineto'
 * 
 * @param x0 Point 1 x value
 * @param y0 Point 1 y value
 * @param x1 Point 2 x value
 * @param y1 Point 2 y value
 * @return string with ps code
 */
string psLine(int x0, int y0, int x1, int y1){
	return stringify(x0) + " " + stringify(y0) + " moveto " + stringify(x1) + " " + stringify(y1) + " lineto";
}

/**
 * @brief generates ps code for drawing an arc
 * @details returns a string containing the ps code for drawing an arc, in the form 'x y r angle1 angle2 arc'
 * 
 * @param x c position of the center
 * @param y y position of the center
 * @param r radius of the arc
 * @param startAngle start angle for the arc, from 0 to 360 degrees
 * @param endAngle end angle for the arc, from 0 to 360 degrees
 * @return string containing ps code
 */
string psArc(int x, int y, double r, int startAngle, int endAngle){
	return stringify(x) + " " + stringify(y) + " " + stringify(r) + " " + stringify(startAngle) + " " + stringify(endAngle) + " arc";
}

/**
 * @brief calculates a point
 * @details calculates the position of the nth vertice of a polygon
 * 
 * @param k vetrice number, 0 through n-1
 * @param n number of sides
 * @param l side length
 * 
 * @return the location of the vertice
 */
pair<double,double> getPoint(int k, int n, double l){
	double x = (l/2)*( sin( (2*k+1)*PI/n ) / sin(PI/n) );
	double y = (-l/2)*( cos( (2*k+1)*PI/n ) / sin(PI/n) );
	return pair<double,double>(x,y);
}

/**
 * @brief cacluate width of polygon
 * @details calculate the width of any equlateral polygon
 * 
 * @param n number of sides
 * @param l length of sides
 * 
 * @return width of polygon
 */
double getWidth(int n, double l){
	return n%2 ? (l*(sin(PI*(n-1)))/sin(PI/n)) : ( n%4 ? (l / sin(PI/2)) : (l*cos(PI/n)/sin(PI/n)) );
}

/**
 * @brief cacluate height of polygon
 * @details calculate the height of any equlateral polygon
 * 
 * @param n number of sides
 * @param l length of sides
 * 
 * @return height of polygon
 */
double getHeight(int n, double l){
	return n%2 ? (l * (1+cos(PI/n)) / (2*sin(PI/n))) : (l * (cos(PI/n)) / (sin(PI/n)));
}

