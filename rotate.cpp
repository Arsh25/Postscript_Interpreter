/*
 * rotate.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "rotate.h"

Rotated::Rotated(Shape * shape, int angle): Shape(), shape_(shape), angle_(angle){
	string name = string(typeid(*shape).name()).substr(1);

	if(name == "Circle" || name == "Star"){
		boundsWidth_ = shape->width();
		boundsHeight_ = shape->height();
	} else if (name == "Square" || name == "Rectangle" || name == "Rotated" || name == "Scaled"){
		boundsWidth_ = (shape->height() * cos((M_PI/2)-angle*(M_PI/180))) + (shape->width() * sin((M_PI/2)-angle*(M_PI/180)));
		boundsHeight_ = (shape->width() * cos((M_PI/2)-angle*(M_PI/180))) + (shape->height() * sin((M_PI/2)-angle*(M_PI/180)));
	} else if (name == "Polygon" || name == "Triangle") {
		double minX = shape->radius() * cos( angle*(M_PI/180) );
		double maxX = minX;

		double minY = shape->radius() * sin( angle*(M_PI/180) );
		double maxY = minY;

		for(int i = 1; i < shape->numOfSides(); i++){
			double tempX = shape->radius() * cos( angle*(M_PI/180) + (2*i*M_PI)/shape->numOfSides() );
			minX = min(minX,tempX);
			maxX = max(maxX,tempX);

			double tempY = shape->radius() * sin( angle*(M_PI/180) + (2*i*M_PI)/shape->numOfSides() );
			minY = min(minY,tempY);
			maxY = max(maxY,tempY);
		}

		boundsWidth_ = maxX - minX;
		boundsHeight_ = maxY - minY;
	}
}

string Rotated::draw() const{
	return draw(shape_->x(),shape_->y());
}

string Rotated::draw(int x, int y) const
{
	stringstream ss;

	ss << psHeader(x,y);

	ss << angle_ << " rotate\n";
	ss << (*shape_)(0,0);

	ss << psFooter();

	return ss.str();
}