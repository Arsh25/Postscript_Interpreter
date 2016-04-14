#include "scaled.h"

string Scaled::draw(int x, int y){
	
	stringstream ss;
	ss << "gsave\n";
	ss << sx_ << " " << sy_ << " scale\n";
	ss << shape_.draw(x,y);
	ss << "grestore\n";

	return ss.str();
}