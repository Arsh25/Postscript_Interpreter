/*
 * layered.cpp
 * 4/15/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "layered.h"

/**
 * @brief Layered constructor
 * @details constructs a Layered shape from a list of shapes
 * 
 * @param x x position of center
 * @param y y position of center
 * @param shapes list of pointers to Shapes
 */
Layered::Layered(int x, int y, initializer_list<Shape*> shapes) : Shape(x,y), shapes_(shapes) {
	double width=0,height=0;
	for(auto shape: shapes_){
		width = max(width,shape->width());
		height = max(height,shape->height());
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Layered::draw() const{
	return draw(x_,y_);
}

string Layered::draw(int x, int y) const{
	stringstream ss;

	ss << psHeader(x,y);

	for(auto shape: shapes_){
		ss << shape->draw(0,0) << "\n";
	}

	ss << psFooter();

	return ss.str();
}

/**
 * @brief Horizontal costructor
 * @details constructs a Horizontal shape from a list of Shapes
 * 
 * @param x x position of center
 * @param y y position of center
 * @param shapes list of pointers to Shapes
 */
Horizontal::Horizontal(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes){
	double width=0,height=0;
	for(auto shape: shapes_){
		width += shape->width();
		height = max(height,shape->height());
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Horizontal::draw() const{
	return draw(x_,y_);
}

string Horizontal::draw(int x, int y) const{
	stringstream ss;

	ss << psHeader(x,y);

	double half = boundsWidth_/2;

	for(auto shape: shapes_){
		ss << shape->draw( half-(shape->width()/2), 0) << "\n";
		half -= shape->width();
	}

	ss << psFooter();

	return ss.str();
}

/**
 * @brief Vertical constructor
 * @details constructs a Vertical shape from a list of Shapes
 * 
 * @param x x position of center
 * @param y y position of center
 * @param shapes list of pointers to Shapes
 */
Vertical::Vertical(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes){
	double width=0,height=0;
	for(auto shape: shapes_){
		width = max(width,shape->width());
		height += shape->height();
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Vertical::draw() const{
	return draw(x_,y_);
}

string Vertical::draw(int x, int y) const{
	stringstream ss;

	ss << psHeader(x,y);

	double half = boundsHeight_/2;

	for(auto shape: shapes_){
		string name = string(typeid(*shape).name()).substr(1);
		if(name == "Triangle"){
			ss << shape->draw(0, half-(shape->radius())) << "\n";
		} else {
			ss << shape->draw(0, half-(shape->height()/2) ) << "\n";
		}
		half -= shape->height();
	}

	ss << psFooter();

	return ss.str();
}



