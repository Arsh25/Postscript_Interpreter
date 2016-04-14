#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
using std::string;

#include "rectangle.h"

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