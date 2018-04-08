#include <iostream>
using namespace std;

class Shape {
	public:
		// Calculate Function
		int calcArea();

		// Set Functions
		void setWidth(int w);
		void setHeight(int h);

		// Get Functions
		int getWidth();
		int getHeight();

	private:
		int width;
		int height;
};
int Shape::calcArea(){
	return width * height;
}
void Shape::setWidth(int w){
	width = w;
}
void Shape::setHeight(int h){
	height = h;
}
int Shape::getWidth(){
	return width;
}
int Shape::getHeight(){
	return height;
}

// Triangle Class
class Triangle: public Shape{
	public:
		double calcArea();
};
double Triangle::calcArea(){
	return getWidth() * getHeight() / 2;
}

// Square Class
class Square: public Shape{
	public:
		double calcArea();
};
double Square::calcArea(){
	return getWidth() * getWidth();
}