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
	Polygon() : Shape(), numOfSides_(0), sideLength_(0) {};
	Polygon(int sides, double length) : Shape(), numOfSides_(sides), sideLength_(length) {};

	string draw(int x,int y) override;

protected:
	int numOfSides_;
	double sideLength_;

}; //end of class Polygon



class Triangle : public Polygon
{
public:
	Triangle() : Polygon(3,0) {};
	Triangle(double side) : Polygon(3,side) {};

	string draw(int x,int y) override;


private:


}; //end of class Triangle



class Square: public Polygon
{
public:
	Square(): Polygon(4,0) {};
	Square(double side): Polygon(4,side) {};

	string draw(int x,int y) override;


private:


}; //end of class Square


#endif