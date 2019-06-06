#include "stdafx.h"
#include "Shape.h"
#include <cstring>
#include <iostream>
using namespace std;
string Shape::read(istream& in) {
	string buffer;
	in >> buffer;
	int index = buffer.find("=\"");
	string value;
	for (int i = index + 2; i < buffer.length()-1; i++) {
		value += buffer[i];
	}
	return value;
 }
void Shape::setX(int _x) {
	this->x = _x;
}
void Shape::setY(int _y) {
	this->y = _y;
}
void Shape::setText(const char *s) {
	if (text != nullptr) {
		delete text;
	}
	text = new char[strlen(s) + 1];
	strcpy_s(text,strlen(s)+1, s);
}
void Shape::translateWith(int newValueX,int newValueY) {
	x = x + newValueX;
	y = y + newValueY;
}
int Shape::getX()const {
	return this->x;
}
int Shape::getY()const {
	return this->y;
}
const char* Shape::getText() const {
	return text;
}

Shape::Shape() :x(0), y(0), text(nullptr) {

}
Shape::Shape(int _x, int _y, const char *s) {
	setX(_x);
	setY(_y);
	text = nullptr;
	setText(s);
}

Shape::~Shape() {
	delete text;
}

Shape::Shape(const Shape &s) :x(s.x), y(s.y), text(nullptr) {
	setText(s.text);
}

void Shape::operator=(const Shape &s) {
	if (this != &s) {
		setText(s.text);
	}
}
