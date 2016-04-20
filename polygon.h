/*
 * polygon.h
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "shape.h"

class Polygon: public Shape
{
public:
	Polygon() 
		: Shape(), 
			numOfSides_(0), 
			sideLength_(0), 
			radius_(0) 
			{};

	Polygon(int x, int y, int sides, double length) 
		: Shape(x, y, getWidth(sides,length),getHeight(sides,length)), 
			numOfSides_(sides), 
			sideLength_(length),
			radius_(getRadius(sides,length))
			{};

	Polygon(int sides, double length) 
		: Polygon(0,0,sides,length) 
			{};

	string draw(int x,int y) const;

	int numOfSides();
	double sideLength();
	double radius();

protected:
	/**
	 * number of sides of the polygon
	 */
	int numOfSides_;
	/**
	 * length of polygon's sides
	 */
	double sideLength_;
	/**
	 * radius of polygon
	 */
	double radius_;

}; //end of class Polygon



class Triangle : public Polygon
{
public:
	Triangle() : Polygon(0,0,3,0) {};
	Triangle(int x, int y, double side) : Polygon(x,y,3,side) {};
	Triangle(double side) : Triangle(0,0,side) {};

}; //end of class Triangle



class Square: public Polygon
{
public:
	Square(): Polygon(0,0,4,0) {};
	Square(int x, int y, double side): Polygon(x,y,4,side) {};
	Square(double side) : Square(0,0,side) {};
	
}; //end of class Square


#endif