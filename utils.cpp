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
	return to_string(x0) + " " + to_string(y0) + " moveto " + to_string(x1) + " " + to_string(y1) + " lineto";
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
	return to_string(x) + " " + to_string(y) + " " + to_string(r) + " " + to_string(startAngle) + " " + to_string(endAngle) + " arc";
}

/**
 * @brief calculate x
 * @details calculate the x coordinate of a given vertex of an equilateral polygon
 * 
 * @param k vertex number
 * @param n number of sides
 * @param l length of sides
 * @return double, x coordinate of vertex
 */
double calcX(int k, int n, double l){
	return (l/2)*( sin( (2*k+1)*M_PI/n ) / sin(M_PI/n) );
}

/**
 * @brief calculate y
 * @details calcualte the y coordinate of a given vertex of an equilateral polygon
 * 
 * @param k vertex number
 * @param n number of sides
 * @param l length of sides
 * @return double, y coordinate of vertex
 */
double calcY(int k, int n, double l){
	return (-l/2)*( cos( (2*k+1)*M_PI/n ) / sin(M_PI/n) );
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
	if(n%2 == 0){
		if(n%4 == 0){
			return (l*cos(M_PI/n)/sin(M_PI/n));
		} else {
			return (l / sin(M_PI/n));
		}
	} else {
		return ( l * ( sin( M_PI * (n-1) / (2*n) ) ) / sin(M_PI/n) );
	}
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
	if(n%2 == 0){
		return (l * (cos(M_PI/n)) / (sin(M_PI/n)));
	} else {
		return (l * (1+cos(M_PI/n)) / (2*sin(M_PI/n)));
	}
}

/**
 * @brief calculate radius
 * @details calculate radius of an equlateral polygon
 * 
 * @param n number of sides
 * @param l length of sides
 * 
 * @return double, radius
 */
double getRadius(int n, double l){
	return l/(2*sin(M_PI/n));
}
