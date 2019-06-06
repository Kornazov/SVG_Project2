#include "stdafx.h"
#include "Circle.h"
#include "visitor.h"
#include <iostream>
#include<string>
using namespace std;

void Circle::open(istream& in) {
	//cx="5" cy = "51" r = "10" fill = "blue"
	string value = read(in);
	if (value[0]>='0' && value[0]<='9') x = atoi(value.c_str());
	value = read(in);
	if (value[0] >= '0' && value[0] <= '9') y= atoi(value.c_str());
	value = read(in);
	if (value[0] >= '0' && value[0] <= '9') r = atoi(value.c_str());
	string text = read(in);
	setText(text.c_str());
	
}
void Circle::close(ostream& out) {

	out << "<circle x" << "=\"" << x << "\" " << "y=\"" << y << "\" " << "r=\"" << r << "\" "<< "text=\"" << text << "\" " << "/>" << endl;

}
Circle::Circle(int _x, int _y, int _r, const char *_s) :Shape(_x, _y, _s), r(_r) {

}
void Circle::print() const {
	cout << "Circle "<< " " << x << " " << y << " "<<r<<" "<< getText()<< endl;
}

void Circle::setRadius(int r) {
	this->r = r;
}

int Circle::getRadius() const {
	return this->r;
}

Shape* Circle::clone() {
	return new Circle(*this);
}
	