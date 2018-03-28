#include <string>
#include "Triangle.h"

using namespace std;

double Triangle::calculateArea(){
	return this->width * this->height / 2;
}
void Triangle::draw(){
	for(int i = 1; i <= (int)getHeight(); i++){
		for(int j = 1; j <= i; j++){
			cout << "*";
		}
		cout << endl;
	}
}
double Triangle::getHeight(){
	return this->height;
}

double Triangle::getWidth(){
	return this->width;
}

void Triangle::setHeight(double h){
	this->height = h;
}

void Triangle::setWidth(double w){
	this->width = w;
}

Triangle::Triangle(){
	this->name = "triangle";
	this->width = 1;
	this->height = 1;
}

Triangle::Triangle(string n, double w, double h){
	this->name = n;
	this->width = w;
	this->height = h;
}