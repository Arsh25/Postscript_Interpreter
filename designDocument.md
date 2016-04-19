#PostScript Interpreter Design Document

CS 372 Software Construction
Project 2 – PostScript Interpreter

Jason Warta
Arsh Chauhan
Lonny Strunk

Updated: April 19, 2016

##Goal
Produce a C++ library that takes commands to draw certain shapes and outputs code in the PostScript programming language.

##Testing Framework
We are using the [Catch](https://github.com/philsquared/Catch) framework for our testing. This is an easy to use testing framework that only needs one header and one #include.

We are also utilizing [Travis CI](https://travis-ci.org/) to automate the testing. When new code is pushed onto GitHub, Travis CI is called to build the testing code and report any errors.

##Documentation
We are utilizing a documentation generation tool from source code called [Doxygen](http://www.stack.nl/~dimitri/doxygen/). It generates an online documentation browser (HTML) which makes it easy to navigate the source code. It also makes it easy to see the inheritance and dependencies because of the automatic generation of graphs and diagrams.

##Class Hierarchy
![Figure 1: Shape Abstract Class Hierarchy](https://github.com/Arsh25/Postscript_Interpreter/blob/master/html/class_shape.png)
Figure 1: Shape Abstract Class Hierarchy

Shape |
---
int x_
int y_
double boundsWidth_	
double boundsHeight_ |
Shape()
Shape(int x, int y, double width, double height)
Shape(double width,double height)
virtual ~Shape()
Shape (const Shape & other){}
virtual string draw() const
virtual string draw(int x,int y) const
virtual void place(int x, int y)
string bounds()
double width()
double height()
int x()
void x(int x)
int y()
void y(int y)
string operator()(int x, int y)
virtual int numOfSides()
virtual double sideLength()
virtual double radius()
ostream & operator<<(ostream &os, const Shape & shape) |

Circle
double radius_
Circle()
Circle(int x, int y, double radius)
Circle(double radius)
string draw(int x, int y) const

Layered
initializer_list<Shape*> shapes_
Layered()
Layered(int x, int y, initializer_list<Shape*> shapes)
Layered(initializer_list<Shape*> shapes)
string draw(int x, int y) const

Horizontal

Horizontal()
Horizontal(int x, int y, initializer_list<Shape*> shapes)
Horizontal(initializer_list<Shape*> shapes)
string draw(int x, int y) const


Vertical

Vertical()
Vertical(int x, int y, initializer_list<Shape*> shapes)
Vertical(initializer_list<Shape*> shapes)
string draw(int x, int y) const

Polygon
int numOfSides_
double sideLength_
double radius_
Polygon()
Polygon(int x, int y, int sides, double length)
Polygon(int sides, double length)
string draw(int x,int y) const
int numOfSides()
double sideLength()
double radius()

Square

Square()
Square(int x, int y, double side)
Square(double side) 

Triangle

Triangle() : Polygon(0,0,3,0)
Triangle(int x, int y, double side)
Triangle(double side)

Rectangle
double width_
double height_
Rectangle()
Rectangle(int x, int y, double w, double h)
Rectangle(double w, double h)
string draw(int x, int y) const

Spacer

Spacer()
Spacer(int x, int y, double w, double h) 
Spacer(double w, double h) 
string draw(int x, int y) const;

Rotated
Shape * shape_
int angle_
Rotated()
Rotated(Shape * shape, int angle)
string draw() const
string draw(int x, int y) const

Scaled
Shape * shape_
double sx_
double sy_
Scaled()
Scaled(Shape* shape, double sx, double sy) 
string draw() const;
string draw(int x, int y) const;

