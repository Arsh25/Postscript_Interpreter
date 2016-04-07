/*
 * spacer.h
 * 4/4/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef SPACER_H_INCLUDED
#define SPACER_H_INCLUDED

class Spacer : public Rectangle
{
public:
	Spacer(): Rectangle() {};
	Spacer(double w, double h): Rectangle(w,h) {};
	Spacer(int x, int y, double w, double h): Rectangle(x,y,w,h) {};
	Spacer(pair<int,int> center, double w, double h): Rectangle(center,w,h) {};

private:


};



#endif