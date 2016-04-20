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
#include "spacer.h"
#include "circle.h"

//Complex Shapes
#include "layered.h"
#include "rotate.h"
#include "star.h" //Our custom shape
#include "scaled.h"



/*	utils.h test functions 
	Functions to test utils.h functionality
	Calling these functions should return the same thing
	corresponding utils.h function. 
*/

//error in doubles
const double ERROR = 0.0000001;


string testPsLine(int x, int y)
{
	return to_string(x)+ " "+ to_string(y)+ " lineto\n" ; 
}

string testPsMove (int x, int y)
{
	return to_string(x) + " " + to_string(y) + " moveto\n";
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
	return "closepath\nstroke\ngrestore\n";
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
		return (len * (sin( M_PI * (sides-1) / ( 2*sides )))/(sin(M_PI/sides)));
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

double testGetHeight(int n,double l){
	if(n%2 == 0){
		return (l * (cos(M_PI/n)) / (sin(M_PI/n)));
	} else {
		return (l * (1+cos(M_PI/n)) / (2*sin(M_PI/n)));
	}
}

double testGetRadius(int n,double l){
	return l/(2*sin(M_PI/n));
}

double testGetConvexX(int k, int n, double r){
	return r * cos(2 * M_PI * k / n);
}

double testGetConvexY(int k, int n, double r){
	return r * sin(2 * M_PI * k / n);
}

double testGetConcaveX(int k, int n, double r){
	return r * cos( (2 * M_PI * k + M_PI) / n);
}

double testGetConcaveY(int k, int n, double r){
	return r * sin( (2 * M_PI * k + M_PI) / n);
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

string testCircleDraw(int x, int y, double radius)
{
	stringstream ss;
	ss << testPsHeader(x,y);
	ss << testPsArc(0,0, radius,0,360);
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
		REQUIRE(expectedPS == returnedPS);

		//Testing psHeader
		expectedPS=returnedPS=string();
		expectedPS = testPsHeader(xCollection[i],yCollection[i]);
		returnedPS = psHeader(xCollection[i],yCollection[i]);		
		REQUIRE(expectedPS == returnedPS);
	}
	//Testing psFooter
		expectedPS=returnedPS=string();
		expectedPS = testPsFooter();
		returnedPS = psFooter();
		REQUIRE(expectedPS == returnedPS);
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


TEST_CASE ("Testing width and height calculations","[Utils]")
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

	for (int i=0;i<NUM;i++)
	{
		lenCollection.push_back(len(rndDev));
		sidesCollection.push_back(sides(rndDev));
	}

	for(int i=0;i<NUM;i++)
	{
		SECTION ("Testing Width")
		{
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
			expectWidth = testGetwidth(sidesCollection[i],lenCollection[i]);
			returnedWidth = getWidth(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectWidth - returnedWidth) <= ERROR);
		}
		SECTION("Testing height")
		{
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
			expectHeight = testGetHeight(sidesCollection[i],lenCollection[i]);
			returnedHeight = getHeight(sidesCollection[i],lenCollection[i]);
			REQUIRE( abs(expectHeight - returnedHeight) <= ERROR);
		}
	}
}

TEST_CASE ("Simple Shape Default Construction","[Construction]")
{
	Rectangle defaultRect;
	string postScript, expectPS;
	postScript = defaultRect.draw(72,72);
	expectPS = testPolyDraw(72,72,4,0);
	REQUIRE(expectPS == postScript);

	Square defaultSquare;
	postScript = defaultSquare.draw(72,72);
	expectPS = testPolyDraw(72,72,4,0);
	REQUIRE(expectPS == postScript);

	Triangle defaultTri;
	postScript = defaultTri.draw(72,72);
	expectPS = testPolyDraw(72,72,3,0);
	REQUIRE(expectPS == postScript);

	Polygon defaultPoly;
	postScript = defaultPoly.draw(72,72);
	expectPS = testPolyDraw(72,72,0,0);
	REQUIRE(expectPS == postScript);	

	Spacer defaultSpacer;
	postScript = defaultSpacer.draw(72,72);
	expectPS = "";
	REQUIRE(expectPS == postScript);

	Circle defaultCircle;
	postScript = defaultCircle.draw(72,72);
	expectPS = testCircleDraw(72,72,0);
	REQUIRE(expectPS == postScript);	

}

