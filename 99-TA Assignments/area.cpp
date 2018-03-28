#include <iostream>
using namespace std;

int areaSquare(int length, int width){
	return length * width;
}
float areaTriangle(int length, int width){
	return length * width / 2.0;
}

int main(){
	//Initialize variables
	int length, width, shape;
	//Input length
	cout << "Enter length (cm): ";
	cin >> length;
	//Input width
	cout << "Enter width (cm): ";
	cin >> width;
	//Input shape
	cout << "[1] Square" << endl << "[2] Triangle" << endl << "Enter shape index: ";
	cin >> shape;

	switch(shape){
		case 1:
			cout << "Area of a square: " << areaSquare(length, width) << "cm^2" << endl;
			break;
		case 2:
			cout << "Area of a triangle: " << areaTriangle(length, width) << "cm^2" << endl;
			break;
	}
}