#include <iostream>
using namespace std;

class Shape {
	public:
		// Calculate Function
		int calcArea(){
			return width * height;
		}

		// Set Functions
		void setWidth(int w){
			width = w;
		}
		void setHeight(int h){
			height = h;
		}

		// Get Functions
		int getWidth(){
			return width;
		}
		int getHeight(){
			return height;
		}

	private:
		int width;
		int height;
};

// Triangle Class
class Triangle: public Shape{
	public:
		double calcArea(){
			return getWidth() * getHeight() / 2;
		}
};

// Square Class
class Square: public Shape{
	public:
		double calcArea(){
			return getWidth() * getWidth();
		}
};