/*
 * utils.h
 * 4/4/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
using std::string;

#include <sstream>
using std::stringstream;


/**
 * @brief turns a variable into a string
 * @details uses stringstream with an insertion operator to convert the variable to a string
 * 
 * @param var value by reference
 * @return string version of variable
 */
template<typename T>
string stringify(const T& var){
	stringstream ss;
	ss << var;
	return ss.str();
};

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
	return "newpath " + stringify(x0) + " " + stringify(y0) + " moveto " + stringify(x1) + " " + stringify(y1) + " lineto";
};

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
string psArc(int x, int y, int r, int startAngle, int endAngle){
	return stringify(x) + " " + stringify(y) + " " + stringify(r) + " " + stringify(startAngle) + " " + stringify(endAngle) + " arc";
}


#endif