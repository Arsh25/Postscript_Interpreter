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
	Rectangle(): Shape() {};
	Rectangle(double w, double h): Shape(), w_(w), h_(h) {};
	Rectangle(int x, int y, double w, double h): Shape(x,y), w_(w), h_(h) {};
	Rectangle(pair<int,int> center, double w, double h): Shape(center), w_(w), h_(h) {};

private:
	double w_;
	double h_;

}; //end of class Rectangle

#endif