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
string stringify(T& var){
	stringstream ss;
	ss << var;
	return ss.str();
};

/**
 * @brief returns string containing postsript code for a line
 * @details generates string containing postscript code for drawing a line between two points
 * 
 * @param x0 Point 1 x value
 * @param y0 Point 1 y value
 * @param x1 Point 2 x value
 * @param y1 Point 2 y value
 * @return string with ps code
 */
string line(int x0, int y0, int x1, int y1){
	return stringify(x0) + " " + stringify(y0) + " move " + stringify(x1) + " " + stringify(y1) + " rlineto";
};


#endif