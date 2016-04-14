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

#include <sstream>
using std::stringstream;


/**
 * @brief turns a variable into a string
 * @details uses stringstream with an insertion operator to convert the variable to a string
 * 
 * @param var value by reference
 * @return string version of variable
 */
template<typename T>
string stringify(const T& var){
	stringstream ss;
	ss << var;
	return ss.str();
};

string psLine(int,int,int,int);
string psArc(int,int,int,int,int);


#endif