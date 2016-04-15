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

#include "rotate.h"
#include "scaled.h"

#include "utils.h"


#include <iostream>
using std::cout;
using std::endl;

int main(){

	Circle circle(100,100,20);
	Square square(200,150,40);
	Triangle triangle(100,200,40);
	Rectangle rect(300,300,100.0, 50.0);
	Polygon poly6(100,300,6,55.5);
	Polygon poly10(100,400,10,16);

	Scaled scaled(&triangle,0.5,1.5);
	Rotated rotated(&square,45);

	cout << "%!\n" << endl;

	cout << circle << endl;
	cout << square << endl;
	cout << triangle << endl;
	cout << rect << endl;
	cout << poly6 << endl;
	cout << poly10 << endl;

	cout << scaled << endl;
	cout << rotated << endl;

	cout << "showpage" << endl;

	// std::cout << circle.draw(100,100) << std::endl;

	// std::cout << square.draw(200,150) << std::endl;

	// std::cout << triangle.draw(100,200) << std::endl;

	// std::cout << scaled.draw(100,300) << std::endl;

	// std::cout << rotated.draw(300,150) << std::endl;

	// std::cout << rect.draw(300,300) << std::endl;

	// std::cout << poly6.draw(100,300) << std::endl;

	// std::cout << poly10.draw(100,400) << std::endl;


	// std::cout << "showpage\n" << std::endl;
	return 0;
}