/*
 * layered.cpp
 * 4/15/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "layered.h"

Layered::Layered(int x, int y, initializer_list<Shape*> shapes) : Shape(x,y), shapes_(shapes){
	double width=0,height=0;
	for(auto shape: shapes_){
		width = max(width,shape->width());
		height = max(height,shape->height());
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Layered::draw(int x, int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << x << " " << y << " translate\n";

	for(auto shape: shapes_){
		ss << shape->draw(0,0) << "\n";
	}

	ss << "grestore\n"; 
	return ss.str();
}



Horizontal::Horizontal(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes){
	double width=0,height=0;
	for(auto shape: shapes_){
		width += shape->width();
		height = max(height,shape->height());
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Horizontal::draw(int x, int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << x << " " << y << " translate\n";

	double half = boundsWidth_/2;

	for(auto shape: shapes_){
		ss << shape->draw( half-(shape->width()/2), 0) << "\n";
		half -= shape->width();
	}

	ss << "grestore\n";
	return ss.str();
}



Vertical::Vertical(int x, int y, initializer_list<Shape*> shapes) : Layered(x,y,shapes){
	double width=0,height=0;
	for(auto shape: shapes_){
		width = max(width,shape->width());
		height += shape->height();
	}
	boundsWidth_ = width;
	boundsHeight_ = height;
}

string Vertical::draw(int x, int y) const{
	stringstream ss;

	ss << "gsave\n";
	ss << x << " " << y << " translate\n";

	double half = boundsHeight_/2;

	for(auto shape: shapes_){
		ss << shape->draw(0, half-(shape->height()/2) ) << "\n";
		half -= shape->height();
	}

	ss << "grestore\n";
	return ss.str();
}



