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
 * @details returns a string containing the ps code for drawing a line, in the form "x y lineto\n"
 * 
 * @param x x coordinate of endpoint
 * @param y y coordinate of endpoint
 * @return string with ps code
 */
string psLine(int x, int y){
	return to_string(x) + " " + to_string(y) + " lineto\n";
}

/**
 * @brief generates ps code for moving the cursor
 * @details returns a string containing the ps code for moving the ps cursor, in the form "x y moveto\n"
 * 
 * @param x x coordinate of target point
 * @param y y coordinate of target point
 * 
 * @return string with ps code
 */
string psMove(int x, int y){
	return to_string(x) + " " + to_string(y) + " moveto\n";
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
	return to_string(x) + " " + to_string(y) + " " + to_string(r) + " " + to_string(startAngle) + " " + to_string(endAngle) + " arc\n";
}

string psHeader(int x, int y){
	return "gsave\nnewpath\n" + to_string(x) + " " + to_string(y) + " translate\n";
}

string psFooter(){
	return "closepath\nstroke\ngrestore\n";
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

/**
 * @brief get x
 * @details calculate x coordinate of a convex vertex of a star
 * 
 * @param k vertex number, 0 - (n-1)
 * @param n number of verticies
 * @param r radius out outer circle
 * @return double, x coordinate
 */
double getConvexX(int k, int n, double r){
	return r * cos(2 * M_PI * k / n);
}

/**
 * @brief get y
 * @details calculate y coordinate of a convex vertex of a star
 * 
 * @param k vertex number, 0 - (n-1)
 * @param n number of verticies
 * @param r radius out outer circle
 * @return double, y coordinate
 */
double getConvexY(int k, int n, double r){
	return r * sin(2 * M_PI * k / n);
}

/**
 * @brief get x
 * @details calculate x coordinate of a concave vertex of a star
 * 
 * @param k vertex number, 0 - (n-1)
 * @param n number of verticies
 * @param r radius of inner circle
 * @return double, x coordinate
 */
double getConcaveX(int k, int n, double r){
	return r * cos( (2 * M_PI * k + M_PI) / n);
}

/**
 * @brief get y
 * @details calculate y coordinate of a concave vertex of a star
 * 
 * @param k vertex number, 0 - (n-1)
 * @param n number of verticies
 * @param r radius of inner circle
 * @return double, y coordinate
 */
double getConcaveY(int k, int n, double r){
	return r * sin( (2 * M_PI * k + M_PI) / n);
}
