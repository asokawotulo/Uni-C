#include <iostream>
using namespace std;

void makeTriangle(int amount){
	for(int i = 1; i <= amount; i++){
		for(int j = amount; j >= i; j--){
			cout << " ";
		}
		for(int k = 1; k <= i*2-1; k++){
			cout << "*";
		}
		cout << endl;
	}
}

void makeRightTriangle(int amount){
	for(int i = 1; i <= amount; i++){
		for(int j = 1; j <= i; j++){
			cout << "*";
		}
		cout << endl;
	}
}
void makeSquare(int amount){
	for(int i = 1; i <= amount; i++){
		for(int j = 1; j <= amount; j++){
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	int lines, shapeIndex;
	cout << "[1] Triangle" << endl << "[2] Right Triangle" << endl << "[3] Square" << endl;
	cin >> shapeIndex;
	cout << "Input number of lines: ";
	cin >> lines;
	switch(shapeIndex){
		case 1:
			makeTriangle(lines);
			break;
		case 2:
			makeRightTriangle(lines);
			break;
		case 3:
			makeSquare(lines);
			break;
	}
}