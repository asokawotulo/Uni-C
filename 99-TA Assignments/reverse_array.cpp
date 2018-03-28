#include <iostream>
using namespace std;

int main(){
	// Initialize size
	int size;
	cout << "Insert size of array: ";
	cin >> size;

	//Initialize array
	int arr[size];
	for(int i = 0; i < size; i++){
		cout << "Insert number " << i + 1 << ": ";
		cin >> arr[i];
	}

	//Reverse array
	for(int j = size - 1; j >= 0; j--){
		cout << arr[j] << " ";
	}
	cout << endl;
}