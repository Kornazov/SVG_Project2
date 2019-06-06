#ifndef _SERIALIZEVISITOR__H
#define _SERIALIZEVISITOR__H

#include "visitor.h"
#include <iostream>
using namespace std;

class SerializeVisitor : public Visitor {
public:
	SerializeVisitor(string filename);
	void visitLine(fstream&);
	void visitRectangle(fstream&);
	void visitCircle(fstream&);
	void visitGroup(fstream&);
	Group getGroup()const {
		return group;
	}
	void save();
public:
	Group group;
	string filename;
};

#endif
