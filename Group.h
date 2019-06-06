#pragma once
#ifndef __GROUP_H
#define __GROUP_H
#include<iostream>
using namespace std;
#include "Shape.h"
#include <vector>

class Group {
public:
	Group();
	Group(const Group&);
	void accept(Visitor*);
	void addShape(Shape&);
	void erase(int);
	void within(Shape*);
	void translate(int,int);
	Group& operator =(const Group &g);
	void print() const;
	size_t get_nChildren() const;
	Shape* getChild(size_t i) const;
	void save(fstream&);

	~Group();

private:
	std::vector<Shape*> children;
};

#endif  
