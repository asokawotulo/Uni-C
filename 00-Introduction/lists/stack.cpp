#include <iostream>
using namespace std;


int main(){
	int size = 100;
	int arr[size];
	int option, number;
	int index = 0;
	cout << "[1] Push" << endl << "[2] Pop" << endl << "[3] Show number of entries" << endl << "[4] Show all entries" << endl << "[5] End Program" << endl;
	cout << "Selected option: ";
	cin >> option;
	while(option != 5){
		if(option == 1){
			number = 0;
			cout << "Number to input: ";
			cin >> number;
			arr[index] = number;
			cout << number << " is placed into the array with the index " << index << endl;
			index++;
		}
		else if(option == 2){
			number = arr[index - 1];
			cout << number << " is taken out of the array" << endl;
			index--;
		}
		else if(option == 3){
			cout << "You have " << index << " entries" << endl;
		}
		else if(option == 4){
			for(int i = 0; i < index; i++){
				cout << i << ". " << arr[i] << endl;
			}
		}
		cout << "[1] Push" << endl << "[2] Pop" << endl << "[3] Show number of entries" << endl << "[4] Show all entries" << endl << "[5] End Program" << endl;
		cout << "Selected option: ";
		cin >> option;
	}
	cout << "Bye" << endl;
	return 0;
}