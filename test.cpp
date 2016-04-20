#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
using std::string;
using std::make_pair;
#include <random>
using std::mt19937;
using std::random_device;
using std::uniform_real_distribution;
using std::uniform_int_distribution;
#include <algorithm>
using std::swap;

#include "rectangle.h"
#include "polygon.h"


/*	utils.h test functions 
	Functions to test utils.h functionality
	Calling these functions should return the same thing
	corresponding utils.h function. 
*/


string testPsLine(int x, int y)
{
	return to_string(x)+ " "+ to_string(y)+ " "+ "lineto\n" ; 
}

string testPsArc(int x, int y, double r, int startAngle, int endAngle )
{
	return to_string(x)+" "+ to_string(y)+" "+ to_string(r)+ " "+ to_string(startAngle) + " "+to_string(endAngle) + " arc";
}


double testCalcX(int k, int n, double l)
{
	return (l/2)*(sin(((2*k+1)*M_PI)/n)/(sin(M_PI/n)));
}

double testCalcY(int k, int n, double l)
{
	return (-l/2)*(cos(((2*k+1)*M_PI)/n)/(sin(M_PI/n)));		
}

double testGetwidth (int sides, double len)
{
	if (sides % 2 !=0)
	{
		return len*((sin(M_PI*(sides-1))/2*sides)/(sin(M_PI/sides)));
	}
	else
	{
		if (sides % 4 != 0)
		{
			return len*(1/(sin(M_PI/sides)));
		}
	
		else
		{
			return len*((cos(M_PI/sides))/(sin(M_PI/sides)));
		}
	}
}



string testPolyDraw (int x, int y, int sides, double length)
{
	stringstream ss;
	ss << "gsave\n";
	ss << "newpath\n";
	ss << x <<" " <<y << " translate\n";
	double vertX = testCalcX(0,sides,length);
	double vertY = testCalcY(0,sides,length);
	ss << vertX << " "<< vertY << " moveto\n";

	for(int i = 1; i < sides; i++){
		vertX = testCalcX(i,sides,length);
		vertY = testCalcY(i,sides,length);
		ss << vertX << " " << vertY << " lineto\n";
	}

	ss << "closepath\n";
	ss << "stroke\n";
	ss << "grestore\n";

	return ss.str();

}

TEST_CASE ("Testing utils drawing helpers","[Utils]")
{
	const int NUM = 5;
	random_device rndDev;
	mt19937 randomNum(rndDev());
	uniform_int_distribution<> posX1(0,842);
	uniform_int_distribution<>posY1 (0,595);
	uniform_int_distribution<> posX2(0,842);
	uniform_int_distribution<>posY2 (0,595);

	uniform_int_distribution<> startAngle(0,360);
	uniform_int_distribution<>endAngle (0,360);
	uniform_real_distribution<>radii(0,595);
	
	std::vector<int> x1Collection;
	std::vector<int> y1Collection;
	std::vector<int> x2Collection;
	std::vector<int> y2Collection;
	
	std::vector<int> startAngleCollection;
	std::vector<int> endAngleCollection;
	std::vector<double> radiiColection;

	for (int i=0; i<NUM; i++ )
	{
		x1Collection.push_back(posY1(rndDev));
		y1Collection.push_back(posY1(rndDev));
		x2Collection.push_back(posX2(rndDev));
		y2Collection.push_back(posY2(rndDev));

		startAngleCollection.push_back(startAngle(rndDev));
		endAngleCollection.push_back(endAngle(rndDev));
		radiiColection.push_back(radii(rndDev));
	}

	for (int i = 0; i<NUM; i++)
	{
		string expectedPS, returnedPS;
		expectedPS = testPsLine(x1Collection[i],y1Collection[i]);
		returnedPS = psLine(x1Collection[i],y1Collection[i]);
		REQUIRE(returnedPS == expectedPS);
		expectedPS=returnedPS=string();
		expectedPS = testPsArc(x1Collection[i], y1Collection[i], radiiColection[i]  , startAngleCollection[i],endAngleCollection[i]);
		returnedPS = psArc(x1Collection[i], y1Collection[i], radiiColection[i], startAngleCollection[i],endAngleCollection[i]);
		REQUIRE(returnedPS == expectedPS);
	}
}

