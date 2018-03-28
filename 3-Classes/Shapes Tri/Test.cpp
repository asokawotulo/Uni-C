#include <iostream>
#include <string>
#include "Shape.cpp"
#include "Circle.cpp"
#include "Triangle.cpp"
#include "Rectangle.cpp"

using namespace std;

int menu(){
	int chosen;
	cout << "Options:" << endl << "[1] Triangle" << endl << "[2] Circle" << endl << "[3] Rectangle" << endl << "[4] End Program" << endl << "Insert option ID: ";
	cin >> chosen;
	return chosen;
}

int main(){
	// Initialize Variables
	double length, width, height, radius;
	string name;

	int option = menu();

	while (option != 4){
		if(option == 1){
			cout << "Insert width: ";
			cin >> width;
			cout << "Insert height: ";
			cin >> height;
			cout << "Insert name: ";
			cin >> name;
			Triangle myTriangle(name, width, height);
			cout << "Drawing of " << myTriangle.getName() << endl;
			myTriangle.draw();
			cout << "Area of " << myTriangle.getName() << ": " << myTriangle.calculateArea() << endl;
		}
		else if(option == 2){
			cout << "Insert radius: ";
			cin >> radius;
			cout << "Insert name: ";
			cin >> name;
			Circle myCircle(name, radius);
			cout << "Drawing of " << myCircle.getName() << endl;
			myCircle.draw();
			cout << "Area of " << myCircle.getName() << ": " << myCircle.calculateArea() << endl;
		}
		else if(option == 3){
			cout << "Insert width: ";
			cin >> width;
			cout << "Insert length: ";
			cin >> length;
			cout << "Insert name: ";
			cin >> name;
			Rectangle myRectangle(name, width, length);
			cout << "Drawing of " << myRectangle.getName() << endl;
			myRectangle.draw();
			cout << "Area of " << myRectangle.getName() << ": " << myRectangle.calculateArea() << endl;
		}
		option = menu();
	}
	cout << "Byee" << endl;
	return 0;
}