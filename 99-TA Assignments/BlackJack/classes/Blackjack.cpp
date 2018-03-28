#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Blackjack.h"
using namespace std;

void Blackjack::resetCards(){
	// Place cards in full deck
	string suit[] = {"Diamond","Clover","Heart","Spade"};
	string card[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	for (int j = 0; j < 13; j++) {
		for (int i = 0; i < 4; i++) {
			full_deck.push_back(Card(suit[i],card[j]));
		}
	}
	// Reset card of player and dealer
	player_deck.clear();
	dealer_deck.clear();
	// Deal 1st Card to Player and Dealer
	addCard(&dealer_deck);
	addCard(&player_deck);
	// Deal 2nd Card to Player and Dealer
	addCard(&dealer_deck);
	addCard(&player_deck);
}
void Blackjack::addCard(vector<Card> *deck){
	srand(time(NULL));
	int card_index = rand() % full_deck.size();
	deck->push_back(full_deck.at(card_index));
	full_deck.erase(full_deck.begin() + card_index);
}
void Blackjack::viewHands(){
	cout << setw(13) << "Dealer's Hand" << "|" << "Player's Hand" << endl;
	cout << setw(13) << "-------------" << "|" << "-------------" << endl;
	for(int i = 0; i < (dealer_deck.size()>player_deck.size()?dealer_deck.size():player_deck.size()); i++){
		try {
			cout << setw(13) << dealer_deck.at(i).getCard();
		}
		catch (const std::out_of_range& e){
			cout << setw(14);
		}
		cout << "|";
		try {
			cout << setw(13) << player_deck.at(i).getCard() << endl;
		}
		catch (const std::out_of_range& e){
			cout << endl;
		}
	}
	cout << setw(13) << "-------------" << "|" << "-------------" << endl;
	cout << setw(13) << countValue(dealer_deck) << "|" << countValue(player_deck) << endl;
}
int Blackjack::playGame(){
	playerDone = false;
	dealerDone = false;
	resetCards();
	viewHands();
	if(countValue(dealer_deck) == 21){
		cout << "Dealer Wins!" << endl;
		return 0;
	}
	else if(countValue(player_deck) == 21){
		cout << "Player Wins!" << endl;
		return 0;
	}
	while(dealerDone == false || playerDone == false){
		if(countValue(player_deck) == 21 && countValue(dealer_deck) == 21){
			cout << "Push! Dealer and Player have Blackjack" << endl;
			return 0;
		}
		else if(countValue(dealer_deck) == 21 || countValue(player_deck) > 21){
			cout << "Dealer Wins" << endl;
			return 0;
		}
		else if(countValue(player_deck) == 21 || countValue(dealer_deck) > 21){
			cout << "Player Wins" << endl;
			return 0;
		}
		else if (playerDone == false){
			int playerOpt;
			cout << "[1] Hit" << endl << "[2] Stay" << endl << "Insert option: ";
			cin >> playerOpt;
			if(playerOpt == 1){
				addCard(&player_deck);
				viewHands();
				if(countValue(player_deck) > 21){
					cout << "Dealer Wins" << endl;
					return 0;
				}
			}
			else if(playerOpt == 2){
				playerDone = true;
			}
		}
		if(countValue(dealer_deck) < 17 && dealerDone == false){
			addCard(&dealer_deck);
			if(countValue(dealer_deck) > 21){
				viewHands();
				cout << "Player Wins" << endl;
				return 0;
			}
		}
		else if(countValue(dealer_deck) >= 17){
			dealerDone = true;
		}
	}
	return 0;
}
int Blackjack::countValue(vector<Card> deck){
	int count = 0;
	for(int i=0; i<deck.size(); i++){
		string card_num = deck.at(i).getCard().substr(0,2);
		if (card_num == "10"){
			count += 10;
		}
		else if (card_num == "J "){
			count += 11;
		}
		else if (card_num == "Q "){
			count += 12;
		}
		else if (card_num == "K "){
			count += 13;
		}
		else if (card_num == "A "){
			if(count > 10){
				count += 1;
			} else{
				count += 11;
			}
		}
		else {
			count += card_num[0]-'0';
		}
	}
	return count;
}
Blackjack::Blackjack(){
	playerDone = false;
	dealerDone = false;
}