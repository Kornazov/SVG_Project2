#include "stdafx.h"
#include "Serializevisitor.h"
#include <iomanip>
#include<string>
#include<fstream>

SerializeVisitor::SerializeVisitor(string filename) {
	fstream in;
	in.open(filename, std::fstream::in | std::fstream::out);

	this->filename = filename;
	string buffer;
	while (buffer != "<svg>") {

		in >> buffer; }
	visitGroup(in);
	in.close();
};

void SerializeVisitor::save() {

	fstream out(this->filename, std::fstream::in | std::fstream::out| fstream::trunc);
	string buffer = "<?xml version=\"1.0\" standalone=\"no\"?>\n <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	out << buffer;
	group.save(out);
	out.close();
}
void SerializeVisitor::visitLine(fstream& in) {
	Line myLine;
	myLine.open(in);
	this->group.addShape(myLine);
	}
void SerializeVisitor::visitRectangle(fstream& in)
{
	Rectangle myrect;
	
	myrect.open(in);
	cout << "rect is created!" << endl;
	this->group.addShape(myrect);
	
}

void SerializeVisitor::visitCircle(fstream& in)
{
	Circle mycircle;
	mycircle.open(in);
	this->group.addShape(mycircle);

}
void SerializeVisitor::visitGroup(fstream& in)
{
	string buffer;
	while(buffer!="</svg>")
	{  
		in >> buffer;
		cout << buffer << endl;
		if (buffer == "<rect") {
			cout << "visiting rectanble" << endl;
			visitRectangle(in);
		}
		else if (buffer == "<circle") {
			cout << "visiting circle" << endl;

			visitCircle(in);
		}
		else if (buffer == "<line") {
			cout << "visiting line" << endl;

			visitLine(in);
		}
	}
}
