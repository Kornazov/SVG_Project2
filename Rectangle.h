#include "stdafx.h"
#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include<iostream>
using namespace std;
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int _x=0, int _y=0, int _w=0, int _h=0, const char *_s=" ");
	Shape* clone();
	virtual void close(ostream& out);
	virtual void print()const;
	virtual void open(istream& in);
	void setWidth(int _w);
	void setHeight(int _h);
	int getWidth() const;
	int getHeight() const;


private:
	int w;
	int h;
};

#endif