/*
 * utils.h
 * 4/4/2016
 * 
 * CS 372 Sp16
 * Group Project 2: Postscript Generator
 */

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
using std::string;
using std::to_string;
#include <sstream>
using std::stringstream;
#include <utility>
using std::pair;
#include <cmath>


//const double PI = 3.14159;

string psLine(int,int);
string psMove(int,int);
string psArc(int,int,double,int,int);
double calcX(int,int,double);
double calcY(int,int,double);
double getWidth(int,double);
double getHeight(int,double);
double getRadius(int,double);

double getConvexX(int k, int n, double r);
double getConvexY(int k, int n, double r);
double getConcaveX(int k, int n, double r);
double getConcaveY(int k, int n, double r);

#endif