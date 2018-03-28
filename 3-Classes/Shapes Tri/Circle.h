#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

class Circle: public Shape {
	public:
		double calculateArea();
		void draw();
		double getRadius();
		void setRadius(double r);
		Circle();
		Circle(string n, double r);
	private:
		double radius;
};

#endif