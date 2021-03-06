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

/**
 * @brief get x
 * @details gets x value of center of shape
 * @return returns x
 */
int Shape::x(){
	return x_;
}

/**
 * @brief set x
 * @details sets x value of center of shape
 * 
 * @param x new x value
 */
void Shape::x(int x){
	x_ = x;
}

/**
 * @brief get y
 * @details gets y value of center of shape
 * @return returns y
 */
int Shape::y(){
	return y_;
}

/**
 * @brief sets y
 * @details sets y value of center of shape
 * 
 * @param y new y value
 */
void Shape::y(int y){
	y_ = y;
}

/**
 * @brief draw shape at position
 * @details generates ps code for drawing a shape at the shape's set location
 * @return string containing ps code
 */
string Shape::operator()(){
	return draw(x_,y_);
}

/**
 * @brief draw shape at position
 * @details generates ps code for drawing shape at specified location
 * 
 * @param x x position of center of shape
 * @param y y position of center of shape
 * 
 * @return string containing ps code
 */
string Shape::operator()(int x, int y){
	return draw(x,y);
}

/**
 * @brief returns number of sides
 * @details returns number of sides of a shape, only defined for Polygon
 * @return if Polygon, returns number of sides. Otherwise returns 0.
 */
int Shape::numOfSides(){
	return 0;
}

/**
 * @brief returns side length
 * @details returns length of a side of a shape, only defined for Polygon
 * @return if Polygon, returns length of a side. Otherwise returns 0.
 */
double Shape::sideLength(){
	return 0;
}

/**
 * @brief returns radius
 * @details returns the radius of a shape, only defined for Polygon and Circle
 * @return if Polygon or Circle, returns the radius. Otherwise returns 0.
 */
double Shape::radius(){
	return 0;
}

/**
 * @brief overloaded output operator
 * @details prints the ps code for drawing the shape to the calling ostream
 * 
 * @param os target ostream, passed implicitly
 * @param shape Shape to print, passed implicitly
 */
ostream & operator<<(ostream &os, const Shape & shape){
	os << shape.draw();
	return os;
}