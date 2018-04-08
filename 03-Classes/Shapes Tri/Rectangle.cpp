#include <string>
#include "Rectangle.h"

using namespace std;

double Rectangle::calculateArea(){
	return this->width * this->length;
}
void Rectangle::draw(){
	for(int i = 1; i <= (int)getLength(); i++){
		for(int j = 1; j <= (int)getWidth(); j++){
			cout << "*";
		}
		cout << endl;
	}
}
double Rectangle::getLength(){
	return this->length;
}

double Rectangle::getWidth(){
	return this->width;
}

void Rectangle::setLength(double l){
	this->length = l;
}

void Rectangle::setWidth(double w){
	this->width = w;
}

Rectangle::Rectangle(){
	this->name = "rectangle";
	this->width = 1;
	this->length = 1;
}

Rectangle::Rectangle(string n, double w, double l){
	this->name = n;
	this->width = w;
	this->length = l;
}