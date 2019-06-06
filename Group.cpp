#include "stdafx.h"
#include "Group.h"
#include "visitor.h"
#include <typeinfo>
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

Group::Group() {}

void Group::within(Shape* c) {
	Rectangle *d = dynamic_cast<Rectangle*>(c);
	if (d != nullptr) {
		for (auto& child : children) {
			Rectangle *rectangle = dynamic_cast<Rectangle*>(child);
			if (rectangle != nullptr) {
				int a = rectangle->getX() + rectangle->getWidth();
				int z = rectangle->getY() + rectangle->getHeight();
				if (d->getX() < a && d->getHeight() > z) {
					child->print();
				}
			}

			Line *line = dynamic_cast<Line*>(child);
			if (line != nullptr) {
				if ((d->getX() < line->getX() && d->getY() < line->getY())
					&& (d->getWidth() > line->getX1()) && d->getHeight() > line->getY1()) {
					child->print();
				}
			}

			Circle *circle = dynamic_cast<Circle*>(child);
			if (circle != nullptr) {
				if ((d->getX() < circle->getX() && d->getY() < circle->getY())
					&& (d->getHeight() + d->getY() > circle->getY() + circle->getRadius()) && (d->getY() < circle->getY() - circle->getRadius())
					&& (d->getWidth() + d->getX() > circle->getX() + circle->getRadius()) && (d->getX() < circle->getX() - circle->getRadius())) {
					child->print();
				}
			}
		}
	}

	Circle *newCircle = dynamic_cast<Circle*>(c);
	if (newCircle != nullptr) {
		for (auto& child : children) {
			Rectangle *rectangle = dynamic_cast<Rectangle*>(child);
			if (rectangle != nullptr) {

				int secondPointX = rectangle->getX() + rectangle->getWidth();
				int secondPointY = rectangle->getY() + rectangle->getWidth();
				int thirdPointX = rectangle->getX() + rectangle->getHeight();
				int thirdPointY = rectangle->getY() + rectangle->getHeight();
				int fourthPointX = thirdPointX + rectangle->getWidth();
				int fourthPointY = thirdPointY + rectangle->getWidth();
				double firstPointX = rectangle->getX()*rectangle->getX();
				double firstPointY = rectangle->getY()*rectangle->getY();
				double radius = newCircle->getRadius()*newCircle->getRadius();
				if ((secondPointX*secondPointX + secondPointY*secondPointY <= radius) &&
					(thirdPointX*thirdPointX + thirdPointY*thirdPointY <= radius) &&
					(fourthPointX*fourthPointX + fourthPointY*fourthPointY <= radius) &&
					firstPointX + firstPointY <= radius) {
					child->print();
				}
			}

			Line *line = dynamic_cast<Line*>(child);
			if (line != nullptr) {
				if (line->getX() < newCircle->getX() + newCircle->getRadius()
					&& line->getY() < newCircle->getY() + newCircle->getRadius()) {
					child->print();
				}
			}

			Circle *circle = dynamic_cast<Circle*>(child);
			if (circle != nullptr) {
				if (circle->getX() < newCircle->getX() + newCircle->getRadius()
					&& circle->getY() < newCircle->getY() + newCircle->getRadius()) {
					child->print();
				}
			}
		}
	}
}
void Group::save(fstream& out) {
	out << "<svg>" << endl;
	for (auto& child : children) {
		child->close(out);
	}
	out << "</svg>";
}
void Group::translate(int translateX,int translateY ) {
	for (auto& child : children) {
		child->translateWith(translateX,translateY);
	}
}
void Group::print()const {
	for (auto& child : children) {
		child->print();
	}
}
void Group::addShape(Shape& shape) {
	children.push_back(shape.clone());
}

void Group::erase(int index) {
	cout << "Deleted" << endl;
	children[index]->print();
	children.erase(children.begin() + index);
}
Group::~Group() {
	for (Shape *shape : children) {
		delete shape;
	}
}


Group& Group::operator=(const Group &g) {
	if (this != &g) {
		for (Shape *s : children) {
			delete s;
		}
		children.clear();
		for (Shape *s : g.children) {
			children.push_back(s->clone());
		}
	}
	return *this;
}

Group::Group(const Group &g)
{
	for (Shape *s : g.children) {
		children.push_back(s->clone());
	}
}

size_t Group::get_nChildren() const {
	return children.size();
}

Shape *Group::getChild(size_t i) const {
	return children[i];
}

