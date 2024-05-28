#include <iostream>
#include <vector>

int linearSearch(std::vector<int> vec, int val){
	for(int i=0; i<vec.size(); i++){
		if(vec.at(i) == val){
			std::cout << "Index was found at index: " << i << std::endl;
			return 1;
		}
	}
	std::cout << "Value was not found." << std::endl;
	return -1;
}
int binarySearch(std::vector<int> vec, int first, int last, int val) {
	if(last >= 1){
		int mid = (first + last)/2;
		if(vec.at(mid) == val) {
			return mid;
		} if(vec.at(mid) < val){
			return binarySearch(vec, mid+1, last, val);
		} else {
			return binarySearch(vec, first, mid-1, val);
		}
	}
	return -1;
}
int interpolateSearch(std::vector<int> vec, int val) {
	int first = 0;
	int last = vec.size()-1;
	int mid;
	while(first <= last){
		mid = first + ((val - vec.at(first))*(last-first)/(vec.at(last)-vec.at(first)));
		if(vec.at(mid) == val){
			std::cout << "Index was found at index: " << mid << std::endl;
			return 1;
		} else if(vec.at(mid) < val) {
			first = mid + 1;
		} else {
			last = mid - 1;
		}
	}
	std::cout << "Value was not found." << std::endl;
	return -1;
}

int main(){
	std::vector<int> myVector;

	myVector.push_back(3);
	myVector.push_back(9);
	myVector.push_back(6);
	myVector.push_back(2);
	myVector.push_back(7);

	std::sort(myVector.begin(), myVector.end());

	linearSearch(myVector, 7);
	int val = binarySearch(myVector, 0, myVector.size()-1, 7);
	(val != -1)?(std::cout << "Index was found at index: " << val << std::endl):(std::cout << "Value was not found." << std::endl);
	interpolateSearch(myVector, 7);

	return 0;
}