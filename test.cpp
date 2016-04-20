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
	return to_string(x)+ " "+ to_string(y)+ " lineto\n" ; 
}

string testPsMove (int x, int y)
{
	return to_string(x) + " " + to_string(y) + " " +"moveto\n";
}

string testPsArc(int x, int y, double r, int startAngle, int endAngle )
{
	return to_string(x)+" "+ to_string(y)+" "+ to_string(r)+ " "+ to_string(startAngle) + " "+to_string(endAngle) + " arc\n";
}

string testPsHeader (int x, int y)
{
	return "gsave\nnewpath\n" + to_string(x) + " " + to_string(y) + " " + "translate\n";
}

string testPsFooter ()
{
	return "closepath\nstroke\nstroke\n";
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
		return (len*((sin(M_PI*(sides-1))/ (2*sides)))/(sin(M_PI/sides)));
	}
	else
	{
		if (sides % 4 != 0)
		{
			return (len*(1/(sin(M_PI/sides))));
		}
	
		else
		{
			return (len*((cos(M_PI/sides))/(sin(M_PI/sides))));
		}
	}
}



string testPolyDraw (int x, int y, int sides, double length)
{
	stringstream ss;
	ss << testPsHeader(x,y);
	double vertX = testCalcX(0,sides,length);
	double vertY = testCalcY(0,sides,length);
	ss << testPsMove(vertX,vertY);

	for(int i = 1; i < sides; i++){
		vertX = testCalcX(i,sides,length);
		vertY = testCalcY(i,sides,length);
		ss << testPsLine(vertX,vertY);
	}

	ss << testPsFooter();

	return ss.str();

}

TEST_CASE ("Testing utils drawing helpers","[Utils]")
{
	const int NUM = 5;
	random_device rndDev;
	mt19937 randomNum(rndDev());
	uniform_int_distribution<> posx(0,842);
	uniform_int_distribution<>posy (0,595);

	uniform_int_distribution<> startAngle(0,360);
	uniform_int_distribution<>endAngle (0,360);
	uniform_real_distribution<>radii(0,595);
	
	std::vector<int> xCollection;
	std::vector<int> yCollection;
	
	std::vector<int> startAngleCollection;
	std::vector<int> endAngleCollection;
	std::vector<double> radiiColection;

	string expectedPS, returnedPS;
	for (int i=0; i<NUM; i++ )
	{
		xCollection.push_back(posx(rndDev));
		yCollection.push_back(posy(rndDev));

		startAngleCollection.push_back(startAngle(rndDev));
		endAngleCollection.push_back(endAngle(rndDev));
		radiiColection.push_back(radii(rndDev));
	}

	for (int i = 0; i<NUM; i++)
	{
		expectedPS = testPsLine(xCollection[i],yCollection[i]);
		returnedPS = psLine(xCollection[i],yCollection[i]);
		REQUIRE(returnedPS == expectedPS);
		
		expectedPS=returnedPS=string();
		expectedPS = testPsArc(xCollection[i], yCollection[i], radiiColection[i] , startAngleCollection[i],endAngleCollection[i]);
		returnedPS = psArc(xCollection[i], yCollection[i], radiiColection[i], startAngleCollection[i],endAngleCollection[i]);
		REQUIRE(returnedPS == expectedPS);

		//Testing psMove
		expectedPS=returnedPS=string();
		expectedPS = testPsMove(xCollection[i],yCollection[i]);
		returnedPS = psMove(xCollection[i],yCollection[i]);

		//Testing psHeader
		expectedPS=returnedPS=string();
		expectedPS = testPsHeader(xCollection[i],yCollection[i]);
		returnedPS = psHeader(xCollection[i],yCollection[i]);		

	}
	//Testing psFooter
		expectedPS=returnedPS=string();
		expectedPS = testPsFooter();
		returnedPS = psFooter();
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

/*TEST_CASE ("Testing width and height calculations","[Utils]")
{
	const int NUM = 5;
	random_device rndDev;
	mt19937 randomNum(rndDev());
	uniform_real_distribution<double> len(0,842);
	uniform_int_distribution<>sides (0,1000);

	double expectWidth, expectHeight;
	double returnedWidth, returnedHeight;

	std::vector<double> lenCollection;
	std::vector<int> sidesCollection;

	lenCollection = {72,144, 150.45, 160, 621, 630.79};
	sidesCollection = {2,3,4,5,6,10,12,13};
	for(auto v : lenCollection)
	{
		expectWidth = testGetwidth(sidesCollection[0],v);
		returnedWidth = getWidth(sidesCollection[0],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[1],v);
		returnedWidth = getWidth(sidesCollection[1],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[2],v);
		returnedWidth = getWidth(sidesCollection[2],v);
		//REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[3],v);
		returnedWidth = getWidth(sidesCollection[3],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[4],v);
		returnedWidth = getWidth(sidesCollection[4],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[5],v);
		returnedWidth = getWidth(sidesCollection[5],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[6],v);
		returnedWidth = getWidth(sidesCollection[6],v);
		REQUIRE(expectWidth == returnedWidth);
		expectWidth = testGetwidth(sidesCollection[7],v);
		returnedWidth = getWidth(sidesCollection[7],v);
		REQUIRE(expectWidth == returnedWidth);
	}


}*/

TEST_CASE ("Rectangle Construction","[Rectangle]")
{
	Rectangle defaultRect;
	string postScript, expectPS;
	postScript = defaultRect.draw(72,72);

	//Helper variables, keeps test interface 
	// similar to internal interface
	int width, height, x, y;
	width = 72;
	height = 144;
	x=y=72; //Draw 1 inch from left edge
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

TEST_CASE("Shape operator ()","[Shape] [operator ()]")
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
		returnedPS << poly1(0,0);
		REQUIRE(returnedPS.str()  == testPolyDraw (0,0,2,len));
		returnedPS.str("");
		Triangle tri1(len);
		returnedPS << tri1(10,10);
		REQUIRE(returnedPS.str() == testPolyDraw (10,10,3,len));
		Square square1(len);
		returnedPS.str("");
		returnedPS << square1(20,20);
		REQUIRE(returnedPS.str() == testPolyDraw (20,20,4,len));
	}
}