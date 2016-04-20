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

*Shape*|
---
#int x_<br>#int y_<br>#double boundsWidth_<br>#double boundsHeight_|
+Shape()<br>+Shape(int x, int y, double width, double height)<br>+Shape(double width,double height)<br>*+virtual ~Shape()*<br>+Shape (const Shape & other)<br>*+virtual string draw() const*<br>*+virtual string draw(int x,int y) const*<br>*+virtual void place(int x, int y)*<br>+string bounds()<br>+double width()<br>+double height()<br>+int x()<br>+void x(int x)<br>+int y()<br>+void y(int y)<br>+string operator()(int x, int y)<br>*+virtual int numOfSides()*<br>*+virtual double sideLength()*<br>*+virtual double radius()*<br>+ostream & operator<<(ostream &os, const Shape & shape)|

Circle |
---
#double radius_ |
+Circle()<br>+Circle(int x, int y, double radius)<br>+Circle(double radius)<br>+string draw(int x, int y) const|

Layered|
---
#initializer_list<Shape*> shapes_|
+Layered()<br>+Layered(int x, int y, initializer_list<Shape*> shapes)<br>+Layered(initializer_list<Shape*> shapes)<br>+string draw(int x, int y) const|

Horizontal|
---
|
+Horizontal()<br>+Horizontal(int x, int y, initializer_list<Shape*> shapes)<br>+Horizontal(initializer_list<Shape*> shapes)<br>+string draw(int x, int y) const|


Vertical|
---
|
+Vertical()<br>+Vertical(int x, int y, initializer_list<Shape*> shapes)<br>+Vertical(initializer_list<Shape*> shapes)<br>+string draw(int x, int y) const|

Polygon|
---
#int numOfSides_<br>#double sideLength_<br>#double radius_|
+Polygon()<br>+Polygon(int x, int y, int sides, double length)<br>+Polygon(int sides, double length)<br>+string draw(int x,int y) const<br>+int numOfSides()<br>+double sideLength()<br>+double radius()|

Square|
---
|
+Square()<br>+Square(int x, int y, double side)<br>+Square(double side)|

Triangle|
---
|
+Triangle()<br>+Triangle(int x, int y, double side)<br>+Triangle(double side)|

Rectangle|
---
#double width_<br>#double height_|
+Rectangle()<br>+Rectangle(int x, int y, double w, double h)<br>+Rectangle(double w, double h)<br>+string draw(int x, int y) const|

Spacer|
---
|
+Spacer()<br>+Spacer(int x, int y, double w, double h) <br>+Spacer(double w, double h) <br>+string draw(int x, int y) const|

Rotated|
---
-Shape * shape_<br>-int angle_|
+Rotated()<br>+Rotated(Shape * shape, int angle)<br>+string draw() const<br>+string draw(int x, int y) const|

Scaled|
---
-Shape * shape_<br>-double sx_<br>-double sy_|
+Scaled()<br>+Scaled(Shape* shape, double sx, double sy)<br>+string draw() const<br>+string draw(int x, int y) const|

