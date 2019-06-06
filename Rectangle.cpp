#include "stdafx.h"
#include "Rectangle.h"
#include "Visitor.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void Rectangle::close(ostream& out) {
	out << "<rect x"<<"=\""<<x<<"\" " << "y=\"" <<y<< "\" "<<"w=\""<<w << "\" "<<"h=\""<< h <<"\" "<<"text=\"" << text<<"\" "<<"/>"<< endl;
}
 void Rectangle:: open (istream& in) {
	 string value = read(in);
	 cout << value << endl;
	 if (value[0] >= '0' && value[0] <= '9') x = atoi(value.c_str());
	 value = read(in);
	 cout << value << endl;
	 if (value[0] >= '0' && value[0] <= '9') y = atoi(value.c_str());
	 value = read(in);
	 cout << value << endl;
	 if (value[0] >= '0' && value[0] <= '9') w = atoi(value.c_str());
	 value = read(in);
	 cout << value << endl;
	 if (value[0] >= '0' && value[0] <= '9') h = atoi(value.c_str());
	 string text = read(in);
	 cout << text << endl;
	 int length = text.length() + 1;
	 this->text = new char[length];
	 strcpy_s(this->text,length,text.c_str());
	 
}
void Rectangle::print()const {

	cout<<"Rectangle"<<" "<< x << " " << y << " " << w << " " << h <<" "<<getText()<< endl;
}
Rectangle::Rectangle(int _x, int _y, int _w, int _h, const char *_s) :Shape(_x, _y, _s), w(_w), h(_h) {

}

void Rectangle::setWidth(int _w) {
	this->w = _w;
}

void Rectangle::setHeight(int _h) {
	this->h = _h;
}

int Rectangle::getWidth() const {
	return this->w;
}
int Rectangle::getHeight() const {
	return  this->h;
}


Shape *Rectangle::clone() {
	return new Rectangle(*this);
}


