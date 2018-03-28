// #include <iostream>
// using namespace std;

// int main(){
// 	int grade;
// 	cout << "Please Insert your grade: ";
// 	cin >> grade;
// 	// 0-50 D
// 	// 51-75 C
// 	// 76-90 B
// 	// 91-100 A
// 	if(grade <= 50) {
// 		cout << "You have a D... You're a fucking disgrace." << endl;
// 	}
// 	else if (grade >= 51 && grade <= 75) {
// 		cout << "You have a C... You fucking piece of shit." << endl;
// 	}
// 	else if (grade >= 76 && grade <= 90) {
// 		cout << "You have a B... Guess you're not that shit." << endl;
// 	}
// 	else if (grade >= 91 && grade <= 100) {
// 		cout << "You have a A... Nice job. Dick." << endl;
// 	}
// }

#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect;
  rect.set_values (3,4);
  cout << "area: " << rect.area();
  return 0;
}