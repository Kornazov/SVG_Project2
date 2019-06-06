#include "stdafx.h"
#ifndef __CIRCLE_H
#define __CIRCLE_H
#include<iostream>
using namespace std;
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int _x=0, int _y=0, int _r=0, const char *_s="");
	Shape* clone();
	virtual void close(ostream& out);
	virtual void print()const;
	virtual void open(istream& in);
	void setRadius(int _r);

	int getRadius() const;

private:
	int r;
};

#endif

