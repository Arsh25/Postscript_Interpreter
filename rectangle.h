/*
 * rectangle.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "shape.h"

class Rectangle: public Shape
{
public:
	Rectangle(): Shape(), width_(0), height_(0) {};
	Rectangle(double w, double h): Shape(), width_(w), height_(h) {};
	Rectangle(int x, int y, double w, double h): Shape(x,y), width_(w), height_(h) {};
	Rectangle(pair<int,int> center, double w, double h): Shape(center), width_(w), height_(h) {};

protected:
	double width_;
	double height_;

}; //end of class Rectangle

#endif