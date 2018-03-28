#include <string>
#include "Shape.h"

using namespace std;

// double Shape::calculateArea() {
// 	return height * width;
// }
// void Shape::draw() {
// 	//Do something
// }
string Shape::getName(){
	return name;
}
void Shape::setName(string n){
	this->name = n;
}
Shape::Shape(){
	this->name = "shape";
}
Shape::Shape(string n){
	this->name = n;
}