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

	Circle c(16);

	std::cout << "%!\n" << std::endl;
	std::cout << c.draw(100,100) << std::endl;
	std::cout << c.draw(150,150) << std::endl;

	Rectangle r(100.0, 50.0);
	cout << r.draw(300,300) << endl;

	std::cout << "showpage\n" << std::endl;
	return 0;
}