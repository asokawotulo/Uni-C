#include <iostream>
#include "simpleLL.h"
using namespace std;

int main(){
	simpleLL<int> list;

	list.insert(1);
	list.insert(2);
	list.insert(3);

	list.print();
	cout << list.search(3);

	list.destroy();

	return 0;
}