#include <iostream>
#include "class.h"
using namespace std;

int main(){
	Triangle t;
	Square s;

	t.setWidth(5);
	t.setHeight(8);

	s.setWidth(5);

	cout << "Triangle area: " << t.calcArea() << endl;
	cout << "Square area: " << s.calcArea() << endl;

	return 0;
}