/*
 * circle.cpp
 * 4/13/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#include "circle.h"

string Circle::draw(int x, int y){
	return psArc(x,y,radius_,0,360);
}