#include <iostream>
#include "stack.h"

int main(){
	int runs, passes, last_player, i, j;
	bool front = true;
	char action;
	Stack<int> player_stack;

	std::cout << "Number of Runs: ";
	std::cin >> runs;

	for(i = 0; i < runs; i++){
		player_stack.clear();
		std::cout << "Number of Passes: ";
		std::cin >> passes;
		std::cout << "Last Player: ";
		std::cin >> last_player;
		for(j = 0; j < passes; j++){
			std::cout << "Front pass (F) / Back pass (B): ";
			std::cin >> action;
			switch(tolower(action)){
				case('f'):
					std::cout << "Pass to which player: ";
					std::cin >> last_player;
					player_stack.push(last_player);
					break;
				case('b'):
					if (front){
						last_player = player_stack.pop();
						front = false;
					}else{
						player_stack.push(last_player);
						front = true;
					}
					break;
			}
		}
	}
	std::cout << "Last Player: " << player_stack.pop();

	return 0;
}