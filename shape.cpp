/*
 * shape.cpp
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "shape.h"

//moved Shape constructor declarations to shape.cpp 
//because derived classes couldn't find them otherwise
Shape::Shape() : center_(0,0) {}
Shape::Shape(int x, int y) : center_(x,y) {}
Shape::Shape(pair<int,int> center) : center_(center) {}