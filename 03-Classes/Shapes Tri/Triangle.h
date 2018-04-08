#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

class Triangle: public Shape {
	public:
		double calculateArea();
		void draw();
		double getHeight();
		double getWidth();
		void setHeight(double h);
		void setWidth(double w);
		Triangle();
		Triangle(string n, double w, double h);

	private:
		double height;
		double width;
};

#endif