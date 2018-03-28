#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int size = 10;
	int n[size];

	for(int i = 0; i < size; i++){
		n[i] = i + 100;
	}
	cout << setw(7) << "Element" << setw(13) << "Value" << endl;

	for(int j = 0; j < size; j++){
		cout << setw(7) << j << setw(13) << n[j] << endl;
	}
	return 0;
}