/*
 * shape.cpp
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "shape.h"

/**
 * @brief shape boundary
 * @details generates string with the values of boundary box witdth and height
 * @return string with boundary
 */
string Shape::bounds(){
	stringstream ss;
	ss << "W: " << boundsWidth_ << "  H: " << boundsHeight_ << "\n";
	return ss.str();
}

/**
 * @brief get boundary width
 * @details get the double containing the width of the shape's boundary box
 * @return double boundary width
 */
double Shape::width(){
	return boundsWidth_;
}

/**
 * @brief get boundary box height
 * @details get the double containing the height of the shape's boundary box
 * @return double boundary height
 */
double Shape::height(){
	return boundsHeight_;
}