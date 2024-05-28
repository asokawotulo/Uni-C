#include <iostream>
#include "classes/queue.h"
#include <string>
using namespace std;

int palindrome(string input){
	Queue<char> myqueue;
	for(int i=0; i<input.size(); i++){
		myqueue.enqueue(input.at(i));
	}
	for(int i=input.size()-1; i>0; i--){
		if(myqueue.front()!=input.at(i)){
			cout << "Not a palindrome" << endl;
			return 0;
		}
		myqueue.dequeue();
	}
	cout << "Palindrome" << endl;
	return 1;
}

void convertCase(string &str){
	for(int i=0; i<str.size(); i++){
		if(isupper(str.at(i))) str.at(i)=tolower(str.at(i));
	}
}

int main(){
	string input;
	cout << "Please enter String: ";
	getline(cin,input);
	
	convertCase(input);
	palindrome(input);

	return 0;
}