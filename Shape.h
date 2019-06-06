#include "stdafx.h"
#ifndef __SHAPE_H
#define __SHAPE_H
#include<iostream>
#include<string>
using namespace std;
class Visitor;

class Shape
{
public:

	Shape();
	Shape(int, int, const char*);
	Shape(const Shape&);
	string  read(istream& in);
	virtual void close(ostream& out) = 0;
	virtual void print() const = 0;
	virtual void open(istream &in) = 0;
	
	virtual Shape* clone() = 0;
	void setX(int);
	void setY(int);
	void setText(const char*);
	void translateWith(int, int);
	void operator = (const Shape& s);
	int getX()const;
	int getY()const;
	const char* getText() const;
	virtual ~Shape();
protected:

	int x;
	int y;
	char *text;

};

#endif