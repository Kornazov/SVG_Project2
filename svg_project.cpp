// svg_project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Group.h"
#include "SerializeVisitor.h"
#include<iostream>
using namespace std;


int main()
{
	string option;
	SerializeVisitor* current = nullptr;
	while (true) {
		cin >> option;

		if (option == "open") {
			cin >> option;
			if(current==nullptr)current = new SerializeVisitor(option);
		}
		else if (option == "save") {
			if (current) {
				current->save();
			}
		}
		else if (option == "exit") {
			cout<< "exit";
			return 0;
		}
		else if (option == "print") {
			if (current) {
				current->getGroup().print();
			}
		}
		else if (option == "create") {
			string figure;
			cin >> figure;
			if (figure == "Rect") {
				Rectangle rect(1000, 100, 2, 3, "yellow");
				current->group.addShape(rect);
			}
			
		}

	}








	return 0;
}

