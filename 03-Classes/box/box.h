#include <iostream>
using namespace std;

class Box {
	public:
		// Get Functions
		int getLength();
		int getWidth();
		int getHeight();
		// Set Functions
		void setLength(int l);
		void setWidth(int w);
		void setHeight(int h);
		// Calculate Functions
		int calcArea();
		int calcVolume();
		// Call
		Box();
		Box(int, int, int);
		// ~Box();
	private:
		int length;
		int width;
		int height;
};
// Get Functions
int Box::getLength(){
	return length;
}
int Box::getWidth(){
	return width;
}
int Box::getHeight(){
	return height;
}
// Set Functions
void Box::setLength(int l){
	length = l;
}
void Box::setWidth(int w){
	width = w;
}
void Box::setHeight(int h){
	height = h;
}
// Set Functions
int Box::calcArea(){
	return 2*(width*height + width*length + height*length);
}
int Box::calcVolume(){
	return length * width * height;
}
// Call
Box::Box(){
	length = 1;
	width = 1;
	height = 1;
}
Box::Box(int l, int w, int h){
	length = l;
	width = w;
	height = h;
}