TEST_CASE( "Simple Shape Construction", "Construction")
{
	SECTION ("Polygons")
	{
		const int NUM = 5;
		random_device rndDev;
		mt19937 randomNum(rndDev());
		uniform_real_distribution<> len(0,842);
		uniform_int_distribution<>x (0,842);
		uniform_int_distribution<>y (0,595);

		std::vector<double> lenCollection;
		std::vector<int> xCollection;
		std::vector<int> yCollection;
		std::vector<int> sidesCollection = {2,3,4,5,6,7,8,9,10,100,1000};

		string expectedPS, returnedPS;

		for(int i=0; i<NUM; i++)
		{
			lenCollection.push_back(len(rndDev));
			xCollection.push_back(x(rndDev));
			yCollection.push_back(y(rndDev));
		}
		for (int i = 0; i < NUM; ++i)
		{
			Polygon poly1(xCollection[i],yCollection[i],4,lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = poly1.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly2(xCollection[i],yCollection[i],4,lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = poly2.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly3(xCollection[i],yCollection[i],4,lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = poly3.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly4(xCollection[i],yCollection[i],sidesCollection[3],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[3],lenCollection[i]);
			returnedPS = poly4.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly5(xCollection[i],yCollection[i],sidesCollection[4],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[4],lenCollection[i]);
			returnedPS = poly5.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly6(xCollection[i],yCollection[i],sidesCollection[5],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[5],lenCollection[i]);
			returnedPS = poly6.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly7(xCollection[i],yCollection[i],sidesCollection[6],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[6],lenCollection[i]);
			returnedPS = poly7.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly8(xCollection[i],yCollection[i],sidesCollection[7],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[7],lenCollection[i]);
			returnedPS = poly8.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly9(xCollection[i],yCollection[i],sidesCollection[8],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[8],lenCollection[i]);
			returnedPS = poly9.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly10(xCollection[i],yCollection[i],sidesCollection[9],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[9],lenCollection[i]);
			returnedPS = poly10.draw();
			REQUIRE(expectedPS == returnedPS);
			Polygon poly11(xCollection[i],yCollection[i],sidesCollection[10],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],sidesCollection[10],lenCollection[i]);
			returnedPS = poly11.draw();
			REQUIRE(expectedPS == returnedPS);

		}

	}
	SECTION ("Squares")
	{
		const int NUM = 5;
		random_device rndDev;
		mt19937 randomNum(rndDev());
		uniform_real_distribution<> len(0,842);
		uniform_int_distribution<>x (0,842);
		uniform_int_distribution<>y (0,595);

		std::vector<double> lenCollection;
		std::vector<int> xCollection;
		std::vector<int> yCollection;

		string expectedPS, returnedPS;

		for(int i=0; i<NUM; i++)
		{
			lenCollection.push_back(len(rndDev));
			xCollection.push_back(x(rndDev));
			yCollection.push_back(y(rndDev));
		}
		for (int i = 0; i < NUM; ++i)
		{
			Square square1(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square1.draw();
			REQUIRE(expectedPS == returnedPS);
			Square sqaue2(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = sqaue2.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square3(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square3.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square4(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square4.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square5(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square5.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square6(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square6.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square8(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square8.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square9(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square9.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square10(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square10.draw();
			REQUIRE(expectedPS == returnedPS);
			Square square11(xCollection[i],yCollection[i],lenCollection[i]);
			expectedPS = testPolyDraw(xCollection[i],yCollection[i],4,lenCollection[i]);
			returnedPS = square11.draw();
			REQUIRE(expectedPS == returnedPS);

		}
	}
}

//Commented out since drawing complex shapes means getting the initializer list
/*TEST_CASE ("Complex Shape Default Construction","[Construction]")
{
	string returnedPS, expectedPS;
	Layered defaultLayered;
	returnedPS = defaultLayered.draw(144,72);
	expectedPS = 

	Horizontal defaultHorizontal;
	Vertical defaultVertical;

}*/

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