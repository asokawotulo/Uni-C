#include <iostream>
#include <string>
using namespace std;

template <class temp>
temp Larger{
	temp a, b;
	public:
		isLarger(temp a, temp b){
			return (a>b?a:b);
		}
}

int main(){
	string input_1, input_2;

	cout << "First Input: ";
	cin >> input_1;

	cout << "Second Input: ";
	cin >> input_2;

	cout << isLarger(input_1, input_2) << " is larger" << endl;
	return 0;
}