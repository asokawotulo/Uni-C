#include <string>
#include <cmath>
#include "Circle.h"

using namespace std;

double Circle::calculateArea(){
	return pow(3.14, 2) * this->radius;
}
void Circle::draw(){
	for(int i = 1; i <= (int)getRadius(); i++){
		for(int j = (int)getRadius() - 1; j >= i; j--){
			cout << " ";
		}
		for(int k = 1; k <= i*2-1; k++){
			cout << "*";
		}
		cout << endl;
	}
	for(int i = 1; i <= (int)getRadius() - 1; i++){
		for(int j = 1; j <= i; j++){
			cout << " ";
		}
		for(int k = (int)getRadius()*2-1; k >= i*2+1; k--){
			cout << "*";
		}
		cout << endl;
	}
}
double Circle::getRadius(){
	return this->radius;
}
void Circle::setRadius(double r){
	this->radius = r;
}
Circle::Circle(){
	this->name = "circle";
	this->radius = 1;
}
Circle::Circle(string n, double r){
	this->name = n;
	this->radius = r;
}