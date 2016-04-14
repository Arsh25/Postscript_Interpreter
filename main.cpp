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

#include "shape_decorator.h"

#include "layered.h"
#include "horizontal.h"
#include "vertical.h"

#include "rotate.h"
#include "scaled.h"

#include "utils.h"


#include <iostream>
using std::cout;
using std::endl;

int main(){

	Circle circle(20);
	Square square(40);
	Triangle triangle(40);
	Rectangle rect(100.0, 50.0);
	Polygon poly6(6,55.5);
	Polygon poly10(10,16);

	Scaled scaled(&triangle,0.5,1.5);
	Rotated rotated(&square,45);

	std::cout << "%!\n" << std::endl;

	std::cout << circle.draw(100,100) << std::endl;

	std::cout << square.draw(200,150) << std::endl;

	std::cout << triangle.draw(100,200) << std::endl;

	std::cout << scaled.draw(100,300) << std::endl;

	std::cout << rotated.draw(300,150) << std::endl;

	std::cout << rect.draw(300,300) << std::endl;

	std::cout << poly6.draw(100,300) << std::endl;

	std::cout << poly10.draw(100,400) << std::endl;

	// std::cout << "showpage\n" << std::endl;
	return 0;
}