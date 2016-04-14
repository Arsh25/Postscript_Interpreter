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

int main(){

	std::cout << "Hello world! " << stringify(3.141592) << std::endl;
	std::cout << psLine(1,1,6,9) << std::endl;

	return 0;
}