/*
 * shape.cpp
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "shape.h"

/**
 * @brief generate ps code for shape
 * @details generate ps code for drawing shape at default location
 * @return string containing ps code for drawing shape at default location
 */
string Shape::draw() const{
	return draw(x_,y_);
}

/**
 * @brief generate ps code for shape
 * @details generate ps code for drawing shape at specified coordinates
 * 
 * @param x x position for center of shape's desired location
 * @param y y position for center of shape's desired location
 * 
 * @return string containing ps code for drawing shape at specified location
 */	
string Shape::draw(int x,int y) const{
	return "";
}

/**
 * @brief change shape position
 * @details change shape position to passed coordinates
 * 
 * @param x x coordinate of new position
 * @param y y coordinate of new position
 */
void Shape::place(int x, int y){
	x_ = x;
	y_ = y;
}

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

int Shape::x(){
	return x_;
}
int Shape::y(){
	return y_;
}

void Shape::print(ostream & os) const{
	os << this->draw();
}

ostream & operator<<(ostream &os, const Shape & shape){
	shape.print(os);
	return os;
}