#include <iostream>
#include "stack.h"
using namespace std;

int main(){
	Stack<string> stack;
	int option;
	string input;

	while(true){
		cout << "Options:" << endl << "[1] Push" << endl << "[2] Pop" << endl << "[3] Print" << endl << "[4] Count" << endl << "[5] Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				cout << "Insert String: ";
				cin >> input;
				stack.push(input);
				break;
			case 2:
				stack.pop();
				break;
			case 3:
				stack.print();
				break;
			case 4:
				stack.isEmpty();
				stack.count();
				break;
			case 5:
				return 0;
		}
	}

	return 0;
}