#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> seperateComma(string str){
	stringstream ss(str);
    vector<int> arr;
    char comma;
    int n;
    while(ss >> n) {
        arr.push_back(n);
        ss >> comma;
    }
    return arr;
}

int main(){
	string str;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cin >> str;
	vector<int> integers = seperateComma(str);

	for(int b = 0; b < integers.size(); b++){
		arr[integers[b]-1] = 0;
	}

	for(int c = 0; c < 10; c++){
		if(arr[c] != 0){
			cout << arr[c] << " ";
		}
	}

	return 0;
}