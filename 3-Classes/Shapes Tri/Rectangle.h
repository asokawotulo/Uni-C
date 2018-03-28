#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle: public Shape {
	public:
		double calculateArea();
		void draw();
		double getLength();
		double getWidth();
		void setLength(double l);
		void setWidth(double w);
		Rectangle();
		Rectangle(string n, double w, double l);

	private:
		double length;
		double width;
};

#endif