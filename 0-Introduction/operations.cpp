#include <iostream>
using namespace std;

int main(){
	char oper;
	int a, b;
	cout << "Insert Operation (+,-,*,/): ";
	cin >> oper;

	cout << "Insert First Number: ";
	cin >> a;
	cout << "Insert Second Number: ";
	cin >> b;

	switch(oper) {
		case '+' :
			cout << a + b << endl;
			break;
		case '-' :
			cout << a - b << endl;
			break;
		case '*' :
			cout << a * b << endl;
			break;
		case '/' :
			cout << a / b << endl;
			break;
	}
	return 0;
}