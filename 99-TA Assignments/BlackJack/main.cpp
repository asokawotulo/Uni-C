#include <iostream>
#include "classes/Blackjack.cpp"
using namespace std;

int main() {
	Blackjack game;
	bool over = false;
	int option;
	do {
		over = false;
		while(over == false){
			game.playGame();
			over = true;
		}
		cout << "[1] Play" << endl << "[2] End" << endl << "Input option: ";
		cin >> option;
	}while(option != 2);
	return 0;
}