TEST_CASE ("Testing Centers","[Utils]")
{
	const int NUM = 5;
	random_device rndDev;
	mt19937 randomNum(rndDev());
	uniform_real_distribution<> randomLen(0,842);
	std::vector<double> lenCollection;
	for (int i=0; i<NUM; i++ )
	{
		lenCollection.push_back(randomLen(rndDev));
	}
	//Testing Triangles 
	for (auto v:lenCollection)
	{
		REQUIRE(testCalcX(1,3,v) == calcX (1,3,v));
		REQUIRE(testCalcX(2,3,v) == calcX (2,3,v));
		REQUIRE(testCalcY(1,3,v) == calcY (1,3,v));
		REQUIRE(testCalcY(2,3,v) == calcY (2,3,v));
	}
	//Testing Squares 
	for (auto v:lenCollection)
	{
		REQUIRE(testCalcX(1,4,v) == calcX (1,4,v));
		REQUIRE(testCalcX(2,4,v) == calcX (2,4,v));
		REQUIRE(testCalcX(3,4,v) == calcX (3,4,v));
		REQUIRE(testCalcY(1,4,v) == calcY (1,4,v));
		REQUIRE(testCalcY(2,4,v) == calcY (2,4,v));
		REQUIRE(testCalcY(3,4,v) == calcY (3,4,v));
	}

	//Testing Pentagon
		for (auto v:lenCollection)
	{
		REQUIRE(testCalcX(1,5,v) == calcX (1,5,v));
		REQUIRE(testCalcX(2,5,v) == calcX (2,5,v));
		REQUIRE(testCalcX(3,5,v) == calcX (3,5,v));
		REQUIRE(testCalcX(4,5,v) == calcX (4,5,v));
		REQUIRE(testCalcY(1,5,v) == calcY (1,5,v));
		REQUIRE(testCalcY(2,5,v) == calcY (2,5,v));
		REQUIRE(testCalcY(3,5,v) == calcY (3,5,v));
		REQUIRE(testCalcY(4,5,v) == calcY (4,5,v));
	}

	
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
	Rectangle rect(0,0,width,height);

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

TEST_CASE("Polygon Draw","[Polygon] [draw function]")
{
    //numOfSides, sidelength
	Polygon poly1(0,0,1,1); 
	Polygon poly2(0,0,1,1);
	Polygon poly3(0,0,3,1); //Triangle
	Polygon poly4(0,0,4,10); //Square 
	Polygon poly5(0,0,10,10);
	Polygon poly6(0,0,9,23);
	Polygon poly7(0,0,10,230.345);

	REQUIRE(poly1.draw(72,72) == testPolyDraw(72,72,1,1));
	REQUIRE(poly2.draw(72,144) == testPolyDraw(72,144,1,1));
	REQUIRE(poly3.draw(72,72) == testPolyDraw(72,72,3,1));
	REQUIRE(poly4.draw(72,72) == testPolyDraw(72,72,4,10));
	REQUIRE(poly5.draw(72,72) == testPolyDraw(72,72,10,10));
	REQUIRE(poly6.draw(72,72) == testPolyDraw(72,72,9,23));
	REQUIRE(poly7.draw(72,72) == testPolyDraw(72,72,10,230.345));
}

TEST_CASE("Shape operator <<","[Shape] [operator <<]")
{
	const int NUM = 5;
	random_device rndDev;
	mt19937 randomNum(rndDev());
	uniform_real_distribution<> randomLen(0,842);
	std::vector<double> lenCollection;
	stringstream returnedPS;
	for (int i=0; i<NUM; i++ )
	{
		lenCollection.push_back(randomLen(rndDev));
	}
	for(auto len : lenCollection)
	{	
		returnedPS.str("");
		Polygon poly1(2,len);
		returnedPS << poly1;
		REQUIRE(returnedPS.str()  == testPolyDraw (0,0,2,len));
		returnedPS.str("");
		Triangle tri1(len);
		returnedPS << tri1;
		REQUIRE(returnedPS.str() == testPolyDraw (0,0,3,len));
		Square square1(len);
		returnedPS.str("");
		returnedPS << square1;
		REQUIRE(returnedPS.str() == testPolyDraw (0,0,4,len));
	}
}