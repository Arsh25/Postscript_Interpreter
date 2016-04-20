/*
 * main.cpp
 * 4/3/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "shape.h"

#include "circle.h"

#include "polygon.h"

#include "rectangle.h"
#include "spacer.h"

#include "layered.h"

#include "rotate.h"
#include "scaled.h"

#include "utils.h"

#include "star.h"

#include <typeinfo>

#include <iostream>
using std::cout;
using std::endl;

int main(){

	// ***** Basic Shape Constructors *****
	// If x & y coordinates are not set, default location is (0,0)
	Circle circle1(25);							// Circle(double radius)
	Circle circle2(100,700,20); 				// Circle(int x, int y, double radius)

	Square square1(50);							// Square(double side)
	Square square2(200,150,40);					// Square(int x, int y, double side)

	Triangle triangle1(30);						// Triangle(double side)
	Triangle triangle2(300,700,40);				// Triangle(int x, int y, double side)

	Rectangle rectangle1(50.0, 100.0);			// Rectangle(double w, double h)
	Rectangle rectangle2(300,300,100.0, 50.0);	// Rectangle(int x, int y, double w, double h)

	Star star1(5,10,30);						// Star(int n, double oRadius, double iRadius)
	Star star2(200,300,5,10,30);				// Star(int x, int y, int n, double oRadius, double iRadius)

	Polygon poly6(6,55.5);						// Polygon(int sides, double length)
	Polygon poly10(200,500,10,16);				// Polygon(int x, int y, int sides, double length)
	Polygon poly25(300,500,25,12);



	// ***** Compound Shape Constructors *****
	Scaled sCircle(&circle1,0.5,1.5);			// Scaled(Shape* shape, double sx, double sy)
	Scaled sHexagon(&poly6,2.0,1.5);

	Rotated rSquare(&square1,30);				// Rotated(Shape * shape, int angle)
	Rotated rStar(&star1,90);

	// Layered(initializer_list<Shape*> shapes)
	// Layered(int x, int y, initializer_list<Shape*> shapes)
	Layered layered{&circle1,&triangle1,&rectangle2,&poly6,&poly25,&rSquare};

	Spacer spacer1(50.0,50.0);					//Spacer(double w, double h)
	Spacer spacer2(50,100,25.0,50.0);			//Spacer(int x, int y, double w, double h)

	// Vertical(initializer_list<Shape*> shapes)
	// Vertical(int x, int y, initializer_list<Shape*> shapes)
	Vertical vertical(500,350,{&circle2,&square1,&triangle2,&rectangle1,&spacer2,&poly10,&rStar});

	// Horizontal(initializer_list<Shape*> shapes)
	// Horizontal(int x, int y, initializer_list<Shape*> shapes)
	Horizontal horizontal(300,100,{&square2,&triangle1,&spacer1,&rectangle2,&poly6,&star1,&poly25,&sCircle,&rSquare});

	// cout << triangleTest.draw() << endl;



	// ***** Begin Postscript *****
	cout << psBegin() << endl;

	// ***** 4 Ways to Print Shapes *****
	cout << circle2 << endl;						// 1: << shapeName
	cout << square1(200,700) << endl;				// 2: shapeName(int x, int y)
	cout << triangle2.draw() << endl;				// 3: shapeName.draw()
	cout << rectangle1.draw(400,700) << endl;		// 4: shapeName.draw(int x, int y)

	cout << poly6(100,500) << endl;
	cout << poly10 << endl;
	cout << poly25 << endl;
	cout << sCircle(400,500) << endl;

	cout << rSquare.draw(100,300) << endl;
	cout << star2 << endl;
	cout << layered(350,300) << endl;

	cout << vertical(500,450) << endl;
	cout << horizontal(300,100) << endl;

	// ***** Print Page / Page Break *****
	cout << psPageBreak() << endl;

	return 0;
}