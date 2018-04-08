#include <iostream>
#include "box.h"
using namespace std;

int main() {
	Box mybox;
	Box yourbox(3, 6, 10);

	int l, w, h;
	cin >> l >> w >> h;

	mybox.setLength(l);
	mybox.setWidth(w);
	mybox.setHeight(h);

	cout << "Dimensions of mybox is (" << mybox.getLength() << ", " << mybox.getWidth() << ", " << mybox.getHeight() << ")" << endl;
	cout << "Area of mybox is " << mybox.calcArea() << endl;
	cout << "Volume of mybox is " << mybox.calcVolume() << endl;
}