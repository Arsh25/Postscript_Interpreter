#include "shape_decorator.h"



/**
 * @brief generate ps code for shape
 * @details generate ps code for drawing shape at default location
 * @return string containing ps code for drawing shape at default location
 */
string ShapeDecorator::draw() const{
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
string ShapeDecorator::draw(int x,int y) const{
	return "";
}


void ShapeDecorator::print(ostream & os) const{
	os << this->draw();
}


ostream & operator<<(ostream &os, const ShapeDecorator & shape){
	shape.print(os);
	return os;
}