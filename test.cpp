#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
using std::string;
using std::make_pair;

#include "rectangle.h"
#include "polygon.h"

pair<double,double> testGetPoint (int k, int sides, double length)
{
	double x = (length/2)*(sin((((2*k)+1)*PI)/sides))/(sin(PI/sides));
	double y = (-length/2)*(cos((((2*k)+1)*PI)/sides))/(sin(PI/sides));
	return make_pair(x,y);

}

string testPolyDraw (int x, int y, int sides, int length)
{
	stringstream ss;
	ss << "gsave\n";
	ss << "newpath\n";
	ss << x <<" " <<y << " translate\n";
	pair<double,double> vertex = testGetPoint(0,sides,length);
	ss << vertex.first << " "<< vertex.second << " moveto\n";

	for(int i = 1; i < sides; i++){
		vertex = testGetPoint(i,sides,length);
		ss << vertex.first << " " << vertex.second << " lineto\n";
	}

	ss << "closepath\n";
	ss << "stroke\n";
	ss << "grestore\n";

	return ss.str();

}

TEST_CASE ("Rectangle Construction","[Rectangle]")
{
	Rectangle defaultRect;
	string postScript, expectPS;
	postScript = defaultRect.draw(72,72);
	expectPS = "newpath\n72 72 moveto\n72 72 lineto\n";
	expectPS+= "72 72 lineto\n72 72 lineto\nclosepath\n";
	expectPS+= "stroke\n";

	REQUIRE( postScript == expectPS);

	postScript = defaultRect.draw(75,75);
	expectPS = "newpath\n75 75 moveto\n75 75 lineto\n";
	expectPS+= "75 75 lineto\n75 75 lineto\nclosepath\n";
	expectPS+= "stroke\n";

	REQUIRE( postScript == expectPS);

	//Helper variables, keeps test interface 
	// similar to internal interface
	int llx, lly, width, height, x, y;
	width = 72;
	height = 144;
	x=y=72; //Draw 1 inch from left edge
	llx = x - (width/2);
	lly = y - (height/2);
	Rectangle rect(width,height);

	stringstream expectedPS;

	expectedPS << "newpath\n";
	expectedPS << (llx) << " " << (lly) <<" moveto\n";
	expectedPS << (llx + width) << " " <<(lly) << " lineto\n";
	expectedPS << (llx + width) << " " <<(lly + height) << " lineto\n";
	expectedPS << (llx) <<" " << (lly + height) << " lineto\n";
	expectedPS << "closepath\n";
	expectedPS << "stroke\n";

	postScript = rect.draw(x,y);
	REQUIRE(postScript == expectedPS.str());
}

TEST_CASE("Polygon Draw","[Polygon]")
{
    //numOfSides, sidelength
	Polygon poly1(1,1); 
	Polygon poly2(1,1);
	Polygon poly3(4,1); //Square
	Polygon poly4(3,10); //Triangle 
	Polygon poly5(10,10);
	Polygon poly6(10,23.6);

	REQUIRE(poly1.draw(72,72) == testPolyDraw(72,72,1,1));
	REQUIRE(poly2.draw(72,144) == testPolyDraw(72,144,1,1));
	REQUIRE(poly3.draw(72,72) == testPolyDraw(144,144,4,1));


}