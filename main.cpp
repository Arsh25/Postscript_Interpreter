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

	Circle circle(100,100,20);
	Square square(200,150,40);
	Triangle triangle(100,200,40);
	Rectangle rect(300,300,100.0, 50.0);
	Polygon poly6(100,300,6,55.5);
	Polygon poly10(100,400,10,16);
	Polygon poly25(300,100,25,12);

	Scaled scaled(&triangle,0.5,1.5);
	Rotated rotated(&square,30);
	Rotated rTriangle(&triangle,15);

	cout << "%!\n" << endl;

	cout << circle << endl;
	cout << square << endl;
	cout << triangle << endl;
	cout << rect << endl;
	cout << poly6 << endl;
	cout << poly10 << endl;
	cout << poly25 << endl;

	cout << scaled(400,400) << endl;
	cout << rotated.draw(250,200) << endl;

	Layered layered({&circle,&square,&triangle,&rect,&poly6,&poly10,&poly25,&scaled,&rotated,&rTriangle});
	cout << layered(250,500) << endl;

	Vertical vertical({&circle,&square,&triangle,&rect,&poly6,&poly10,&poly25,&scaled,&rotated,&rTriangle});
	cout << vertical(500,350) << endl;

	Horizontal horizontal({&circle,&square,&triangle,&rect,&poly6,&poly10,&poly25,&scaled,&rotated,&rTriangle});
	cout << horizontal(300,700) << endl;

	Triangle triangleTest(30);
	Circle circleTest(triangleTest.radius());
	Rotated rTriOne(&triangleTest,30);
	Rotated rTriTwo(&triangleTest,60);
	Rotated rTriThr(&triangleTest,90);

	cout << triangleTest(100,500) << endl;
	cout << circleTest(100,500) << endl;
	cout << rTriOne(100,500) << endl;
	cout << rTriTwo(100,500) << endl;
	cout << rTriThr(100,500) << endl;

	Star star(5,10,30);
	cout << star(100,600) << endl;

	Rotated rStar(&star,90);
	cout << rStar(150,600) << endl;


	cout << "showpage" << endl;

	// cout << square.bounds() << endl;
	// cout << rotated.bounds() << endl;

	// cout << triangle.bounds() << endl;
	// cout << triangle.radius() << endl;
	// cout << rTriangle.bounds() << endl;

	return 0;
}