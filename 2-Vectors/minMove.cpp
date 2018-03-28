#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void difference(vector<int> nums){
	int count = 0;
	int avg = 0;
	avg = accumulate(nums.begin(), nums.end(), 0)/nums.size();
	for(int i = 0; i < nums.size(); i++){
		if(nums.at(i) < avg){
			count += avg - nums.at(i);
		}
	}
	cout << "Minimum moves: " << count << endl;
}

int main(){
	int nOfData = 0;
	int number = 0;
	vector<int> nums;
	cout << "Number of data: ";
	cin >> nOfData;
	for (int i = 0; i < nOfData; i++){
		cout << "Number " << i+1 << ": ";
		cin >> number;
		nums.push_back(number);
	}
	difference(nums);
	return 0;
}