#include "stdafx.h"
#include "Shape.h"
#include<iostream>
using namespace std;
#pragma once
class Line: public Shape
{
public:
	Line(int x=0, int y=0,int x1=0,int y1=0, const char* text=" ");

	Shape* clone();
	virtual void close(ostream& out);
	virtual void open(istream& in);

	virtual void print()const;
	void setX1(int x1);
	void setY1(int y1);
	int getX1() const;
	int getY1() const;
protected:
	int x1;
	int y1;
};

