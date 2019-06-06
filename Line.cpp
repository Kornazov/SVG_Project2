#include "stdafx.h"
#include "Line.h"
#include "Shape.h"
#include "Visitor.h"
#include<iostream>
using namespace std;
void Line::open(istream& in) {
	string value = read(in);
	if (value[0] >= '0' && value[0] <= '9') x = atoi(value.c_str());
	value = read(in);
	if (value[0] >= '0' && value[0] <= '9') y = atoi(value.c_str());
	value = read(in);
	if (value[0] >= '0' && value[0] <= '9') x1 = atoi(value.c_str());
	value = read(in);
	if (value[0] >= '0' && value[0] <= '9') y1 = atoi(value.c_str());
	string text = read(in);
	setText(text.c_str());
}
void Line::close(ostream& out) {
	out << "<line x" << "=\"" << x << "\" " << "y=\"" << y << "\" " << "x1=\"" << x1 << "\" " << "y1=\"" << y1 << "\" " << "text=\"" << text << "\" " << "/>" << endl;
}
void Line::setX1(int x1) {
	this->x1 = x1;
}

void Line::setY1(int y1) {
	this->y1 = y1;
}
int Line:: getX1() const {
	return x1;
}
int Line::getY1() const {
	return y1;
}
Line::Line(int x,int y,int x1,int y1,const char* text):Shape(x,y,text)
{
	this->x1 = x1;
	this->y1 = y1;
}
void Line::print()const {
	cout << "Line  "<< " " << x << " " << y <<" "<<x1<<" "<<y1<<" "<< getText() <<  endl;
}
Shape* Line::clone() {

	return new Line(*this);
}

