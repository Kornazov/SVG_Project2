#include "stdafx.h"
#ifndef _VISITOR__H
#define _VISITOR__H

#include "Rectangle.h"
#include "Circle.h"
#include "Group.h"
#include "Line.h"
class Visitor
{
public:
	virtual void visitRectangle(fstream& in) = 0;
	virtual void visitCircle(fstream& in) = 0;
	virtual void visitGroup(fstream& in) = 0;
	virtual void visitLine(fstream& in) = 0;
};

#endif