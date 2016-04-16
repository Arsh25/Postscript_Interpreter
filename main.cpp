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
	Polygon poly25(300,100,25,12);

	Scaled scaled(&triangle,0.5,1.5);
	Rotated rotated(&square,45);

	cout << "%!\n" << endl;

	cout << circle << endl;
	cout << square << endl;
	cout << triangle << endl;
	cout << triangle.draw(400,400) << endl;
	cout << rect << endl;
	cout << poly6 << endl;
	cout << poly10 << endl;
	cout << poly25 << endl;

	cout << scaled << endl;
	cout << rotated << endl;

	cout << "showpage" << endl;

	return 0;
}