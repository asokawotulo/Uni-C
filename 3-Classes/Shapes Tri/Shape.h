#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
	public:
		// double calculateArea();
		// void draw();
		string getName();
		void setName(string n);
		Shape();
		Shape(string n);
	protected:
		string name;
};

#endif